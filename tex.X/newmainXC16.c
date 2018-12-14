/*
 * File:   newmainXC16.c
 * Author: Natalia
 *
 * Created on 26 October 2018, 14:44
 */

#include "xc.h"
#include "IOSetup.h"
#include "timer1Functions.h"
#include "pwm1Functions.h"
#include "uartFunctions.h"
#include "motorFunctions.h"
#include "qeiFunctions.h"

// FOSC
#pragma config FPR = XT_PLL8            // Primary Oscillator Mode (XT w/PLL 8x)
#pragma config FOS = PRI                // Oscillator Source (Primary Oscillator)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_OFF         // PBOR Enable (Disabled)
#pragma config LPOL = PWMxL_ACT_HI      // Low-side PWM Output Polarity (Active High)
#pragma config HPOL = PWMxH_ACT_LO      // High-side PWM Output Polarity (Active Low)
#pragma config PWMPIN = RST_PWMPIN      // PWM Output Pin Reset (Control with HPOL/LPOL bits)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)
 
// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
//lets set the device configuration bits using the pre-processor macros
//_FOSC(PRI  &  XT_PLL8 & CSW_FSCM_OFF  );
//primary oscillator with 8 times pll no clock switching
//_FWDT(WDT_OFF);
//watch dog is disabled
//_FBORPOR( PBOR_OFF & MCLR_EN & PWRT_64 & PWMxL_ACT_HI &  PWMxH_ACT_LO &RST_PWMPIN);
//brown out disabled, master-clear enabled, power on reset time = 64ms
//pwm low side is active high, pwm high side is active low,
//reset state controlled with HPOL/LPOL bits

//void wait_500ms() 
//{
//    float counter;
//   // for (int i = 0; i < 10; i++)
//   // {   
//        counter = 1;
//       for (int i = 0; i < 9000; i ++)
//        {
//            counter = counter * 2;
//        };
//   // }
//}

void LED_init() 
{
    LED2Latch = 0;
    //LED3Latch = 1;
}

int main(void) 
{
    gpIOSetup();
    LED_init();
    pwm1Setup();
    uartSetup();
    Timer1Setup();  
    
    motorSetup();
    
    setupQEI();
    
    changeDC();
    
    while(1){
        // infinite cycle
    }
    return 0; 
}
