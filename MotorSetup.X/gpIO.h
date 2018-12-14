/* 
 * File:   gpIO.h
 * Author: Rene
 *
 * Created on 23 November 2018, 15:21
 */

#ifndef GPIO_H
#define	GPIO_H

#include "xc.h"

#endif	/* GPIO_H */

#define LED2 PORTDBITS.RD1
#define LED2Latch LATDbits.LATD1
#define LED3Latch LATDbits.LATD0

void gpIOSetup();