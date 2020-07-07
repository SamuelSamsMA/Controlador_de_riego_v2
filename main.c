#include "mcc_generated_files/mcc.h"
#include "LCD_4x20.h"
#include "teclado_5x4.h"
#include "I2C_lib.h"
#include "main.h"
#include "RTC_EEPROM.h"
#include <stdio.h>

//
// Variables globales
//
TIEMPO tiempo;


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
    
    while (1)
    {   // <editor-fold defaultstate="collapsed" desc="Ciclo infinito">
        // Solo para medir el tiempo que tarda en ejecutar un ciclo while
        LED_SetHigh();
        CLRWDT();
        uint8_t tecla = TECLADO_leerTecla();
        
        // Si se presiona la tecla F1 se reinicia la cuenta de tiempo del RTC.
        if (tecla == TECLA_F1)
        {
            tiempo.segundos = 0;
            tiempo.minutos  = 0;
            tiempo.horas    = 0;
            tiempo.fecha    = 1;
            tiempo.mes      = 1;
            tiempo.anio     = 0;
            RTC_escribirHora(&tiempo);
            RTC_escribirFecha(&tiempo);
        }
        
        LCD_limpiarPantalla();
        printf(" %02d:%02d:%02d  %02d/%02d/%02d",
                tiempo.horas,
                tiempo.minutos,
                tiempo.segundos,
                tiempo.fecha,
                tiempo.mes,
                tiempo.anio);
        
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
    
} /* void rutinaDeControl(void) */


// Ésta función es necesaria para el funcionamiento de printf y se ha
// sobreescrito para que se impriman los caracteres en la pantalla LCD.
void putch(char byte)
{
    LCD_caracter(byte);
}

/**
 End of File
*/