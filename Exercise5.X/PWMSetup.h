/* 
 * File:   PWMSetup.h
 * Author: adamp
 *
 * Created on November 16, 2018, 10:24 AM
 */

// Define the maximum value of the PWM duty cycle register, for easy reference
#define maxDC (2*(PTPER + 1))

void configurePWM();
void changeDC();