#include "mcc_generated_files/mcc.h"
#include "LCD_4x20.h"
#include "teclado_5x4.h"
#include "I2C_lib.h"
#include "main.h"
#include "RTC_EEPROM.h"
#include <stdio.h>


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
    
    /*
     Primero se guardan 4 cadenas de texto en las páginas 1, 15, 30 y 31
     de la memoria EEPROM 24C04
     */
    
    char cadena1[16] = "Ejemplo";
    char cadena2[16] = "creado por";
    char cadena3[16] = "Samuel Munoz";
    char cadena4[16] = "el 07/07/2020..";
    
    EEPROM_escribirPagina(1, cadena1);
    EEPROM_escribirPagina(15, cadena2);
    EEPROM_escribirPagina(30, cadena3);
    EEPROM_escribirPagina(31, cadena4);
    
    char bufer[16] = {0};
    
    while (1)
    {   // <editor-fold defaultstate="collapsed" desc="Ciclo infinito">
        CLRWDT();
        uint8 tecla = TECLADO_leerTecla();
        
        /*
         * Cada vez que el usuario presiona una de las siguientes teclas, el
         * microcontrolador solicita el contenido de una página de la EEPROM
         * e imprime los datos en la pantalla LCD.
         * 
         * Éste programa de ejemplo es para probar el buen funcionamiento del
         * módulo I2C maestro y la comunicación con la Memoria EEPROM 24C04,
         * los cuales son de vital importancia para el desarrollo del
         * controlador de riego.
         */
        switch (tecla)
        {
        case TECLA_1:
            LCD_limpiarPantalla();
            EEPROM_leerPagina(1, bufer);
            printf("%s", bufer);
            break;
            
        case TECLA_4:
            LCD_limpiarPantalla();
            EEPROM_leerPagina(15, bufer);
            printf("%s", bufer);
            break;
            
        case TECLA_7:
            LCD_limpiarPantalla();
            EEPROM_leerPagina(30, bufer);
            printf("%s", bufer);
            break;
            
        case TECLA_IZQ:
            LCD_limpiarPantalla();
            EEPROM_leerPagina(31, bufer);
            printf("%s", bufer);
            break;
        }
        
        /*
         Una vez que se actualizó la pantalla de acuerdo a la tecla presionda,
         se pone a dormir el procesador para ahorrar energía.
         La interrupción de cada 1 segundo del timer o las interrupciones
         del teclado, despertarán al procesador y continuara su trabajo
         con la pantalla.
         */
        SLEEP();
        // </editor-fold>
    } /* while (1) */
} /* void main(void) */


void rutinaDeControl(void)
{
    // Aquí se agregará el código que administre las salidas del controlador

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