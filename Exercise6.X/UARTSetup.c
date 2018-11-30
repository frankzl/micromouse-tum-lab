
#include "UARTSetup.h"

void setupUART(){
    U1MODEbits.UARTEN = 0;
    
    // select the alternative
    U1MODEbits.ALTIO = 1;
    U1BRG = 1;
    U1MODEbits.LPBACK = 0;
    U1MODEbits.WAKE = 0;
    U1MODEbits.ABAUD = 0;
    U1MODEbits.PDSEL = 0;
    U1MODEbits.STSEL = 0;
    
    U1STAbits.URXISEL = 0b01;
    
    IFS0bits.U1RXIF = 0;
    IPC2bits.U1RXIP = 4;
    IEC0bits.U1RXIE = 1;
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
}


void sendChar(char character){
    U1TXREG = character;
}