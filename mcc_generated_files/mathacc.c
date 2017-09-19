

/**
  MATHACC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    mathacc.c

  @Summary
    This is the generated driver implementation file for the MATHACC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  @Description
    This header file provides implementations for driver APIs for MATHACC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F1619
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "mathacc.h"

/**
  Section: MATHACC APIs
*/




void MATHACC_Initialize(void)
{
    // set the PID module to the options selected in the User Interface
    // PID1MODE PID Controller; PID1EN enabled; 
    PID1CON = 0x85;
    
    PID1K1H = (uint8_t) ((0 & 0xFF00) >> 8);
    PID1K1L = (uint8_t)  (0 & 0x00FF);
    PID1K2H = (uint8_t) ((0 & 0xFF00) >> 8);
    PID1K2L = (uint8_t)  (0 & 0x00FF);
    PID1K3H = (uint8_t) ((0 & 0xFF00) >> 8);
    PID1K3L = (uint8_t)  (0 & 0x00FF);
}

                    
MATHACCResult MATHACC_PIDControllerModeResultGet(int16_t setpoint, int16_t input)
{
    MATHACCResult result;

    PID1SETH = (uint8_t) (((uint16_t)setpoint & 0xFF00) >> 8);
    PID1SETL = (uint8_t)  (setpoint & 0x00FF);  
    PID1INH  = (uint8_t) (((uint16_t)input & 0xFF00) >> 8);
    PID1INL  = (uint8_t)  (input & 0x00FF);   // starts module operation

    while (PID1CONbits.PID1BUSY == 1);  // wait for the module to complete

    result.byteLL = PID1OUTLL;
    result.byteLH = PID1OUTLH;
    result.byteHL = PID1OUTHL;
    result.byteHH = PID1OUTHH;
    result.byteU  = PID1OUTU;
	
    return result;
}	
         

uint32_t MATHACC_Z1Get(void)
{
    uint32_t value = 0;

    value = (uint32_t)PID1Z1L & 0x000000FF;
    value = (value | ((uint32_t)PID1Z1H << 8)) & 0x0000FFFF;
    value = (value | ((uint32_t)PID1Z1U << 16)) & 0x0001FFFF;

    return value;
}

uint32_t MATHACC_Z2Get(void)
{
    uint32_t value = 0;

    value = (uint32_t)PID1Z2L & 0x000000FF;
    value = (value | ((uint32_t)PID1Z2H << 8)) & 0x0000FFFF;
    value = (value | ((uint32_t)PID1Z2U << 16)) & 0x0001FFFF;

    return value;
}

void MATHACC_LoadZ1(uint32_t value)
{
    PID1Z1L = (0x000000FF & value);
    PID1Z1H = ((0x0000FF00 & value)>>8);
    PID1Z1U = ((0x00010000 & value)>>16);
}

void MATHACC_LoadZ2(uint32_t value)
{
    PID1Z2L = (0x000000FF & value);
    PID1Z2H = ((0x0000FF00 & value)>>8);
    PID1Z2U = ((0x00010000 & value)>>16);
}
      

MATHACCResult MATHACC_ResultGet(void)
{
    MATHACCResult data;

    data.byteLL = PID1OUTLL;
    data.byteLH = PID1OUTLH;
    data.byteHL = PID1OUTHL;
    data.byteHH = PID1OUTHH;
    data.byteU = PID1OUTU;

    return data;
}

void MATHACC_ClearResult(void)
{
    PID1OUTLL = 0;
    PID1OUTLH = 0;
    PID1OUTHL = 0;
    PID1OUTHH = 0;
    PID1OUTU  = 0;
}

bool MATHACC_HasOverflowOccured(void)
{
    bool retVal = false;
    
    if (1 == PIR5bits.PID1EIF)
    {
        retVal = true;
        PIR5bits.PID1EIF = 0;
    }
    
    return retVal;
}
// end of file
     
        

        
