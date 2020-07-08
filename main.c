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
    
    // Arranca el watchdog y el timer 1
    WDTCONbits.SWDTEN = 1;
    T1CONbits.TMR1ON = 1;
    
    // Lee el tiempo actual desde el RTC
    RTC_leerHora(&tiempo);
    RTC_leerFecha(&tiempo);
    
    // Reinicia la cuenta de los riegos por dia de cada zona
    for (uint8_t i = NUMERO_DE_ZONAS; i != 0; i--) {
        reporteDiario[i - 1].num_riegos = 0;
        reporteDiario[i - 1].tiempo_total_riego = 0;
    }
    
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
    
    reporteDiario[0].tiempo_total_riego += 0x000384;    // Suma 15 mins y 1 s
    reporteDiario[1].tiempo_total_riego += 0x00003C;    // Suma 1 mins y 0 s
    reporteDiario[2].tiempo_total_riego += 0x000001;    // Suma 0 mins y 1 s
    
} /* void rutinaDeControl(void) */


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


// Ésta función es necesaria para el funcionamiento de printf y se ha
// sobreescrito para que se impriman los caracteres en la pantalla LCD.
void putch(char byte)
{
    LCD_caracter(byte);
}

/**
 End of File
*/