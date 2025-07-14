/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules
  selected in the GUI. Generation Information : Product Revision  :  PIC10 /
  PIC12 / PIC16 / PIC18 MCUs - 1.81.8 Device            :  PIC16F15213 Driver
  Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software
   and any derivatives exclusively with Microchip products. It is your
   responsibility to comply with third party license terms applicable to your
   use of third party software (including open source software) that may
   accompany Microchip software.

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

// 20250704 CS:DB7E V01
// 輸入信號PWM 200HZ
// duty > 80 brake 輸出HI,否則輸出LO
// 有任何輸入信號時pos HI,LO > 5ms pos lo,brake lo.
// PWM 100% 時pos,brake 也要輸出HI

// 20250704 CS:37A2 V02
// 頻率範圍改為200HZ~220HZ
// duty 80% 時間改成用duty 判斷.

//20250714 CS:35A2 V03
//RA2 RA4 互換

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdbool.h>

#define FREQ_190HZ (190)
#define FREQ_220HZ (220)
#define DUTY_80_PERCENT (80)

uint32_t PWM_Frequent = 0;
uint16_t HI_time = 0;
uint32_t cycle_time = 0;
uint32_t Duty_PERCENT = 0;
bool fpluseOK = 0;

// PWM 0%
void TMR0_EvenHandler(void) {
  Pos_SetLow();
  Brake_SetLow();
}

// PWM 100%
void TMR2_EvenHandler(void) {
  Pos_SetHigh();
  Brake_SetHigh();
}

// PWM 1~99%
static void CCP1_EvenCallBack(uint16_t captured) {
  static uint16_t pluse_width_LO = 0;
  static uint16_t pluse_width_HI = 0;
  // static uint16_t cycle_us = 0;
  static uint16_t HI_us = 0;
  static uint16_t LO_us = 0;
  static uint16_t falling_edge_time = 0;
  static uint16_t rising_edge_time = 0;
  static bool rise_edge_flag = 0;

  // falling edge tringgered
  if (CCP1CON == 0x84) {
    falling_edge_time = captured;
    CCP1CON = 0x85; // set to rising edge trigger
    if (rise_edge_flag == 1) {
      rise_edge_flag = 0;

      if (falling_edge_time >= rising_edge_time) {
        pluse_width_HI = falling_edge_time - rising_edge_time;
      } else {
        pluse_width_HI = (0xffff - rising_edge_time) + falling_edge_time;
      }
      LO_us = (pluse_width_LO >> 3);
      HI_us = (pluse_width_HI >> 3);
      cycle_time = HI_us + LO_us;
      HI_time = HI_us;
      fpluseOK = 1;
    }

  }
  // rising edge tringgered
  else if (CCP1CON == 0x85) {
    Pos_SetHigh();
    TMR0_WriteTimer(0);
    rising_edge_time = captured;
    CCP1CON = 0x84; // set to falling edge trigger
    // 計算低電位脈衝寬度
    if (rising_edge_time >= falling_edge_time) {
      pluse_width_LO = rising_edge_time - falling_edge_time;
    } else {
      pluse_width_LO = (0xffff - falling_edge_time) + rising_edge_time;
    }
    rise_edge_flag = 1;
  }
}

/*
                         Main application
 */
void main(void) {
  // initialize the device
  SYSTEM_Initialize();
  TMR0_SetInterruptHandler(TMR0_EvenHandler);
  CCP1_SetCallBack(CCP1_EvenCallBack);
  TMR2_SetInterruptHandler(TMR2_EvenHandler);

  // When using interrupts, you need to set the Global and Peripheral Interrupt
  // Enable bits Use the following macros to:

  // Enable the Global Interrupts
  INTERRUPT_GlobalInterruptEnable();

  // Enable the Peripheral Interrupts
  INTERRUPT_PeripheralInterruptEnable();

  // Disable the Global Interrupts
  // INTERRUPT_GlobalInterruptDisable();

  // Disable the Peripheral Interrupts
  // INTERRUPT_PeripheralInterruptDisable();
  TMR2_StartTimer();

  while (1) {
    // PWM 100%
    if (RA5_GetValue() == 0) {
      TMR2_WriteTimer(0);
    } else {
      TMR0_WriteTimer(0);
    }

    if (fpluseOK == 1) {
      fpluseOK = 0;
      PWM_Frequent = 1000000UL / cycle_time;
      if ((PWM_Frequent > FREQ_190HZ) && (PWM_Frequent < FREQ_220HZ)) {
        Duty_PERCENT = (uint32_t)(HI_time * 100UL) / cycle_time;
        if (Duty_PERCENT >= DUTY_80_PERCENT) {
          Brake_SetHigh();
        } else {
          Brake_SetLow();
        }
      }
      else {
        Brake_SetLow();
      }
    }
  }
}
/**
 End of File
*/