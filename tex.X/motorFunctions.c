#include <p30F4012.h>

#include "motorFunctions.h"
#include "pwm1Functions.h"

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

void motorDrive(int drive_level)
{
    //sanity check for drive_level
    if (drive_level > 100) drive_level = 100;
    if (drive_level < -100) drive_level = -100;
    
    //set driving direction to h-bridge and speed (duty cycle proportion) to PWM
    if (drive_level >= 0)
    {
        DIR_A = 1;
        DIR_B = 0;
        setDC(drive_level);
    }
    
    else
    {
        DIR_A = 0;
        DIR_B = 1;
        setDC(-1*drive_level);

    }
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
