
#include "UARTSetup.h"


void setupUART(){
    U2MODEbits.UARTEN = 0;
    U2BRG = 1;
    U2MODEbits.LPBACK = 0;
    U2MODEbits.WAKE = 0;
    U2MODEbits.ABAUD = 0;
    U2MODEbits.PDSEL = 0;
    U2MODEbits.STSEL = 0;
    U1STAbits.URXISEL = 0b01;
    IFS1bits.U2RXIF = 0;
    IPC6bits.U2RXIP = 4;
    IEC1bits.U2RXIE = 1;
    U2MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
}
