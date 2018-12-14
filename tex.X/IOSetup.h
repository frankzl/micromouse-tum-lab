/* 
 * File:   IOSetup.h
 * Author: Natalia
 *
 * Created on 09 November 2018, 13:13
 */

#ifndef IOSETUP_H
#define	IOSETUP_H

#include <xc.h>

#define LED2Latch LATDbits.LATD1
#define LED2Port  PORTDbits.RD1 // pin 14
//#define LED3Latch LATDbits.LATD3
//#define LED3Port  PORTDbits.RD3
#define LED2TRI TRISDbits.TRISD1 
//#define LED3TRI TRISDbits.TRISD3
#define LED1Latch LATDbits.LATD0
#define LED1Port  PORTDbits.RD0
//#define LED3Latch LATDbits.LATD3
//#define LED3Port  PORTDbits.RD3
#define LED1TRI TRISDbits.TRISD0

void gpIOSetup();

#endif	/* IOSETUP_H */


