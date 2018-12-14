/*
 * File:   uart1Functions.c
 * Author: René
 *
 * Created on 1. Dezember 2018, 22:36
 */

#include "gpIO.h"
#include "uart1Functions.h"

void UART1Setup(void) {
    // disable UART during config
    U1MODEbits.UARTEN = 0;
    
    // choose appropriate baud rate
    /*
     * BaudRate = 57,6 kbit/s
     * U1BRG = (16 * 10^6 / 16 * 57,6 * 10^3) - 1
     * U1BRG = (1000 / 57,6) - 1 = 16
     */
    U1BRG = 16; 
    
    // disable loopback mode, enable to test own interrupt without having a second UART
    // In this mode TX pin is internally connected to the RX pin
    U1MODEbits.LPBACK = 0;
    
    // do not wake-up on serial activity (don?t care)
    U1MODEbits.WAKE = 0;
    
    // no auto-baud detection
    U1MODEbits.ABAUD = 0;
    
    // 8 databits, no parity
    U1MODEbits.PDSEL = 0b00;
    
    // one stop bit
    U1MODEbits.STSEL = 0;
    
    // receive interrupt when 1 character arrives
    U1STAbits.URXISEL = 0b00;
    
    // clear rx interrupt flag
    IFS0bits.U1RXIF = 0;
    
    // set receive interrupt priority
    IPC2bits.U1RXIP = 6;
    
    // enable alternatvie IO (UIATX, PIN11 and RC13)
    U1MODEbits.ALTIO = 1;
    
    // enable receive interupts
    IEC0bits.U1RXIE = 1;
    
    // now, enable UART
    U1MODEbits.UARTEN = 1;
    
    // and enable transmission (order important)
    U1STAbits.UTXEN = 1;
}

void sendCharacter(char characterToSend) {
    // write character to RxRegister
    U1TXREG = characterToSend;
}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{
    // clear rx interrupt flag
    IFS0bits.U1RXIF = 0;
    
    LED2Latch = ~LED2Latch;
    // U1RXREG buffer gets full after 4 characters and stops interrupt getting called
}