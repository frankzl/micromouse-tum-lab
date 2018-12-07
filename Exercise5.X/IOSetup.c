#include "IOSetup.h"

void ledSetup(){
    R0_LEDLatch = 0;
    R0_LEDTristate = 0;
    
    // crucial line: PWM pin needs to be disabled
    //PWMCON1bits.PEN1L = 0;
    //LED2Latch = 0;
    //LED2Tristate = 0;
}

void setLED_R0(int state){
    R0_LEDLatch = state;
}

void motorSetup(){
    TRISBbits.TRISB2 = 0;
    LATBbits.LATB2 = 1;
    TRISBbits.TRISB3 = 0;
    LATBbits.LATB3 = 0;
}

void gpIOSetup(){
    ledSetup();
    motorSetup();
}