#include "pwm1Functions.h"

void pwm1Setup() 
{
    // switch off PWM time base during configuration
    PTCONbits.PTEN = 0;
    
    // choose time base prescaler, options are 1:1, 1:4, 1:16, or 1:64
    PTCONbits.PTCKPS = 0b01; // choose 4
    
    /*
     * PTPER+1 gives the number of Tcycles
     * although counts only up to PTPER but 100% duty cycle (DC) value is 
     * double the amount 2x(PTPER+1)
     * 
     * choose prescaler=4 and period=15999 for 250Hz
     */
    // set the PWM period (15bit)
    PTPER = 15999;

    // set PWM unit 1 into the independent mode (use PWMCON1bits.PMOD1 =1)
    PWMCON1bits.PMOD1 = 1;
    
    // enable PWM 1 low-side driver, (connected to LED4)
    PWMCON1bits.PEN1L = 1;
    
    // enable PWM 1 high-side driver
    PWMCON1bits.PEN1H = 1;
    
    // switch on PWM time base
    PTCONbits.PTEN = 1;
}

void changeDC(void) 
{
    static int counter = 0;
    
    switch(counter % 4)
    {
        case 0:
            // 10% duty cycle
            PDC1 = (int)(0.1 * maxDC1);
            break;
        case 1:
            // 50% duty cycle
            PDC1 = (int)(0.25 * maxDC1);
            break;
        case 2:
            // 75% duty cycle
            PDC1 = (int)(0.50 * maxDC1);
            break;
        case 3:
            // 100% duty cycle
            PDC1 = maxDC1;
            break;
    }
    counter++;
}