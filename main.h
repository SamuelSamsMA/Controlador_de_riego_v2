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
#define PROGRAMAS_POR_ZONA  5
#define PROGRAMAS_PARA_POZO 1
#define PROGRAMAS_PARA_ZONA (NUMERO_DE_ZONAS * PROGRAMAS_POR_ZONA)
#define NUMERO_DE_PROGRAMAS ((NUMERO_DE_ZONAS * PROGRAMAS_POR_ZONA) + \
                            PROGRAMAS_PARA_POZO)

typedef struct {
    uint8_t num_riegos;
    uint24_t tiempo_total_riego;
} INFO_RIEGO;

typedef struct {
    uint8_t     activo;
    uint8_t     zona;
    uint8_t     max_riegos;
    uint24_t    hr_inicio;
    uint24_t    hr_final;
    uint24_t    intervalo;
    uint24_t    duracion_riego;
    
    uint24_t    hr_arranque;
    void (*encender_valvula)(void);
    void (*apagar_valvula)(void);
} DATOS_PROG;

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
 * Retoma la configuración de usuario y las condiciones de tiempo actuales
 * para activar o no las salidas del programa en cuestion.
 * 
 * @param p                 Puntero a la estructura con los datos del programa
 *                          actual.
 * @param hr_actual         La hora actual del sistema en segundos.
 * @param contador_riegos   Variable no-volatil que lleva la cuenta de riegos
 *                          por programa en un día.
 * @return                  Verdadero si es que se logró arrancar un riego.
 */
bool controlarEncendido(DATOS_PROG* p, uint24_t hr_actual, uint8_t contador_riegos);


/**
 * Calcula la hora a la que se debe apagar el riego activo y la compara con la hora
 * actual para tomar la desición.
 * 
 * @param p                 Puntero a la estructura con los datos del programa
 *                          actual.
 * @param hr_actual         La hora actual del sistema en segundos.
 * @return                  Falso si es que se logró apagar el riego.
 */
bool controlarApagado(DATOS_PROG* p, uint24_t hr_actual);


void iniciarVariables(void);


/**
 * Actualiza los contadores de riegos totales y tiempo total de riego por zona.
 * 
 * Cada zona cuenta con 5 programas determinados, cuando uno de ellos termina un
 * nuevo riego es necesario llamar a esta función para que se actualize la cuenta
 * de toda la zona.
 * 
 * @param progRiegoActivo   # de programa que terminó un nuevo riego (valores 1, 2, 3, ... , n).
 */
void actualizarContadoresZona(uint8_t progRiegoActivo);

/**
 * Convierte los segundos del día en su equivalente de horas, minutos y segundos.
 * 
 * @param tseg  Segundos totales del día
 * @param buf   Vector para guardar los segundos, minutos y horas por separado.
 */
void segundos_a_hhmmss(uint24_t tseg, uint8_t* buf);


/**
 * Convierte la hora en formato hh:mm:ss en segundos totales.
 * 
 * @param buf   Vector con los tres valores de hr, min y seg
 * @return      La hora en segundos totales
 */
uint24_t hhmmss_a_segundos(uint8_t* buf);


void encenderBomba(void);
void apagarBomba(void);

void encenderZona1(void);
void apagarZona1(void);

void encenderZona2(void);
void apagarZona2(void);

void encenderZona3(void);
void apagarZona3(void);

void encenderPozo(void);
void apagarPozo(void);

#endif	/* XC_MAIN_H */

