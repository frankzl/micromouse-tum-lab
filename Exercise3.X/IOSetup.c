
#include <p30F4011.h>

#include "IOSetup.h"

void ledSetup(){
    LED2Latch = 1;
}

void gpIOSetup(){
    TRISDbits.TRISD0 = 0;
}