#include <p30F4012.h>
#include <stdlib.h>

#include "timer1Functions.h"
#include "IOSetup.h"
#include "uartFunctions.h"

#include "qeiFunctions.h"
#include "pidFunctions.h"
#include "pwm1Functions.h"
#include "motorFunctions.h"

extern long xx_xx;

pid_ctrl pid;

void Timer1Setup()
{
    T1CONbits.TON = 0; //switches the timer off during setup
    TMR1 = 0; //resets the timer to 0
    T1CONbits.TCKPS1 = 1; //choose an appropriate pre-scale value
    T1CONbits.TCKPS0 = 0; //choosing 64
    PR1 = 2500 - 1; // 50ms value for the period register
    T1CONbits.TCS = 0;  // choose internal clock 
    T1CONbits.TSYNC = 0; //TSYNC is ignored when using the internal clock
    T1CONbits.TSIDL = 1; //stop timer in idle mode
    T1CONbits.TGATE = 0; // do not gate the timer
    IFS0bits.T1IF=0; //clear the interrupt flag
    IPC0bits.T1IP = 0b011; //choose interrupt priority
    IEC0bits.T1IE = 1; // enable Timer1 interrupt
    T1CONbits.TON = 1;//switches the Timer 1 on 
    
    pid_init(&pid);
}

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF=0; //reset the timer 1 interrupt flag
    
    int desired = 27;
    
    static long old_POSCNT = 0x7FFF;
    
    long new_POSCNT = POSCNT + xx_xx;
    
    int velocity = ( new_POSCNT - old_POSCNT );
    // initially the velocity might be gibberish when the motor is still standing
    if (velocity > 80 || velocity < -80){
        velocity = 0;
    }

    int err = (desired - velocity);
    
    int squeeze = (int) (pid_process(&pid, (float) err));
    
    motorDrive(squeeze);
    
    static int counter = 0;
    if(counter < 100){
        WriteIntUART( 2000 + velocity ) ;
        counter++;
    }
    
    old_POSCNT = new_POSCNT;
}
