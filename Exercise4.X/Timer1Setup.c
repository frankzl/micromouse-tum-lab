
#include "Timer1Setup.h"
#include "IOSetup.h"

void Timer1Setup()
{
    T1CONbits.TON = 0; //switches the timer off during setup
    TMR1 = 0; //resets the timer to 0
    T1CONbits.TCKPS1 = 1; //choose an appropriate pre-scale value
    T1CONbits.TCKPS0 = 0; //choosing 64
    PR1 = 12500 - 1; // 50ms value for the period register
    T1CONbits.TCS = 0;  // choose internal clock 
    T1CONbits.TSYNC = 0; //TSYNC is ignored when using the internal clock
    T1CONbits.TSIDL = 1; //stop timer in idle mode
    T1CONbits.TGATE = 0; // do not gate the timer
    IFS0bits.T1IF=0; //clear the interrupt flag
    IPC0bits.T1IP = 0b011; //choose interrupt priority
    IEC0bits.T1IE = 1; // enable Timer1 interrupt
    T1CONbits.TON = 1;//switches the Timer 1 on 
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF=0; //reset the timer 1 interrupt flag
    setLED_R1(~R1_LEDLatch);
    //LED2Latch = ~LED2Latch; // switch the LED2
    //LED3Latch = ~LED3Latch; // switch the LED3
}