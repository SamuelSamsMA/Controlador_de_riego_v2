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
#define RTC_DS3231MZ_DIR        0x00

#define EEPROM_TAMANO_PAGINA    16



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

#endif	/* XC_RTC_EEPROM_H */