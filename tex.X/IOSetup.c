#include "IOSetup.h"

void gpIOSetup()
{
    // setup the ports
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD0 = 0;
    //TRISDbits.TRISD3 = 0;
   // TRISCbits.TRISC13 = 0;
    TRISFbits.TRISF3 = 0; // pin 17 
    
    // motor pins
    // direction A
    TRISBbits.TRISB2 = 0; 
    LATBbits.LATB2 = 1;
    // direction B
    TRISBbits.TRISB3 = 0;
    LATBbits.LATB3 = 0;
}