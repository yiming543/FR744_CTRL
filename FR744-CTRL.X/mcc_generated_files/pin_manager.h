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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15213
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

// get/set Brake aliases
#define Brake_TRIS                 TRISAbits.TRISA2
#define Brake_LAT                  LATAbits.LATA2
#define Brake_PORT                 PORTAbits.RA2
#define Brake_WPU                  WPUAbits.WPUA2
#define Brake_OD                   ODCONAbits.ODCA2
#define Brake_ANS                  ANSELAbits.ANSA2
#define Brake_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Brake_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Brake_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Brake_GetValue()           PORTAbits.RA2
#define Brake_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Brake_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Brake_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define Brake_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define Brake_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define Brake_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define Brake_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define Brake_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set Pos aliases
#define Pos_TRIS                 TRISAbits.TRISA4
#define Pos_LAT                  LATAbits.LATA4
#define Pos_PORT                 PORTAbits.RA4
#define Pos_WPU                  WPUAbits.WPUA4
#define Pos_OD                   ODCONAbits.ODCA4
#define Pos_ANS                  ANSELAbits.ANSA4
#define Pos_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define Pos_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define Pos_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define Pos_GetValue()           PORTAbits.RA4
#define Pos_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define Pos_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define Pos_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define Pos_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define Pos_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define Pos_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define Pos_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define Pos_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSA5 = 0; } while(0)

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