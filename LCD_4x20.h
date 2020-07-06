/* 
 * File:   LCD_4x20.h
 * Author: Samuel Muñoz Aguilar
 * Comments:
 * Revision history:
 *      25/Junio/2020 - Creado
 *      05/Julio/2020 - Se agregó el macro LCD_moverCursor(x,y)
 */

#ifndef XC_LCD_4X20_H
#define	XC_LCD_4X20_H

#include <xc.h>


//
// Comandos para la LCD
//

#define LCD_cursorEncParpEnc    0x0F
#define LCD_cursorEncParpApa    0x0E
#define LCD_cursorApaParpEnc    0x0D
#define LCD_cursorApaParpApa    0x0C
#define LCD_displayEnc          0x0C
#define LCD_displayApa          0x08
#define LCD_moverDisplayDer     0x1C
#define LCD_moverDisplayIzq     0x18
#define LCD_moverCursorDer      0x14
#define LCD_moverCursorIzq      0x10
#define LCD_limpiarDisplay      0x01    // Usar el macro limpiarPantalla()



//
// Macros con funciones predeterminadas para la LCD
//

#define LCD_caracter(x)         LCD_enviarByte(x,false)
#define LCD_comando(x)          LCD_enviarByte(x,true)

#define L1  0x00        // Dirección en DDRAM de la primera pos. de la linea 1
#define L2  0x40        // Dirección en DDRAM de la primera pos. de la linea 2
#define L3  0x14        // Dirección en DDRAM de la primera pos. de la linea 3
#define L4  0x54        // Dirección en DDRAM de la primera pos. de la linea 4

/**
Calcula el valor de la DDRAM de acuerdo a los valores X,Y
que indican el espacio horizontal X y la linea Y deseados en la pantalla.
 */
#define LCD_moverCursor(x,y)    LCD_comando(0x80 | (y + x))

/**
Limpia toda la pantalla escribiendo 0x20 (espacio) en todas las localidades
de la DDRAM y escribe 0x00 en la dirección de la DDRAM.
 */
#define LCD_limpiarPantalla()   LCD_comando(LCD_limpiarDisplay);    \
                                __delay_ms(2)



//
// Prototipos de funciones
//

/**
 * Inicia la configuración de la pantalla LCD con el modo de comunicación
 * de 4 bits.
 * 
 * Se debe llamar a ésta función antes que cualquier otra de la LCD.
 * 
 * @param
 * @return
 */
void LCD_iniciar(void);


/**
 * Envía un byte a la pantalla LCD con la comunicación de 4 bits
 * Se recomienda usar los macros 'LCD_caracter(x)' o 'LCD_comando'
 * para una mayor claridad en el código.
 * 
 * @param dato      Byte que se desea enviar
 * @param comando   'true' si es un comando, 'false' si es un caracter
 * @return
 */
void LCD_enviarByte(char dato, bool comando);


/**
 * Envía un nibble a través de los pines de comunicación.
 * 
 * Ésta función es necesaria para la librería LCD y no se recomienda
 * su uso fuera de ésta.
 * 
 * @param nib    Toma al nibble menos significativo para enviar
 * @return
 */
void LCD_enviarNibble(char nib);


#endif	/* XC_LCD_4X20_H */

