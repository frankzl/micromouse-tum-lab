
#include <xc.h>

#include "IOSetup.h"

void ledSetup(){
    R1_LEDLatch = 0;
    R1_LEDTristate = 0;
    
    // crucial line: PWM pin needs to be disabled
    //PWMCON1bits.PEN1L = 0;
    //LED2Latch = 0;
    //LED2Tristate = 0;
}

void setLED_R1(int state){
    R1_LEDLatch = state;
}

void gpIOSetup(){
    ledSetup();
}