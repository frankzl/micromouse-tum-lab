#include "gpIO.h"

void gpIOSetup()
{
    // setup the ports
    TRISDbits.TRISD1 = 0;
    //TRISDbits.TRISD3 = 0;
    PORTDbits.RD1 = 0;
    PORTDbits.RD0 = 0;
}