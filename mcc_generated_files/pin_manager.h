/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC16F1779
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA0
#define LED_LAT                  LATAbits.LATA0
#define LED_PORT                 PORTAbits.RA0
#define LED_WPU                  WPUAbits.WPUA0
#define LED_OD                   ODCONAbits.ODA0
#define LED_ANS                  ANSELAbits.ANSA0
#define LED_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_GetValue()           PORTAbits.RA0
#define LED_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set BOMBA aliases
#define BOMBA_TRIS                 TRISAbits.TRISA1
#define BOMBA_LAT                  LATAbits.LATA1
#define BOMBA_PORT                 PORTAbits.RA1
#define BOMBA_WPU                  WPUAbits.WPUA1
#define BOMBA_OD                   ODCONAbits.ODA1
#define BOMBA_ANS                  ANSELAbits.ANSA1
#define BOMBA_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BOMBA_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BOMBA_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BOMBA_GetValue()           PORTAbits.RA1
#define BOMBA_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BOMBA_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BOMBA_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define BOMBA_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define BOMBA_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define BOMBA_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define BOMBA_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define BOMBA_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set ZONA_1 aliases
#define ZONA_1_TRIS                 TRISAbits.TRISA2
#define ZONA_1_LAT                  LATAbits.LATA2
#define ZONA_1_PORT                 PORTAbits.RA2
#define ZONA_1_WPU                  WPUAbits.WPUA2
#define ZONA_1_OD                   ODCONAbits.ODA2
#define ZONA_1_ANS                  ANSELAbits.ANSA2
#define ZONA_1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define ZONA_1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define ZONA_1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define ZONA_1_GetValue()           PORTAbits.RA2
#define ZONA_1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define ZONA_1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define ZONA_1_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define ZONA_1_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define ZONA_1_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define ZONA_1_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define ZONA_1_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define ZONA_1_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set ZONA_2 aliases
#define ZONA_2_TRIS                 TRISAbits.TRISA3
#define ZONA_2_LAT                  LATAbits.LATA3
#define ZONA_2_PORT                 PORTAbits.RA3
#define ZONA_2_WPU                  WPUAbits.WPUA3
#define ZONA_2_OD                   ODCONAbits.ODA3
#define ZONA_2_ANS                  ANSELAbits.ANSA3
#define ZONA_2_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define ZONA_2_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define ZONA_2_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define ZONA_2_GetValue()           PORTAbits.RA3
#define ZONA_2_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define ZONA_2_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define ZONA_2_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define ZONA_2_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define ZONA_2_SetPushPull()        do { ODCONAbits.ODA3 = 0; } while(0)
#define ZONA_2_SetOpenDrain()       do { ODCONAbits.ODA3 = 1; } while(0)
#define ZONA_2_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define ZONA_2_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set ZONA_3 aliases
#define ZONA_3_TRIS                 TRISAbits.TRISA4
#define ZONA_3_LAT                  LATAbits.LATA4
#define ZONA_3_PORT                 PORTAbits.RA4
#define ZONA_3_WPU                  WPUAbits.WPUA4
#define ZONA_3_OD                   ODCONAbits.ODA4
#define ZONA_3_ANS                  ANSELAbits.ANSA4
#define ZONA_3_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define ZONA_3_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define ZONA_3_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define ZONA_3_GetValue()           PORTAbits.RA4
#define ZONA_3_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define ZONA_3_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define ZONA_3_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define ZONA_3_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define ZONA_3_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define ZONA_3_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define ZONA_3_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define ZONA_3_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set POZO aliases
#define POZO_TRIS                 TRISAbits.TRISA5
#define POZO_LAT                  LATAbits.LATA5
#define POZO_PORT                 PORTAbits.RA5
#define POZO_WPU                  WPUAbits.WPUA5
#define POZO_OD                   ODCONAbits.ODA5
#define POZO_ANS                  ANSELAbits.ANSA5
#define POZO_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define POZO_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define POZO_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define POZO_GetValue()           PORTAbits.RA5
#define POZO_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define POZO_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define POZO_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define POZO_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define POZO_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define POZO_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)
#define POZO_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define POZO_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set LCD_EN aliases
#define LCD_EN_TRIS                 TRISAbits.TRISA6
#define LCD_EN_LAT                  LATAbits.LATA6
#define LCD_EN_PORT                 PORTAbits.RA6
#define LCD_EN_WPU                  WPUAbits.WPUA6
#define LCD_EN_OD                   ODCONAbits.ODA6
#define LCD_EN_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LCD_EN_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LCD_EN_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LCD_EN_GetValue()           PORTAbits.RA6
#define LCD_EN_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LCD_EN_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define LCD_EN_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define LCD_EN_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define LCD_EN_SetPushPull()        do { ODCONAbits.ODA6 = 0; } while(0)
#define LCD_EN_SetOpenDrain()       do { ODCONAbits.ODA6 = 1; } while(0)

// get/set LCD_RS aliases
#define LCD_RS_TRIS                 TRISAbits.TRISA7
#define LCD_RS_LAT                  LATAbits.LATA7
#define LCD_RS_PORT                 PORTAbits.RA7
#define LCD_RS_WPU                  WPUAbits.WPUA7
#define LCD_RS_OD                   ODCONAbits.ODA7
#define LCD_RS_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LCD_RS_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LCD_RS_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LCD_RS_GetValue()           PORTAbits.RA7
#define LCD_RS_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LCD_RS_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LCD_RS_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LCD_RS_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LCD_RS_SetPushPull()        do { ODCONAbits.ODA7 = 0; } while(0)
#define LCD_RS_SetOpenDrain()       do { ODCONAbits.ODA7 = 1; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set TECLADO_C1 aliases
#define TECLADO_C1_TRIS                 TRISCbits.TRISC0
#define TECLADO_C1_LAT                  LATCbits.LATC0
#define TECLADO_C1_PORT                 PORTCbits.RC0
#define TECLADO_C1_WPU                  WPUCbits.WPUC0
#define TECLADO_C1_OD                   ODCONCbits.ODC0
#define TECLADO_C1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define TECLADO_C1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define TECLADO_C1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define TECLADO_C1_GetValue()           PORTCbits.RC0
#define TECLADO_C1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define TECLADO_C1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define TECLADO_C1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define TECLADO_C1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define TECLADO_C1_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define TECLADO_C1_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)

// get/set TECLADO_C2 aliases
#define TECLADO_C2_TRIS                 TRISCbits.TRISC1
#define TECLADO_C2_LAT                  LATCbits.LATC1
#define TECLADO_C2_PORT                 PORTCbits.RC1
#define TECLADO_C2_WPU                  WPUCbits.WPUC1
#define TECLADO_C2_OD                   ODCONCbits.ODC1
#define TECLADO_C2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define TECLADO_C2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define TECLADO_C2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define TECLADO_C2_GetValue()           PORTCbits.RC1
#define TECLADO_C2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define TECLADO_C2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define TECLADO_C2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define TECLADO_C2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define TECLADO_C2_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define TECLADO_C2_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)

// get/set TECLADO_C3 aliases
#define TECLADO_C3_TRIS                 TRISCbits.TRISC2
#define TECLADO_C3_LAT                  LATCbits.LATC2
#define TECLADO_C3_PORT                 PORTCbits.RC2
#define TECLADO_C3_WPU                  WPUCbits.WPUC2
#define TECLADO_C3_OD                   ODCONCbits.ODC2
#define TECLADO_C3_ANS                  ANSELCbits.ANSC2
#define TECLADO_C3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define TECLADO_C3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define TECLADO_C3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define TECLADO_C3_GetValue()           PORTCbits.RC2
#define TECLADO_C3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define TECLADO_C3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define TECLADO_C3_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define TECLADO_C3_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define TECLADO_C3_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define TECLADO_C3_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define TECLADO_C3_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define TECLADO_C3_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set TECLADO_C4 aliases
#define TECLADO_C4_TRIS                 TRISCbits.TRISC3
#define TECLADO_C4_LAT                  LATCbits.LATC3
#define TECLADO_C4_PORT                 PORTCbits.RC3
#define TECLADO_C4_WPU                  WPUCbits.WPUC3
#define TECLADO_C4_OD                   ODCONCbits.ODC3
#define TECLADO_C4_ANS                  ANSELCbits.ANSC3
#define TECLADO_C4_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define TECLADO_C4_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define TECLADO_C4_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define TECLADO_C4_GetValue()           PORTCbits.RC3
#define TECLADO_C4_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define TECLADO_C4_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define TECLADO_C4_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define TECLADO_C4_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define TECLADO_C4_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define TECLADO_C4_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define TECLADO_C4_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define TECLADO_C4_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set TECLADO_F1 aliases
#define TECLADO_F1_TRIS                 TRISCbits.TRISC4
#define TECLADO_F1_LAT                  LATCbits.LATC4
#define TECLADO_F1_PORT                 PORTCbits.RC4
#define TECLADO_F1_WPU                  WPUCbits.WPUC4
#define TECLADO_F1_OD                   ODCONCbits.ODC4
#define TECLADO_F1_ANS                  ANSELCbits.ANSC4
#define TECLADO_F1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define TECLADO_F1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define TECLADO_F1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define TECLADO_F1_GetValue()           PORTCbits.RC4
#define TECLADO_F1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define TECLADO_F1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define TECLADO_F1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define TECLADO_F1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define TECLADO_F1_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define TECLADO_F1_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)
#define TECLADO_F1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define TECLADO_F1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set TECLADO_F2 aliases
#define TECLADO_F2_TRIS                 TRISCbits.TRISC5
#define TECLADO_F2_LAT                  LATCbits.LATC5
#define TECLADO_F2_PORT                 PORTCbits.RC5
#define TECLADO_F2_WPU                  WPUCbits.WPUC5
#define TECLADO_F2_OD                   ODCONCbits.ODC5
#define TECLADO_F2_ANS                  ANSELCbits.ANSC5
#define TECLADO_F2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define TECLADO_F2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define TECLADO_F2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define TECLADO_F2_GetValue()           PORTCbits.RC5
#define TECLADO_F2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define TECLADO_F2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define TECLADO_F2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define TECLADO_F2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define TECLADO_F2_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define TECLADO_F2_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)
#define TECLADO_F2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define TECLADO_F2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set TECLADO_F3 aliases
#define TECLADO_F3_TRIS                 TRISCbits.TRISC6
#define TECLADO_F3_LAT                  LATCbits.LATC6
#define TECLADO_F3_PORT                 PORTCbits.RC6
#define TECLADO_F3_WPU                  WPUCbits.WPUC6
#define TECLADO_F3_OD                   ODCONCbits.ODC6
#define TECLADO_F3_ANS                  ANSELCbits.ANSC6
#define TECLADO_F3_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define TECLADO_F3_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define TECLADO_F3_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define TECLADO_F3_GetValue()           PORTCbits.RC6
#define TECLADO_F3_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define TECLADO_F3_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define TECLADO_F3_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define TECLADO_F3_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define TECLADO_F3_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define TECLADO_F3_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define TECLADO_F3_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define TECLADO_F3_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set TECLADO_F4 aliases
#define TECLADO_F4_TRIS                 TRISCbits.TRISC7
#define TECLADO_F4_LAT                  LATCbits.LATC7
#define TECLADO_F4_PORT                 PORTCbits.RC7
#define TECLADO_F4_WPU                  WPUCbits.WPUC7
#define TECLADO_F4_OD                   ODCONCbits.ODC7
#define TECLADO_F4_ANS                  ANSELCbits.ANSC7
#define TECLADO_F4_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define TECLADO_F4_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define TECLADO_F4_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define TECLADO_F4_GetValue()           PORTCbits.RC7
#define TECLADO_F4_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define TECLADO_F4_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define TECLADO_F4_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define TECLADO_F4_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define TECLADO_F4_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define TECLADO_F4_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define TECLADO_F4_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define TECLADO_F4_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set LCD_D4 aliases
#define LCD_D4_TRIS                 TRISDbits.TRISD0
#define LCD_D4_LAT                  LATDbits.LATD0
#define LCD_D4_PORT                 PORTDbits.RD0
#define LCD_D4_WPU                  WPUDbits.WPUD0
#define LCD_D4_OD                   ODCONDbits.ODD0
#define LCD_D4_ANS                  ANSELDbits.ANSD0
#define LCD_D4_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LCD_D4_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LCD_D4_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LCD_D4_GetValue()           PORTDbits.RD0
#define LCD_D4_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LCD_D4_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LCD_D4_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define LCD_D4_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define LCD_D4_SetPushPull()        do { ODCONDbits.ODD0 = 0; } while(0)
#define LCD_D4_SetOpenDrain()       do { ODCONDbits.ODD0 = 1; } while(0)
#define LCD_D4_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define LCD_D4_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set LCD_D5 aliases
#define LCD_D5_TRIS                 TRISDbits.TRISD1
#define LCD_D5_LAT                  LATDbits.LATD1
#define LCD_D5_PORT                 PORTDbits.RD1
#define LCD_D5_WPU                  WPUDbits.WPUD1
#define LCD_D5_OD                   ODCONDbits.ODD1
#define LCD_D5_ANS                  ANSELDbits.ANSD1
#define LCD_D5_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LCD_D5_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LCD_D5_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LCD_D5_GetValue()           PORTDbits.RD1
#define LCD_D5_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LCD_D5_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LCD_D5_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LCD_D5_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LCD_D5_SetPushPull()        do { ODCONDbits.ODD1 = 0; } while(0)
#define LCD_D5_SetOpenDrain()       do { ODCONDbits.ODD1 = 1; } while(0)
#define LCD_D5_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define LCD_D5_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set LCD_D6 aliases
#define LCD_D6_TRIS                 TRISDbits.TRISD2
#define LCD_D6_LAT                  LATDbits.LATD2
#define LCD_D6_PORT                 PORTDbits.RD2
#define LCD_D6_WPU                  WPUDbits.WPUD2
#define LCD_D6_OD                   ODCONDbits.ODD2
#define LCD_D6_ANS                  ANSELDbits.ANSD2
#define LCD_D6_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LCD_D6_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LCD_D6_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LCD_D6_GetValue()           PORTDbits.RD2
#define LCD_D6_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LCD_D6_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LCD_D6_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define LCD_D6_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define LCD_D6_SetPushPull()        do { ODCONDbits.ODD2 = 0; } while(0)
#define LCD_D6_SetOpenDrain()       do { ODCONDbits.ODD2 = 1; } while(0)
#define LCD_D6_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define LCD_D6_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set LCD_D7 aliases
#define LCD_D7_TRIS                 TRISDbits.TRISD3
#define LCD_D7_LAT                  LATDbits.LATD3
#define LCD_D7_PORT                 PORTDbits.RD3
#define LCD_D7_WPU                  WPUDbits.WPUD3
#define LCD_D7_OD                   ODCONDbits.ODD3
#define LCD_D7_ANS                  ANSELDbits.ANSD3
#define LCD_D7_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LCD_D7_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LCD_D7_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LCD_D7_GetValue()           PORTDbits.RD3
#define LCD_D7_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LCD_D7_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define LCD_D7_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define LCD_D7_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define LCD_D7_SetPushPull()        do { ODCONDbits.ODD3 = 0; } while(0)
#define LCD_D7_SetOpenDrain()       do { ODCONDbits.ODD3 = 1; } while(0)
#define LCD_D7_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define LCD_D7_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set TECLADO_F5 aliases
#define TECLADO_F5_TRIS                 TRISDbits.TRISD4
#define TECLADO_F5_LAT                  LATDbits.LATD4
#define TECLADO_F5_PORT                 PORTDbits.RD4
#define TECLADO_F5_WPU                  WPUDbits.WPUD4
#define TECLADO_F5_OD                   ODCONDbits.ODD4
#define TECLADO_F5_ANS                  ANSELDbits.ANSD4
#define TECLADO_F5_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define TECLADO_F5_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define TECLADO_F5_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define TECLADO_F5_GetValue()           PORTDbits.RD4
#define TECLADO_F5_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define TECLADO_F5_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define TECLADO_F5_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define TECLADO_F5_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define TECLADO_F5_SetPushPull()        do { ODCONDbits.ODD4 = 0; } while(0)
#define TECLADO_F5_SetOpenDrain()       do { ODCONDbits.ODD4 = 1; } while(0)
#define TECLADO_F5_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define TECLADO_F5_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF0 pin functionality
 * @Example
    IOCCF0_ISR();
 */
void IOCCF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_InterruptHandler);

*/
extern void (*IOCCF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_DefaultInterruptHandler);

*/
void IOCCF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF2 pin functionality
 * @Example
    IOCCF2_ISR();
 */
void IOCCF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_InterruptHandler);

*/
extern void (*IOCCF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_DefaultInterruptHandler);

*/
void IOCCF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF3 pin functionality
 * @Example
    IOCCF3_ISR();
 */
void IOCCF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_InterruptHandler);

*/
extern void (*IOCCF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_DefaultInterruptHandler);

*/
void IOCCF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/