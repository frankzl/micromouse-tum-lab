/* 
 * File:   UARTSetup.h
 * Author: Natalia
 *
 * Created on 30 November 2018, 14:06
 */

#ifndef UARTSETUP_H
#define	UARTSETUP_H

#include <p30F4012.h>

void uartSetup();
void uartSendChar(char sending_value);
void WriteUART1 (char data);
void WriteStringUART1(const char * s);

void interpret( char* s);

#endif	/* UARTSETUP_H */

