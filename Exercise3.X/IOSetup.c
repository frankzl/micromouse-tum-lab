
#include <p30F4011.h>

#include "IOSetup.h"

void ledSetup(){
    LEDLatch = 0;
    LEDTristate = 0;
    
    // crucial line: PWM pin needs to be disabled
    PWMCON1bits.PEN1L = 0;
    LED2Latch = 0;
    LED2Tristate = 0;
}

void gpIOSetup(){
    ledSetup();
}