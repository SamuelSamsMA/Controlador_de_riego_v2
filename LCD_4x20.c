/*
 * File:   LCD_4x20.c
 * Author: Samuel Muñoz Aguilar
 *
 * Created on June 25, 2020, 1:42 AM
 */

#include "mcc_generated_files/mcc.h"
#include "LCD_4x20.h"


void LCD_iniciar(void) {
    // Puede ser de utilidad si es que no arranca bien al inicio
    __delay_ms(200);
    
    // Long. de datos de 8 bits
    LCD_enviarNibble(0x03);
    __delay_ms(2);
    
    // Function set. Comunicación de 4 bits
    LCD_enviarNibble(0x02);
    
    // -------------------------------------
	// Function set: "0 0 1 DL N F x x"
	// -------------------------------------
    // DL: 1 = Bus de 8 bits.
	//     0 = Bus de 4 bits.
    // N:  1 = Modo de pantalla de 2 líneas.
	//     0 = Modo de pantalla de 1 línea.
	// F:  1 = Formato de puntos de 5x11.
	//     0 = Formato de puntos de 5x8.
    LCD_comando(0b00101000);
    
    // Apagar pantalla
    LCD_comando(0b00001000);
    
    // Limpiar pantalla
    LCD_limpiarPantalla();
    
    // -------------------------------------
	// Entry mode set: "0 0 0 0 0 1 ID SH"
	// -------------------------------------
	// ID: 1 = Cursor se mueve a la derecha.
	//     0 = Cursor se mueve a la izquierda.
	// SH: 1 = Pantalla se recorre con la escritura de la DDRAM.
	//     0 = Pantalla no se recorre.
    LCD_comando(0b00000110);
    
    // -------------------------------------
	// Display ON/OFF control: "0 0 0 0 1 D C B"
	// -------------------------------------
	// D:  1 = Pantalla encendida.
	//     0 = Pantalla apagada.
	// C:  1 = Visualizar cursor.
    //     0 = Ocultar cursor.
	// B:  1 = Parpadeo activado.
	//     0 = Parpadeo desactivado.
    LCD_comando(0b00001100);
}


void LCD_enviarByte(char dato, bool comando)
{
    if(!comando)
        LCD_RS_SetHigh();
    
    // Envía el nibble más significativo
    char temp = dato >> 4;
    temp &= 0x0F;
    LCD_enviarNibble(temp);
    
    // Envía el nibble menos significativo
    dato &= 0x0F;
    LCD_enviarNibble(dato);
    
    LCD_RS_SetLow();
}


void LCD_enviarNibble(char nib)
{
    LATD = PORTD & 0xF0;
    LATD = PORTD ^ nib;
    
    LCD_EN_SetHigh();
    __delay_us(100);
    LCD_EN_SetLow();
    __delay_us(100);
}


/**
 End of File
*/