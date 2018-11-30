/*
 * File:   main.c
 * Author: frankzl
 *
 * Created on November 30, 2018, 12:40 PM
 */


#include "xc.h"

void init_QEI(void)
{
// configure analogue pins as digital channels
ADPCFGbits.PCFG5
= 1;
// QEB on pin 7 shared with AN5
ADPCFGbits.PCFG4
= 1;
// QEA on pin 6 shared with AN4
// note: IND pin is not connected on firecracker board
// Configure QEI module
QEICONbits.QEISIDL = 1;
QEICONbits.QEIM = 0b111;
QEICONbits.SWPAB = 0;
QEICONbits.PCDOUT = 0;
QEICONbits.POSRES = 0;
QEICONbits.TQCS = 0;
DFLTCONbits.QEOUT = 0;

// set initial counter value and maximum range
MAXCNT = 0xffff; // set the highest possible time out
POSCNT = 0x7fff; // set POSCNT into middle of range

// Configure Interrupt controller
IFS2bits.QEIIF
= 0;
// clear interrupt flag
IEC2bits.QEIIE
= 1;
// enable QEI interrupt
IPC10bits.QEIIP
= 5;
// set QEI interrupt priority
}
// interrupt service routine
void __attribute__((interrupt, auto_psv)) _QEIInterrupt(void)
{
IFS2bits.QEIIF
= 0;
// clear interrupt flag
if(POSCNT<32768)
xx_xx++;
else
xx_xx--;
}
// over-run condition caused interrupt
// under-run condition caused interrupt
}

int main(void) {
    return 0;
}
