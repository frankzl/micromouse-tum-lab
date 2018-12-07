#include "QEISetup.h"

void setupQEI(){
    ADPCFGbits.PCFG5    = 1;    // QEB on pin 7 shared with AN5
    ADPCFGbits.PCFG4    = 1;    // QEB on pin 6 shared with AN4
    
    QEICONbits.QEISIDL  = 1;    // Discontinue in inde mode
    QEICONbits.QEIM     = 0b11; // x4 edge gain and reset POSCNT when == MAXCNT
    QEICONbits.SWPAB    = 0;    // Do not swap the polarity of phase comparison
    QEICONbits.PCDOUT   = 0;    // Disable counter direction pin
    QEICONbits.POSRES   = 0;    // index pulse does not reset POSCNT
    QEICONbits.TQCS     = 0;    // internal clock source (Tcy)
    DFLTCONbits.QEOUT   = 0;    // disable digital filters
    
    MAXCNT              = 0xffff; //highest possible timeout
    POSCNT              = 0x7fff; //set POSCNT into middle of range

    IFS2bits.QEIIF      = 0;    // clear interrupt
    IEC2bits.QEIIE      = 1;    // enable QEI interrupt
    IPC10bits.QEIIP     = 5;    // QEI interrupt prio
}

void __attribute__((interrupt, auto_psv)) _QEIInterrupt(void)
{
    static counter = 0;
    
    IFS2bits.QEIIF      = 0;
    
    if( POSCNT < 32768 )
    {
        counter++;
    }
    else{
        counter--;
    }
}