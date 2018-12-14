#ifndef PWM1FUNCTIONS_H
#define	PWM1FUNCTIONS_H

#include "xc.h"

// Define the maximum value of the PWM duty cycle register, for easy reference
#define maxDC1 (2*(PTPER + 1))

void pwm1Setup();
void changeDC();
#endif	/* PWM1FUNCTIONS_H */