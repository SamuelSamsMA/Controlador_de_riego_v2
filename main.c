#include "mcc_generated_files/mcc.h"
#include "LCD_4x20.h"
#include "teclado_5x4.h"
#include "I2C_lib.h"
#include "menus.h"
#include "main.h"
#include "RTC_EEPROM.h"
#include <stdio.h>

//
// Variables globales
//
TIEMPO tiempo;
INFO_RIEGO reporteDiario[NUMERO_DE_ZONAS];
DATOS_PROG programas[NUMERO_DE_PROGRAMAS];
const uint16_t dir_contadores = 0x3F80;


//
// Función de entrada
//
void main(void)
{
#pragma warning push
#pragma warning disable 520
#pragma warning disable 2053
    // Initialize the device
    SYSTEM_Initialize();
#pragma warning pop
    
    LCD_iniciar();
    I2C_iniciar();
    
    TMR1_SetInterruptHandler(rutinaDeControl);
    IOCCF0_SetInterruptHandler(TECLADO_interrupcion);
    IOCCF1_SetInterruptHandler(TECLADO_interrupcion);
    IOCCF2_SetInterruptHandler(TECLADO_interrupcion);
    IOCCF3_SetInterruptHandler(TECLADO_interrupcion);
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    //TODO Configuración para DEBUG. BORRAR cuando no se use más
    tiempo.horas = 12;
    tiempo.minutos = 59;
    tiempo.segundos = 50;
    tiempo.fecha = 9;
    tiempo.mes = 7;
    tiempo.anio = 20;
    RTC_escribirHora(&tiempo);
    RTC_escribirFecha(&tiempo);
    programas[1].activo = 1;
    programas[1].duracion_riego = 20;
    programas[1].hr_inicio = 46800;
    programas[1].hr_final = 50400;
    programas[1].intervalo = 65;
    programas[1].max_riegos = 3;
    
    programas[6].activo = 1;
    programas[6].duracion_riego = 15;
    programas[6].hr_inicio = 46830;
    programas[6].hr_final = 50400;
    programas[6].intervalo = 65;
    programas[6].max_riegos = 10;
    
    uint16_t buf[WRITE_FLASH_BLOCKSIZE] = { 0 };
    FLASH_WriteBlock(dir_contadores, buf);
    
    // Arranca el watchdog y el timer 1
    WDTCONbits.SWDTEN = 1;
    T1CONbits.TMR1ON = 1;
    
    iniciarVariables();
    
    // Lleva la cuenta de la zona que se debe mostrar en la pantalla de inicio.
    uint8_t iZona = 1;
    
    while (1)
    {   // <editor-fold defaultstate="collapsed" desc="Pantalla de inicio">
        // Solo para medir el tiempo que tarda en ejecutar un ciclo while
        LED_SetHigh();
        CLRWDT();
        // Obtiene el valor de la última tecla que se presionó.
        uint8_t tecla = TECLADO_leerTecla();
        
        switch (tecla) {
        case TECLA_IZQ:     /* Decrementa el contador para mostrar la zona anterior */
            if (iZona != 1) iZona--;
            break;
            
        case TECLA_DER:     /* Incrementa el contador para mostrar la zona siguiente */
            if (iZona != NUMERO_DE_ZONAS) iZona++;
            break;
            
        case TECLA_F1:      /* Entra al menú principal */
            // Detiene al timer 1 y el watchdog
            // (deja de controlar las salidas mientras esté en el menú).
            WDTCONbits.SWDTEN = 0;
            T1CONbits.TMR1ON = 0;
            
            MenuPrincipal();
            
            // Arranca el watchdog y el timer 1
            WDTCONbits.SWDTEN = 1;
            T1CONbits.TMR1ON = 1;
            
            LCD_limpiarPantalla();
            break;
        }
        
        LCD_moverCursor(0, L1);
        printf(" %02d:%02d:%02d  %02d/%02d/%02d",
                tiempo.horas,
                tiempo.minutos,
                tiempo.segundos,
                tiempo.fecha,
                tiempo.mes,
                tiempo.anio);
        LCD_moverCursor(0, L2);
        printf("<      ZONA %d      >", iZona);
        LCD_moverCursor(0, L3);
        printf("NUM. RIEGOS %03d", reporteDiario[iZona - 1].num_riegos);
        
        uint8_t hhmmss[3];
        segundos_a_hhmmss(reporteDiario[iZona - 1].tiempo_total_riego, hhmmss);
        LCD_moverCursor(0, L4);
        printf("RIEGO TOTAL %02d:%02d:%02d", hhmmss[0], hhmmss[1], hhmmss[2]);
        
        LED_SetLow();
//      Una vez que se actualizó la pantalla de acuerdo a la tecla presionda,
//      se pone a dormir el procesador para ahorrar energía.
//      La interrupción de cada 1 segundo del timer o las interrupciones
//      del teclado despertarán al procesador y continuará su trabajo
//      con la pantalla.
        SLEEP();
        
        // </editor-fold>
    } /* while (1) */
} /* void main(void) */


void rutinaDeControl(void)
{
    // Actualiza el tiempo actual desde el RTC
    RTC_leerHora(&tiempo);
    RTC_leerFecha(&tiempo);
    uint8_t temp[] = { tiempo.horas, tiempo.minutos, tiempo.segundos };
    uint24_t hr_actual = hhmmss_a_segundos(temp);
    
    // Indica el # de programa con riego en ejecución. Cero si ningún riego
    // se está ejecutando (sólo puede haber un riego activo a la vez).
    static uint8_t progRiegoActivo = 0;
    
    if (progRiegoActivo)
    {   // Hay un riego en ejecución y se tiene que detener para que pueda entrar otro
        bool riego_en_marcha = controlarApagado(&programas[progRiegoActivo - 1],
                                                hr_actual);
        if (!riego_en_marcha)
        {
            // Incrementa el contador de riegos por programa
            uint16_t leido = FLASH_ReadWord(dir_contadores + progRiegoActivo - 1);
            uint16_t buf[ERASE_FLASH_BLOCKSIZE];
            FLASH_WriteWord((uint16_t)dir_contadores + progRiegoActivo - 1,
                            buf,
                            leido + 1);
            
            actualizarContadoresZona(progRiegoActivo);
            progRiegoActivo = 0;
        }
    }
    else
    {   // No hay riego en ejecución y puede entrar uno nuevo
        uint8_t iProg = 0;
        while (iProg < PROGRAMAS_PARA_ZONA)
        {
            if (programas[iProg].activo)
            {   // Si el prográma i-ésimo está activo, verifica si es tiempo de que entre
                if (hr_actual >= programas[iProg].hr_inicio &&
                    hr_actual <= programas[iProg].hr_final)
                {
                    uint8_t leido = (uint8_t)FLASH_ReadWord(dir_contadores + iProg);
                    
                    bool riego_en_marcha = controlarEncendido(&programas[iProg],
                                                              hr_actual,
                                                              leido);
                    if (riego_en_marcha) {
                        progRiegoActivo = iProg + 1;
                        break;
                    }
                    else {
                        iProg++;
                        continue;
                    }
                }
                else {
                    iProg++;
                    continue;
                }
            }   /* if (programas[iProg].activo) */
            else {
                iProg++;
                continue;
            }
        }   /* while (iProg < NUMERO_DE_PROGRAMAS - PROGRAMAS_PARA_POZO) */
    }   /* else */
    
    //TODO Agregar código que controle al pozo
    
    
    if (hr_actual == 0)
    {   // Reinicia los contadores generales de riego por zona
        uint16_t buf[ERASE_FLASH_BLOCKSIZE];
        for (uint8_t i = 0; i < PROGRAMAS_PARA_ZONA; i++)
            FLASH_WriteWord(dir_contadores + i, buf, 0);
    }
    
}   /* void rutinaDeControl(void) */


bool controlarEncendido(DATOS_PROG* p, uint24_t hr_actual, uint8_t contador_riegos)
{
    // Verifica que la configuración de usuario sea coherente
    bool coherencia = p->intervalo > 1 &&
                      p->intervalo > p->duracion_riego &&
                      p->hr_final > (p->hr_inicio + 2);
    
    if (coherencia)
    {
        uint8_t num_riegos = (uint8_t)((p->hr_final - p->hr_inicio) / p->intervalo) + 1;
        uint8_t i = 0;

        while(i < num_riegos)
        {
            uint24_t hr_arranque = p->hr_inicio + (i * p->intervalo);
            if (hr_actual == hr_arranque)
            {
                if (contador_riegos < p->max_riegos)
                {
                    encenderBomba();
                    p->encender_valvula();
                    p->hr_arranque = hr_actual;
                    return true;
                }
                else
                    // Se han alcanzado el máximo de riegos y ya no se puede regar más.
                    break;
            }
            else if (hr_actual > hr_arranque)
                i++;
            else
                break;

        }   /* while(i < num_riegos) */
        return false;
    }
    else
        return false;
}   /* char controlarEncendido(DATOS_PROG*, uint24_t) */


bool controlarApagado(DATOS_PROG* p, uint24_t hr_actual)
{
    uint24_t hr_paro = p->hr_arranque + p->duracion_riego;
    
    if (hr_paro == hr_actual)
    {
        apagarBomba();
        p->apagar_valvula();
        return false;
    }
    else
        return true;
}


void iniciarVariables(void)
{
    // Lee el tiempo actual desde el RTC
    RTC_leerHora(&tiempo);
    RTC_leerFecha(&tiempo);
    
    // Reinicia la cuenta de los riegos por dia de cada zona
    for (uint8_t i = NUMERO_DE_ZONAS; i != 0; i--) {
        reporteDiario[i - 1].num_riegos = 0;
        reporteDiario[i - 1].tiempo_total_riego = 0;
    }
    
    for (uint8_t i = 0; i < 5; i++) {
        programas[i].encender_valvula = encenderZona1;
        programas[i].apagar_valvula = apagarZona1;
        programas[i].hr_arranque = 0;
    }
    
    for (uint8_t i = 5; i < 10; i++) {
        programas[i].encender_valvula = encenderZona2;
        programas[i].apagar_valvula = apagarZona2;
        programas[i].hr_arranque = 0;
    }
    
    for (uint8_t i = 10; i < 15; i++) {
        programas[i].encender_valvula = encenderZona3;
        programas[i].apagar_valvula = apagarZona3;
        programas[i].hr_arranque = 0;
    }
}


void actualizarContadoresZona(uint8_t progRiegoActivo)
{
    uint8_t temp8;
    uint24_t temp24;
    
    if (progRiegoActivo >= 1 && progRiegoActivo <= 5)
    {
        temp8 = (uint8_t)FLASH_ReadWord(dir_contadores + 0) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 1) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 2) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 3) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 4);
        reporteDiario[0].num_riegos = temp8;

        temp24 = (FLASH_ReadWord(dir_contadores + 0) * programas[0].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 1) * programas[1].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 2) * programas[2].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 3) * programas[3].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 4) * programas[4].duracion_riego);
        reporteDiario[0].tiempo_total_riego = temp24;
    }
    else if (progRiegoActivo >= 6 && progRiegoActivo <= 10)
    {
        temp8 = (uint8_t)FLASH_ReadWord(dir_contadores + 5) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 6) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 7) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 8) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 9);
        reporteDiario[1].num_riegos = temp8;

        temp24 = (FLASH_ReadWord(dir_contadores + 5) * programas[5].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 6) * programas[6].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 7) * programas[7].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 8) * programas[8].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 9) * programas[9].duracion_riego);
        reporteDiario[1].tiempo_total_riego = temp24;
    }
    else if (progRiegoActivo >= 11 && progRiegoActivo <= 15)
    {
        temp8 = (uint8_t)FLASH_ReadWord(dir_contadores + 10) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 11) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 12) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 13) +
                (uint8_t)FLASH_ReadWord(dir_contadores + 14);
        reporteDiario[2].num_riegos = temp8;

        temp24 = (FLASH_ReadWord(dir_contadores + 10) * programas[10].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 11) * programas[11].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 12) * programas[12].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 13) * programas[13].duracion_riego) +
                 (FLASH_ReadWord(dir_contadores + 14) * programas[14].duracion_riego);
        reporteDiario[2].tiempo_total_riego = temp24;
    }
}   /* void actualizarContadoresZona(uint8_t) */


void segundos_a_hhmmss(uint24_t tseg, uint8_t* buf)
{
    // Calcula las horas
    *(buf + 0) = (uint8_t)((tseg / 0x000E10) & 0x0000FF);
    tseg %= 0x000E10;
    
    // Calcula los minutos
    *(buf + 1) = (uint8_t)((tseg / 0x00003C) & 0x0000FF);
    tseg %= 0x00003C;
    
    // Calcula los segundos
    *(buf + 2) = (uint8_t)(tseg & 0x0000FF);
}


uint24_t hhmmss_a_segundos(uint8_t* buf)
{
    uint24_t segs = 0;
    
    // Convierte horas a segundos
    segs = (uint24_t)(*buf) * 0x000E10;         // hrs * 60 * 60
    
    // Convierte minutos a segundos y acumula el resultado
    segs += (uint24_t)(*(buf + 1)) * 0x00003C;  // min * 60
    
    // Acumula los segundos al resultado
    segs += (uint24_t)(*(buf + 2));
    
    return segs;
}


void encenderBomba(void) { LATAbits.LATA1 = 1; }
void apagarBomba(void) { LATAbits.LATA1 = 0; }

void encenderZona1(void) { LATAbits.LATA2 = 1; }
void apagarZona1(void) { LATAbits.LATA2 = 0; }

void encenderZona2(void) { LATAbits.LATA3 = 1; }
void apagarZona2(void) { LATAbits.LATA3 = 0; }

void encenderZona3(void) { LATAbits.LATA4 = 1; }
void apagarZona3(void) { LATAbits.LATA4 = 0; }

void encenderPozo(void) { LATAbits.LATA5 = 1; }
void apagarPozo(void) { LATAbits.LATA5 = 0; }

// Ésta función es necesaria para el funcionamiento de printf y se ha
// sobreescrito para que se impriman los caracteres en la pantalla LCD.
void putch(char byte)
{
    LCD_caracter(byte);
}

/**
 End of File
*/