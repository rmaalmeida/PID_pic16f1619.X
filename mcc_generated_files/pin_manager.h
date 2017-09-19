/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16F1619
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()    do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()   do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()   do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()         PORTAbits.RA0
#define RA0_SetDigitalInput()   do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()  do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()     do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()   do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode() do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set channel_AN1 aliases
#define channel_AN1_TRIS               TRISAbits.TRISA1
#define channel_AN1_LAT                LATAbits.LATA1
#define channel_AN1_PORT               PORTAbits.RA1
#define channel_AN1_WPU                WPUAbits.WPUA1
#define channel_AN1_OD                ODCONAbits.ODA1
#define channel_AN1_ANS                ANSELAbits.ANSA1
#define channel_AN1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_AN1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_AN1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_AN1_GetValue()           PORTAbits.RA1
#define channel_AN1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_AN1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_AN1_SetPullup()      do { WPUAbits.WPUA1 = 1; } while(0)
#define channel_AN1_ResetPullup()    do { WPUAbits.WPUA1 = 0; } while(0)
#define channel_AN1_SetPushPull()    do { ODCONAbits.ODA1 = 1; } while(0)
#define channel_AN1_SetOpenDrain()   do { ODCONAbits.ODA1 = 0; } while(0)
#define channel_AN1_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define channel_AN1_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()    do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()   do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()   do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()         PORTAbits.RA2
#define RA2_SetDigitalInput()   do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()  do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()     do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()   do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode() do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set channel_AN3 aliases
#define channel_AN3_TRIS               TRISAbits.TRISA4
#define channel_AN3_LAT                LATAbits.LATA4
#define channel_AN3_PORT               PORTAbits.RA4
#define channel_AN3_WPU                WPUAbits.WPUA4
#define channel_AN3_OD                ODCONAbits.ODA4
#define channel_AN3_ANS                ANSELAbits.ANSA4
#define channel_AN3_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define channel_AN3_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define channel_AN3_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define channel_AN3_GetValue()           PORTAbits.RA4
#define channel_AN3_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define channel_AN3_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define channel_AN3_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define channel_AN3_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define channel_AN3_SetPushPull()    do { ODCONAbits.ODA4 = 1; } while(0)
#define channel_AN3_SetOpenDrain()   do { ODCONAbits.ODA4 = 0; } while(0)
#define channel_AN3_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define channel_AN3_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_RA5 aliases
#define IO_RA5_TRIS               TRISAbits.TRISA5
#define IO_RA5_LAT                LATAbits.LATA5
#define IO_RA5_PORT               PORTAbits.RA5
#define IO_RA5_WPU                WPUAbits.WPUA5
#define IO_RA5_OD                ODCONAbits.ODA5
#define IO_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_RA5_GetValue()           PORTAbits.RA5
#define IO_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_RA5_SetPullup()      do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_RA5_ResetPullup()    do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_RA5_SetPushPull()    do { ODCONAbits.ODA5 = 1; } while(0)
#define IO_RA5_SetOpenDrain()   do { ODCONAbits.ODA5 = 0; } while(0)

// get/set channel_AN4 aliases
#define channel_AN4_TRIS               TRISCbits.TRISC0
#define channel_AN4_LAT                LATCbits.LATC0
#define channel_AN4_PORT               PORTCbits.RC0
#define channel_AN4_WPU                WPUCbits.WPUC0
#define channel_AN4_OD                ODCONCbits.ODC0
#define channel_AN4_ANS                ANSELCbits.ANSC0
#define channel_AN4_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define channel_AN4_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define channel_AN4_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define channel_AN4_GetValue()           PORTCbits.RC0
#define channel_AN4_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define channel_AN4_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define channel_AN4_SetPullup()      do { WPUCbits.WPUC0 = 1; } while(0)
#define channel_AN4_ResetPullup()    do { WPUCbits.WPUC0 = 0; } while(0)
#define channel_AN4_SetPushPull()    do { ODCONCbits.ODC0 = 1; } while(0)
#define channel_AN4_SetOpenDrain()   do { ODCONCbits.ODC0 = 0; } while(0)
#define channel_AN4_SetAnalogMode()  do { ANSELCbits.ANSC0 = 1; } while(0)
#define channel_AN4_SetDigitalMode() do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IO_RC4 aliases
#define IO_RC4_TRIS               TRISCbits.TRISC4
#define IO_RC4_LAT                LATCbits.LATC4
#define IO_RC4_PORT               PORTCbits.RC4
#define IO_RC4_WPU                WPUCbits.WPUC4
#define IO_RC4_OD                ODCONCbits.ODC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()      do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()    do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()    do { ODCONCbits.ODC4 = 1; } while(0)
#define IO_RC4_SetOpenDrain()   do { ODCONCbits.ODC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS               TRISCbits.TRISC5
#define IO_RC5_LAT                LATCbits.LATC5
#define IO_RC5_PORT               PORTCbits.RC5
#define IO_RC5_WPU                WPUCbits.WPUC5
#define IO_RC5_OD                ODCONCbits.ODC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()    do { ODCONCbits.ODC5 = 1; } while(0)
#define IO_RC5_SetOpenDrain()   do { ODCONCbits.ODC5 = 0; } while(0)

// get/set channel_AN9 aliases
#define channel_AN9_TRIS               TRISCbits.TRISC7
#define channel_AN9_LAT                LATCbits.LATC7
#define channel_AN9_PORT               PORTCbits.RC7
#define channel_AN9_WPU                WPUCbits.WPUC7
#define channel_AN9_OD                ODCONCbits.ODC7
#define channel_AN9_ANS                ANSELCbits.ANSC7
#define channel_AN9_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define channel_AN9_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define channel_AN9_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define channel_AN9_GetValue()           PORTCbits.RC7
#define channel_AN9_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define channel_AN9_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define channel_AN9_SetPullup()      do { WPUCbits.WPUC7 = 1; } while(0)
#define channel_AN9_ResetPullup()    do { WPUCbits.WPUC7 = 0; } while(0)
#define channel_AN9_SetPushPull()    do { ODCONCbits.ODC7 = 1; } while(0)
#define channel_AN9_SetOpenDrain()   do { ODCONCbits.ODC7 = 0; } while(0)
#define channel_AN9_SetAnalogMode()  do { ANSELCbits.ANSC7 = 1; } while(0)
#define channel_AN9_SetDigitalMode() do { ANSELCbits.ANSC7 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/