/*
 * File:   initIO.c
 * Author: a2-lenz
 *
 * Created on May 8, 2018, 11:30 AM
 */


#include "initIO.h"

void initIO() {
    int i;

    // set up analogue pins
    AD1CON1bits.ADON = 0; // disable ADC1 module
   // AD1PCFGL = 0xffCf; //0b1111 1111 1100 1111; 		//  AN4 and AN5 are analog inputs

    // set digital port direction
    // inputs
    //all pins are inputs by default

    //outputs
    TRISAbits.TRISA4=0; //LED0 is output
    TRISBbits.TRISB14=0; //DIR_A_1 output pin for H-Bridge Motor 1
    TRISBbits.TRISB7=0;// DIR_B_1 output pin for H-Brdige Motor1 
    
    TRISBbits.TRISB13=0; //DIR_A_2 for Motor 2
    TRISBbits.TRISB12=0; //DIR_B_2 for Motor 2
    
    TRISBbits.TRISB2 = 0; //UART TX on RP2 , Pin 6
    TRISBbits.TRISB1 = 1; //UART RX on RP1 , Pin 5
    //specifically define some inputs


    // set up remappable pins
    __builtin_write_OSCCONL(OSCCON & 0xbf); // clear bit 6 (unlock, they are usually write protected)
    // inputs
     // input pin mappig example below:, here you choose the register with the device and assign an remappable pin
    //RPINR14bits.QEA1R = 8; // QEI1 A to pin RB8
    RPINR14bits.QEA1R = 11; // QEI1 A to pin RB11
    RPINR14bits.QEB1R = 10; // QEI1 B to pin RB10
    
    RPINR16bits.QEA2R = 3; //QEI2 A to pin RB3 (used to be TAST input with switch, resolder )
    RPINR16bits.QEB2R = 8;//QEI2 B to pin RB8
    
    RPINR18bits.U1RXR = 1 ; //U1RX register is pin RB1 / RP1
    
    // outputs
    //output pin mapping example below, here you choose the pin register and then map it to a device 
     //RPOR6bits.RP12R = 0b00111; // pin RB12 to SPI1 miso (the cod 0b00111 idetifies SPI miso, table in datasheet)  
    RPOR1bits.RP2R = 0b00011; // pin RP2 is connected to UART1 TX, for coding see table 11-2 in datasheet
    //end of set up of remappable pins
    __builtin_write_OSCCONL(OSCCON | 0x40); // Lock PPS registers (lock again!)


    for (i = 0; i < 30000; i++); // short delay
}

