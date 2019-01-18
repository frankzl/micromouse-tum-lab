/* 
 * File:   initIO.h
 * Author: a2-lenz
 *
 * Created on May 8, 2018, 11:31 AM
 */
#include "xc.h"
#ifndef INITIO_H
#define	INITIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LED0 LATAbits.LATA4
    
#define    DIR_A_1 LATBbits.LATB14 // output pin for H-Bridge Motor 1
#define    DIR_B_1 LATBbits.LATB7 // output pin for H-Brdige Motor1 
    
 #define   DIR_A_2 LATBbits.LATB13 //DIR_A_2 for Motor 2
 #define   DIR_B_2 LATBbits.LATB12 //DIR_B_2 for Motor 2
void initIO();

#ifdef	__cplusplus
}
#endif

#endif	/* INITIO_H */

