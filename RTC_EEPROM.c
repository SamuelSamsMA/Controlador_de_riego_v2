/*
 * File:   RTC_&_EEPROM.c
 * Author: Samuel Mu�oz Aguilar
 *
 * Created on July 06, 2020, 11:08 PM
 */

#include "mcc_generated_files/mcc.h"
#include "I2C_lib.h"
#include "RTC_EEPROM.h"


void EEPROM_escribirPagina(uint8_t nPagina, char* bufer)
{
    // Calcula la direcci�n inicial de 9 bits de la p�gina.
    unsigned short dirReg = 16u * nPagina;
    
    // Eval�a al noveno bit de 'dirReg' y lo copia en el segundo bit del
    // byte de direcci�n del dispositivo
    char dirEEPROM;
    
    if (dirReg & 0x0100)
        dirEEPROM = EEPROM_24C04_DIR | 0x02;
    else
        dirEEPROM = EEPROM_24C04_DIR;
    
    // Env�a los 16 bytes del 'bufer' al dispositivo EEPROM
    I2C_escribirNBytes(dirEEPROM, dirReg & 0x00FF, bufer, EEPROM_TAMANO_PAGINA);
    
    // Tiempo m�ximo de espera para que se inicie una nueva escritura
    __delay_ms(5);
}


void EEPROM_leerPagina(uint8_t nPagina, char* bufer)
{
    // Calcula la direcci�n inicial de 9 bits de la p�gina.
    unsigned short dirReg = 16u * nPagina;
    
    // Eval�a al noveno bit de 'dirReg' y lo copia en el segundo bit del
    // byte de direcci�n del dispositivo
    char dirEEPROM;
    
    if (dirReg & 0x0100)
        dirEEPROM = EEPROM_24C04_DIR | 0x02;
    else
        dirEEPROM = EEPROM_24C04_DIR;
    
    // Recibe los 16 bytes de la p�gina y los guarda en 'bufer'
    I2C_leerNBytes(dirEEPROM, dirReg & 0x00FF, bufer, EEPROM_TAMANO_PAGINA);
}


void RTC_leerHora(TIEMPO* tiempo)
{
    uint8_t bufer[3];
    I2C_leerNBytes(RTC_DS3231MZ_DIR, 0, (char*)bufer, 3);
    
    tiempo->segundos = bcd_a_binario(bufer[0]);
    tiempo->minutos  = bcd_a_binario(bufer[1]);
    tiempo->horas    = bcd_a_binario(bufer[2]);
}


void RTC_escribirHora(TIEMPO* tiempo)
{
    uint8_t bufer[3];
    bufer[0] = binario_a_bcd(tiempo->segundos);
    bufer[1] = binario_a_bcd(tiempo->minutos);
    bufer[2] = binario_a_bcd(tiempo->horas);
    
    I2C_escribirNBytes(RTC_DS3231MZ_DIR, 0, (char*)bufer, 3);
}


void RTC_leerFecha(TIEMPO* tiempo)
{
    uint8_t bufer[3];
    I2C_leerNBytes(RTC_DS3231MZ_DIR, 4, (char*)bufer, 3);
    
    tiempo->fecha = bcd_a_binario(bufer[0]);
    tiempo->mes   = bcd_a_binario(bufer[1]);
    tiempo->anio  = bcd_a_binario(bufer[2]);
}


void RTC_escribirFecha(TIEMPO* tiempo)
{
    uint8_t bufer[3];
    bufer[0] = binario_a_bcd(tiempo->fecha);
    bufer[1] = binario_a_bcd(tiempo->mes);
    bufer[2] = binario_a_bcd(tiempo->anio);
    
    I2C_escribirNBytes(RTC_DS3231MZ_DIR, 4, (char*)bufer, 3);
}


static uint8_t bcd_a_binario(uint8_t num)
{
  return ((num >> 4) * 10 + (num & 0x0F));
}


static uint8_t binario_a_bcd(uint8_t num)
{
  return (((num / 10) << 4) + (num % 10));
}

/**
 End of File
*/