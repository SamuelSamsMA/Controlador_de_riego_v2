/* 
 * File:   RTC_&_EEPROM.h
 * Author: Samuel Muñoz Aguilar
 * Comments:
 * Revision history: 
 */

#ifndef XC_RTC_EEPROM_H
#define	XC_RTC_EEPROM_H

#include <xc.h>


//
// Definiciones generales
//
#define EEPROM_24C04_DIR        0xA0
#define RTC_DS3231MZ_DIR        0xD0

#define EEPROM_TAMANO_PAGINA    16

typedef struct {
    uint8_t segundos;
    uint8_t minutos;
    uint8_t horas;
    uint8_t fecha;
    uint8_t mes;
    uint8_t anio;
} TIEMPO;


//
// Prototipos de funciones
//

/**
 * Lee una página completa de 16 bytes de la memoria EEPROM.
 * 
 * @param nPagina   Número de página que se quiere leer [0, 31]
 * @param bufer     Bufer de al menos 16 bytes de tamaño para guardar los datos.
 */
void EEPROM_leerPagina(uint8_t nPagina, char* bufer);


/**
 * Escribe una página completa de 16 bytes en la memoria EEPROM.
 * 
 * @param nPagina   Número de página que se quiere escribir [0, 31]
 * @param bufer     Contenedor de los 16 bytes a escribir.
 */
void EEPROM_escribirPagina(uint8_t nPagina, char* bufer);


/**
 * Lee la hora actual (hrs, mins y segs) del RTC.
 * 
 * @param tiempo    Estructura para guardar los datos leidos del RTC.
 */
void RTC_leerHora(TIEMPO* tiempo);


/**
 * Modifica la hora actual (hrs, mins y segs) del RTC.
 * 
 * @param tiempo    Estructura con los nuevos valores de la hora.
 */
void RTC_escribirHora(TIEMPO* tiempo);


/**
 * Lee la fecha actual (día, mes y año) del RTC.
 * 
 * @param tiempo    Estructura para guardar los datos leidos del RTC.
 */
void RTC_leerFecha(TIEMPO* tiempo);


/**
 * Modifica la fecha actual (día, mes y año) del RTC.
 * 
 * @param tiempo    Estructura con los nuevos valores de la fecha.
 */
void RTC_escribirFecha(TIEMPO* tiempo);


static uint8_t bcd_a_binario(uint8_t num);


static uint8_t binario_a_bcd(uint8_t num);

#endif	/* XC_RTC_EEPROM_H */