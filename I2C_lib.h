/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef XC_I2C_LIB_H
#define	XC_I2C_LIB_H

#include <xc.h> 

//
// Macros
//
#define I2C_master_wait()   while ((SSP1STAT & 0x04) || (SSP1CON2 & 0x1F))


//
// Prototipos de funciones
//

/**
 * Inicializa al m�dulo MSSP en modo I2C maestro, con una frecuencia de 100 kHz.
 * 
 * @param
 * @return
 */
void I2C_iniciar(void);

/**
 * Env�a un byte de datos a un dispositivo conectado al bus I2C.
 * 
 * @param dirEsclavo    Direcci�n de 7 bits del dispositivo esclavo.
 * @param dirRegistro   Direcci�n del registro en que se guardar� el dato.
 * @param dato          Byte que se quiere enviar.
 */
void I2C_escribirByte(char dirEsclavo, char dirRegistro, char dato);

/**
 * Recibe un byte de datos de un dispositivo conectado al bus I2C.
 * 
 * @param dirEsclavo    Direcci�n de 7 bits del dispositivo esclavo.
 * @param dirRegistro   Direcci�n del registro a leer.
 * @return              El contenido del registro solicitado.
 */
char I2C_leerByte(char dirEsclavo, char dirRegistro);

/**
 * Env�a n bytes de datos a un dispositivo conectado al bus I2C.
 * 
 * @param dirEsclavo    Direcci�n de 7 bits del dispositivo esclavo.
 * @param dirRegistro   Direcci�n del primer registro del esclavo que recibir� los datos.
 * @param bufer         Contenedor de los datos que se desean enviar.
 * @param nBytes        N�mero de bytes que a enviar.
 */
void I2C_escribirNBytes(char dirEsclavo, char dirRegistro, char* bufer, uint8_t nBytes);

/**
 * Recibe n bytes de datos de un dispositivo conectado al bus I2C.
 * 
 * @param dirEsclavo    Direcci�n de 7 bits del dispositivo esclavo.
 * @param dirRegistro   Direcci�n del primer registro del esclavo que enviar� los datos.
 * @param bufer         Contenedor para guardar los datos recibidos.
 * @param nBytes        N�mero de bytes a recibir.
 */
void I2C_leerNBytes(char dirEsclavo, char dirRegistro, char* bufer, uint8_t nBytes);


static void I2C_Start(void);
static void I2C_Stop(void);
static void I2C_Write(uint8_t i2c_data);
static void I2C_Repeated_Start(void);
static uint8_t I2C_Read(uint8_t ack);

#endif	/* XC_I2C_LIB_H */

