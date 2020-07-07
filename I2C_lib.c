/*
 * File:   I2C_lib.c
 * Author: Samuel Muñoz Aguilar
 *
 * Created on July 06, 2020, 1:08 PM
 */

#include "mcc_generated_files/mcc.h"
#include "I2C_lib.h"


void I2C_iniciar(void)
{
    if(!SSP1CON1bits.SSPEN)
    {
        SSP1STAT = 0x80;
        SSP1CON1 = 0x08;
        SSP1CON2 = 0x00;
        SSP1ADD = 0x27;
        SSP1CON1bits.SSPEN = 1;
    }
} /* void I2C_Init(void) */


void I2C_escribirByte(char dirEsclavo, char dirRegistro, char dato)
{
    // Inicia una secuencia de escritura
    I2C_Start();
    // Dirección del esclavo
    I2C_Write(dirEsclavo & 0xFE);
    // Dirección del registro que se quiere escribir
    I2C_Write(dirRegistro);
    // Envía el byte de datos
    I2C_Write(dato);
    // Fin de la secuencia de escritura
    I2C_Stop();
    
} /* void I2C_escribirByte(char, char, char) */


char I2C_leerByte(char dirEsclavo, char dirRegistro)
{
    char dato = 0;
    
    // Inicia una secuencia de escritura
    I2C_Start();
    // Dirección del esclavo
    I2C_Write(dirEsclavo & 0xFE);
    // Dirección del registro a leer
    I2C_Write(dirRegistro);
    // Envía otra señal de inicio, ahora para lectura
    I2C_Repeated_Start();
    I2C_Write(dirEsclavo | 0x01);
    // Leé los registros del RTC
    dato = I2C_Read(0);
    // Fin de la secuencia de lectura
    I2C_Stop();
    
    return dato;
} /* char I2C_leerByte(char, char) */


void I2C_escribirNBytes(char dirEsclavo, char dirRegistro, char* bufer, uint8_t nBytes)
{
    // Inicia una secuencia de escritura
    I2C_Start();
    // Dirección del esclavo
    I2C_Write(dirEsclavo & 0xFE);
    // Dirección del primer registro que se quiere escribir
    I2C_Write(dirRegistro);
    
    // Envía el grupo de bytes
    for (uint8_t i = 0; i != nBytes; i++)
        I2C_Write(*(bufer + i));
    
    // Fin de la secuencia de escritura
    I2C_Stop();
    
} /* void I2C_escribirNBytes(char, char, char*, uint8_t) */


void I2C_leerNBytes(char dirEsclavo, char dirRegistro, char* bufer, uint8_t nBytes)
{
    // Inicia una secuencia de escritura
    I2C_Start();
    // Dirección del esclavo
    I2C_Write(dirEsclavo & 0xFE);
    // Dirección del primer registro que se quiere leer
    I2C_Write(dirRegistro);
    // Envía otra señal de inicio, ahora para lectura
    I2C_Repeated_Start();
    I2C_Write(dirEsclavo | 0x01);
    
    // Lee los n-1 bytes del esclavo
    for(uint8_t i = 0; i != (nBytes - 1); i++)
        *(bufer + i) = I2C_Read(1);
    
    // Lee el último byte
    *(bufer + nBytes - 1) = I2C_Read(0);
    
    // Fin de la secuencia de lectura
    I2C_Stop();
    
} /* void I2C_leerNBytes(char, char, char*, uint8_t) */



static void I2C_Start(void)
{
    I2C_master_wait();
    SSP1CON2bits.SEN = 1;  // initiate start condition
}

static void I2C_Stop(void)
{
    I2C_master_wait();
    SSP1CON2bits.PEN = 1;  // initiate stop condition
}

static void I2C_Write(uint8_t i2c_data)
{
    I2C_master_wait();
    SSP1BUF = i2c_data;  // update buffer
}

static void I2C_Repeated_Start(void)
{
    I2C_master_wait();
    SSP1CON2bits.RSEN = 1;  // initiate repeated start condition
}

static uint8_t I2C_Read(uint8_t ack)
{
    uint8_t _data;
    
    I2C_master_wait();
    SSP1CON2bits.RCEN = 1;  // Habilita modo recibir
    
    I2C_master_wait();
    _data = SSP1BUF;        // Lee el dato del buffer
    
    I2C_master_wait();
    // send acknowledge pulse ? (depends on ack, if 1 send, otherwise don't send)
    SSP1CON2bits.ACKDT = !ack;
    SSP1CON2bits.ACKEN = 1;
    
    return _data;  // return data read
}

/**
 End of File
*/