/*
 * File:   teclado_5x4.c
 * Author: Samuel Muñoz Aguilar
 *
 * Created on July 05, 2020, 7:40 PM
 */

#include "mcc_generated_files/mcc.h"
#include "teclado_5x4.h"


//
// Variables globales
//
uint8_t tecla_activa = TECLA_NULO;

const uint8_t teclado[5][4] = {
    {14, 15, 16, 17},
    { 1,  2,  3, 12},
    { 4,  5,  6, 13},
    { 7,  8,  9, 18},
    {11,  0, 10, 19}
};


//
// Funciones
//
uint8_t TECLADO_leerTecla(void)
{
    uint8_t temp = tecla_activa;
    tecla_activa = TECLA_NULO;
    
    return temp;
}

void TECLADO_interrupcion(void)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        if (obtenerColumna(i))
        {
            apagarFilas();
            
            for (uint8_t j = 0; j < 5; j++)
            {
                switch (j) {
                    case 0: TECLADO_F1_SetHigh(); break;
                    case 1: TECLADO_F2_SetHigh(); break;
                    case 2: TECLADO_F3_SetHigh(); break;
                    case 3: TECLADO_F4_SetHigh(); break;
                    case 4: TECLADO_F5_SetHigh(); break;            
                }
                
                if (obtenerColumna(i))
                    tecla_activa = teclado[j][i];
                apagarFilas();
            }
            encenderFilas();
        }
    }
}

bool obtenerColumna (uint8_t columna)
{
    bool valor = false;
    
    switch (columna) {
        case 0:
            valor = TECLADO_C1_GetValue(); break;
        case 1:
            valor = TECLADO_C2_GetValue(); break;
        case 2:
            valor = TECLADO_C3_GetValue(); break;
        case 3:
            valor = TECLADO_C4_GetValue(); break;    
    }
    return (valor);
}

/**
 End of File
*/