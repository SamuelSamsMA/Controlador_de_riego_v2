#include "mcc_generated_files/mcc.h"
#include "LCD_4x20.h"
#include "teclado_5x4.h"
#include "main.h"
#include <stdio.h>


//
// Función de entrada
//
void main(void) {
    // Initialize the device
    SYSTEM_Initialize();
    LCD_iniciar();
    
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
    
    // Enciende el parpadeo del cursor de la pantalla
    LCD_comando(LCD_cursorApaParpEnc);
    
    // Contadores de la posición del cursor con base inicial en 1
    uint8 fila_i = 1, col_i = 1, enters = 0;
    
    while (1)
    { // <editor-fold defaultstate="collapsed" desc="Ciclo infinito">
        uint8 tecla = TECLADO_leerTecla();
        
        CLRWDT();
        
        switch (tecla) {
        
            // Sube al cursor una fila, conservando la columna
        case TECLA_ARRIBA:
            if (fila_i > 1) {
                fila_i--;
                switch (fila_i) {
                case 1: LCD_moverCursor(col_i - 1, L1); break;
                case 2: LCD_moverCursor(col_i - 1, L2); break;
                case 3: LCD_moverCursor(col_i - 1, L3); break;
                case 4: LCD_moverCursor(col_i - 1, L4); break;
                }
            }
            break;
            
            // Baja al cursor una fila, conservando la columna
        case TECLA_ABAJO:
            if (fila_i < 4) {
                fila_i++;
                switch (fila_i) {
                case 1: LCD_moverCursor(col_i - 1, L1); break;
                case 2: LCD_moverCursor(col_i - 1, L2); break;
                case 3: LCD_moverCursor(col_i - 1, L3); break;
                case 4: LCD_moverCursor(col_i - 1, L4); break;
                }
            }
            break;
            
            // Imprime el número de Enters que se han presionado.
            // El contador se reinicia al llegar a 10.
        case TECLA_ENT:
            printf("%d", ++enters);
            if (enters == 9)
                enters = 0;
            col_i++;
            break;
            
            // Mueve al cursor un espacio a la derecha sobre la misma fila
        case TECLA_DER:
            if (col_i < 20) {
                col_i++;
                switch (fila_i) {
                case 1: LCD_moverCursor(col_i - 1, L1); break;
                case 2: LCD_moverCursor(col_i - 1, L2); break;
                case 3: LCD_moverCursor(col_i - 1, L3); break;
                case 4: LCD_moverCursor(col_i - 1, L4); break;
                }
            }
            break;
            
            // Mueve al cursor un espacio a la izquierda sobre la misma fila
        case TECLA_IZQ:
            if (col_i > 1) {
                col_i--;
                switch (fila_i) {
                case 1: LCD_moverCursor(col_i - 1, L1); break;
                case 2: LCD_moverCursor(col_i - 1, L2); break;
                case 3: LCD_moverCursor(col_i - 1, L3); break;
                case 4: LCD_moverCursor(col_i - 1, L4); break;
                }
            }
            break;
            
            // Limpia toda la pantalla y regresa el cursor a la pos. 1,1
        case TECLA_ESC:
            LCD_limpiarPantalla();
            fila_i = 1;
            col_i = 1;
            break;
            
            // Imprime el número de tecla en la pos. actual del cursor
        case TECLA_0: case TECLA_1: case TECLA_2: case TECLA_3: case TECLA_4:
        case TECLA_5: case TECLA_6: case TECLA_7: case TECLA_8: case TECLA_9:
            LCD_caracter(tecla + 0x30);
            col_i++;
            break;
            
            // Imprime el símbolo numeral en la pos. actual del cursor
        case TECLA_NUMERAL:
            LCD_caracter('#');
            col_i++;
            break;
            
            // Imprime el símbolo asterisco en la pos. actual del cursor
        case TECLA_AST:
            LCD_caracter('*');
            col_i++;
            break;
            
            // Lleva al cursor a la columna 1 de la fila actual
        case TECLA_F1:
            col_i = 1;
            switch (fila_i) {
                case 1: LCD_moverCursor(col_i - 1, L1); break;
                case 2: LCD_moverCursor(col_i - 1, L2); break;
                case 3: LCD_moverCursor(col_i - 1, L3); break;
                case 4: LCD_moverCursor(col_i - 1, L4); break;
                }
            break;
            
            // Lleva al cursor a la columna 20 de la fila actual
        case TECLA_F2:
            col_i = 20;
            switch (fila_i) {
                case 1: LCD_moverCursor(col_i - 1, L1); break;
                case 2: LCD_moverCursor(col_i - 1, L2); break;
                case 3: LCD_moverCursor(col_i - 1, L3); break;
                case 4: LCD_moverCursor(col_i - 1, L4); break;
                }
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
    }
}


void rutinaDeControl(void) {
    // Aquí se agregará el código que administre las salidas del controlador
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