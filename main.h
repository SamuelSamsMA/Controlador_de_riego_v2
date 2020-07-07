/* 
 * File:   main.h
 * Author: Samuel Muñoz Aguilar
 * Comments: 
 * Revision history: creado: 05 de julio de 2020
 */

#ifndef XC_MAIN_H
#define	XC_MAIN_H

#include <xc.h>

//
// Definiciones y typedef
//


//
// Prototipos de funciones
//

/**
 * Se encarga del control de las salidas del controlador con base a la
 * configuración de usuario y el tiempo actual.
 * 
 * Esta función se debe llamar a través de la interrupción de un timer 
 * programado con un tiempo de 1 segundo.
 */
void rutinaDeControl(void);

#endif	/* XC_MAIN_H */

