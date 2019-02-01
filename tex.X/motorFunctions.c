#include <p30F4012.h>

#include "motorFunctions.h"

void motorSetup()
{
    //TRISBbits.TRISB2 = 0;
    //PORTBbits.RB2 = 1;
    
    // motor pins
    // direction A
    TRISBbits.TRISB2 = 0; 
    LATBbits.LATB2 = 1;
    // direction B
    TRISBbits.TRISB3 = 0;
    LATBbits.LATB3 = 0;
}


void setMotorDir( int direction )
{
    // save motor from burning
    LATBbits.LATB2 = 0;
    LATBbits.LATB3 = 0;

    // revert direction
    if ( direction == 1) {
        LATBbits.LATB2 = 0;
        LATBbits.LATB3 = 1;
    }
    else
    {
        LATBbits.LATB3 = 0;
        LATBbits.LATB2 = 1;
    }
}


void changeMotorDir()
{
    int dirA = LATBbits.LATB2;
    int dirB = LATBbits.LATB3;
    
    // save motor from burning
    LATBbits.LATB2 = 0;
    LATBbits.LATB3 = 0;

    // revert direction
    if (dirA == 1) {
        LATBbits.LATB2 = 0;
        LATBbits.LATB3 = 1;
    }
    else if(dirB == 1)
    {
        LATBbits.LATB3 = 0;
        LATBbits.LATB2 = 1;
    }
}
