/*
 * File:   RTC_&_EEPROM.c
 * Author: Samuel Muñoz Aguilar
 *
 * Created on July 06, 2020, 11:08 PM
 */

#include "mcc_generated_files/mcc.h"
#include "I2C_lib.h"
#include "RTC_EEPROM.h"


void EEPROM_escribirPagina(uint8_t nPagina, char* bufer)
{
    // Calcula la dirección inicial de 9 bits de la página.
    unsigned short dirReg = 16u * nPagina;
    
    // Evalúa al noveno bit de 'dirReg' y lo copia en el segundo bit del
    // byte de dirección del dispositivo
    char dirEEPROM;
    
    if (dirReg & 0x0100)
        dirEEPROM = EEPROM_24C04_DIR | 0x02;
    else
        dirEEPROM = EEPROM_24C04_DIR;
    
    // Envía los 16 bytes del 'bufer' al dispositivo EEPROM
    I2C_escribirNBytes(dirEEPROM, dirReg & 0x00FF, bufer, EEPROM_TAMANO_PAGINA);
    
    // Tiempo máximo de espera para que se inicie una nueva escritura
    __delay_ms(5);
}


void EEPROM_leerPagina(uint8_t nPagina, char* bufer)
{
    // Calcula la dirección inicial de 9 bits de la página.
    unsigned short dirReg = 16u * nPagina;
    
    // Evalúa al noveno bit de 'dirReg' y lo copia en el segundo bit del
    // byte de dirección del dispositivo
    char dirEEPROM;
    
    if (dirReg & 0x0100)
        dirEEPROM = EEPROM_24C04_DIR | 0x02;
    else
        dirEEPROM = EEPROM_24C04_DIR;
    
    // Recibe los 16 bytes de la página y los guarda en 'bufer'
    I2C_leerNBytes(dirEEPROM, dirReg & 0x00FF, bufer, EEPROM_TAMANO_PAGINA);
}

/**
 End of File
*/