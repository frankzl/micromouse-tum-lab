#include "gpIO.h"
#include "timer1Functions.h"
#include "uart1Functions.h"

void timer1Setup() 
{
    INTCON1bits.NSTDIS = 0; //nesting of interrupts enabled (1 = disabled)
    T1CONbits.TON = 0; //switches the timer off during setup
    TMR1 = 0; //resets the timer to 0
    T1CONbits.TCKPS = 0b01; //choose an appropriate pre-scale value, choosing 8
    //T1CONbits.TCKPS1 = 1; //choose an appropriate pre-scale value
    //T1CONbits.TCKPS0 = 0; //choosing 64
    PR1 = 20000 - 1; // 10ms value for the period register (62.5ns * 20000 * 8 = 10ms)
    //PR1 = 12500 - 1; // 50ms value for the period register (62.5ns * 12500 * 64 = 50ms)
    T1CONbits.TCS = 0;  // choose internal clock 
    T1CONbits.TSYNC = 0; //TSYNC is ignored when using the internal clock
    T1CONbits.TSIDL = 1; //stop timer in idle mode
    T1CONbits.TGATE = 0; // do not gate the timer
    IFS0bits.T1IF = 0; //clear the interrupt flag
    IEC0bits.T1IE = 1; // enable Timer1 interrupt
    IPC0bits.T1IP = 0b011; //choose interrupt priority, (3)
    T1CONbits.TON = 1;//switches the Timer 1 on 
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF = 0; //reset the timer 1 interrupt flag
    static int timer = 0;
    static char charToSend = 'a';
    
    // blink the LED, always for testing
    // LED2Latch = ~LED2Latch;
    
    // send every 100ms
    if (timer == 10)
    {
        timer = 0;
        // send character
        sendCharacter(charToSend);

        charToSend++;

        if (charToSend > 'z')
        {
            charToSend = 'a';
        }
    }
    timer++;
}
