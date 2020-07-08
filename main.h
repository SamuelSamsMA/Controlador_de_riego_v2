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
#define NUMERO_DE_ZONAS     3

typedef struct {
    uint8_t num_riegos;
    uint24_t tiempo_total_riego;
} INFO_RIEGO;

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


/**
 * Convierte los segundos del día en su equivalente de horas, minutos y segundos.
 * 
 * @param tseg  Segundos totales del día
 * @param buf   Vector para guardar los segundos, minutos y horas por separado.
 */
void segundos_a_hhmmss(uint24_t tseg, uint8_t* buf);

#endif	/* XC_MAIN_H */

