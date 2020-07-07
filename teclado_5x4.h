/* 
 * File:   teclado_5x4.h
 * Author: Samuel Muñoz Aguilar
 * Comments:
 * Revision history:
 *      05/Julio/2020 - Creado
 */


#ifndef XC_TECLADO_5X4_H
#define	XC_TECLADO_5X4_H

#include <xc.h>


//
// Definiciones generales
//
#define   TECLA_0       0
#define   TECLA_1       1
#define   TECLA_2       2
#define   TECLA_3       3
#define   TECLA_4       4
#define   TECLA_5       5
#define   TECLA_6       6
#define   TECLA_7       7
#define   TECLA_8       8
#define   TECLA_9       9
#define   TECLA_DER     10
#define   TECLA_IZQ     11
#define   TECLA_ARRIBA  12
#define   TECLA_ABAJO   13
#define   TECLA_F1      14
#define   TECLA_F2      15
#define   TECLA_NUMERAL 16
#define   TECLA_AST     17
#define   TECLA_ESC     18
#define   TECLA_ENT     19
#define   TECLA_NULO    20



//
// Macros
//
#define apagarFilas()   TECLADO_F1_SetLow();    \
                        TECLADO_F2_SetLow();    \
                        TECLADO_F3_SetLow();    \
                        TECLADO_F4_SetLow();    \
                        TECLADO_F5_SetLow();

#define encenderFilas() TECLADO_F1_SetHigh();   \
                        TECLADO_F2_SetHigh();   \
                        TECLADO_F3_SetHigh();   \
                        TECLADO_F4_SetHigh();   \
                        TECLADO_F5_SetHigh();



//
// Prototipos de funciones
//

/**
 * Llamar para obtener la última tecla presionada por el usuario.
 * 
 * @param
 * @return El valor de la última tecla que se presionó.
 */
uint8_t TECLADO_leerTecla(void);

/**
 * Se llama cada vez que se presiona un botón del teclado matricial.
 * 
 * Se debe anclar junto con las interrupciones de cambio de los pines de
 * columnas.
 * 
 * @param
 * @return
 */
void TECLADO_interrupcion(void);

/**
 * Comprueba si cierta columna está en un valor lógico alto.
 * 
 * @param columna   Número de columna que se quiere probar.
 * @return Verdadero si dicha columna está en alto.
 */
static bool obtenerColumna(uint8_t columna);


#endif	/* XC_TECLADO_4X5_H */

