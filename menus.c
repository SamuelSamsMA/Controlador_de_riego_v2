#include "mcc_generated_files/mcc.h"
#include "teclado_5x4.h"
#include "LCD_4x20.h"


//
// Variables globales
//


//
// Funciones
//

static void cadenaTxt_LCD(const char cad[])
{
    unsigned char i = 0;
    while (cad[i])
    {
        LCD_caracter(cad[i]);
        i++;
    }
}

void MenuPrincipal(void)
{
    // Vector donde se guardan los nombres de las opciones
    const char* Menu_Principal[] =
        { "PROGRAMAS", "ZONAS", "POZO", "FECHA Y HORA", "RESETEAR CONFIG." };
    
    bool pantallaValida = false;
    uint8_t indice = 1;
    uint8_t tecla = TECLA_NULO;
    
    // Se mantiene dentro de la función MenuPrincipal hasta que se presiona la
    // tecla ESC
    while(tecla != TECLA_ESC)
    {
        while (tecla != TECLA_ENT)
        {
            if (!pantallaValida)
            {
                // Imprime el título
                LCD_limpiarPantalla();
                cadenaTxt_LCD("        MENU");
                
                // Despliega opciones 
                if(indice > 0 && indice < 4)
                {
                    LCD_moverCursor(0, L2);
                    LCD_caracter(' ');
                    cadenaTxt_LCD(Menu_Principal[0]);
                    LCD_moverCursor(0, L3);
                    LCD_caracter(' ');
                    cadenaTxt_LCD(Menu_Principal[1]);
                    LCD_moverCursor(0, L4);
                    LCD_caracter(' ');
                    cadenaTxt_LCD(Menu_Principal[2]);
                }
                else if (indice > 3 && indice < 7)
                {
                    LCD_moverCursor(0, L2);
                    LCD_caracter(' ');
                    cadenaTxt_LCD(Menu_Principal[3]);
                    LCD_moverCursor(0, L3);
                    LCD_caracter(' ');
                    cadenaTxt_LCD(Menu_Principal[4]);
                }

                //Imprime una flecha al lado del submenú elegido 
                switch (indice)        
                {
                case 1: case 4: 
                    LCD_moverCursor(0, L2);
                    LCD_caracter('>');
                    break;

                case 2: case 5:
                    LCD_moverCursor(0, L3);
                    LCD_caracter('>');
                    break;

                case 3: 
                    LCD_moverCursor(0, L4);
                    LCD_caracter('>');
                    break;
                }
                pantallaValida = true;
            }   /* if (!pantallaValida) */
            
            tecla = TECLADO_leerTecla();
                        
            switch (tecla)
            {
            case TECLA_ABAJO: 
                if (indice != 5)
                indice++;
                pantallaValida = false;
                break;

            case TECLA_ARRIBA:
                if (indice != 1)
                indice--;
                pantallaValida = false;
                break;

            case TECLA_ESC:
                pantallaValida = false;
                return;
            }   /* switch (tecla) */
        }   /* while (tecla != TECLA_ENT) */

        LCD_limpiarPantalla();
        tecla = TECLA_NULO;

        switch (indice)
        {
            case 1:     //MenuProgramas();
                break;

            case 2:
                //Llamar función MENU ZONAS
                cadenaTxt_LCD("MENU ZONAS");
                __delay_ms(2000);
                break;

            case 3:
                //Llamar función MENU POZO
                cadenaTxt_LCD("MENU POZO");
                __delay_ms(2000);
                break;
                
            case 4:
                //Llamar función MENU POZO
                cadenaTxt_LCD("FECHA Y HORA");
                __delay_ms(2000);
                break;
    
            case 5:
                //Llamar función MENU POZO
                cadenaTxt_LCD("RESETEAR");
                __delay_ms(2000);
                break;
        }   /* switch (indice) */
        
        pantallaValida = false;
    }   /* while(tecla != TECLA_ESC) */
}   /* void MenuPrincipal(void) */
