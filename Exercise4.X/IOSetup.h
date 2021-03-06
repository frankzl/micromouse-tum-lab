// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> 

#define R1_LEDLatch LATDbits.LATD1
#define R1_LEDTristate TRISDbits.TRISD1
#define R1_LEDPort  PORTDbits.RD1

#define LED2Latch LATEbits.LATE0
#define LED2Tristate TRISEbits.TRISE0

void ledSetup();

void setLED_R1(int);

void gpIOSetup();

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

