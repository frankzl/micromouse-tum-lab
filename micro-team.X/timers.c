#include "timers.h"
#include "initIO.h"
#include "pwm.h"
#include "math.h"
#include "dma.h"
#include "Serialuart.h"
#include "encoder.h"
#include "control.h"
void initTimer1(unsigned int period) 
{
    T1CON = 0; // ensure Timer 1 is in reset state
    T1CONbits.TGATE = 0; // gated time accumulation disabled
    T1CONbits.TCKPS = 0b10; // FCY divide by 64: tick = 1.6us
    T1CONbits.TCS = 0; // select internal FCY clock source
    TMR1 = 0;
    PR1 = period; // set Timer 1 period register ()
    IFS0bits.T1IF = 0; // reset Timer 1 interrupt flag
    IPC0bits.T1IP = 4; // set Timer1 interrupt priority level to 4
    IEC0bits.T1IE = 1; // enable Timer 1 interrupt
    T1CONbits.TON = 0; // leave timer disabled initially
}

void startTimer1(void) {
    T1CONbits.TON = 1; //
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
{
    static int count = 0;
    static int timecount=0;
    float time;


     IFS0bits.T1IF = 0; // reset Timer 1 interrupt flag
     
    if (count < 9)
    {
        count++;
        
        
    } else
    {
        
       // LED0=~LED0;
        count = 0;
              
 
    }
     AD1CON1bits.ASAM=1;//start adc
     timecount++;
     time=timecount*0.010;
     mainControl();
     

}