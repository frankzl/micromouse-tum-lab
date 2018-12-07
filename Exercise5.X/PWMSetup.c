
//use the generic include file for XC16
#include "xc.h"
#include "PWMSetup.h"

// 1 channel PWM
void configurePWM()
{
    // switch off PWM time base during configuration
    PTCONbits.PTEN = 0;
    
    // choose prescaler=4 and period for 250Hz
    PTCONbits.PTCKPS = 0b01;
    PTPER = 15999;
      
    // set PWM unit 1 into the independent mode
    PWMCON1bits.PTMOD1;
    
    // enable PWM 1 low-side driver
    PWMCON1bits.PEN1L = 1;      
    
    // switch on PWM!
    PTCONbits.PTEN = 1;   
}

// Changes the duty cycle between 4 predefined values
void changeDC()
{
  
    static int index = 0; //for indexing  
    int temp = maxDC/100; //calculate once to save computations
    
    switch(index%4){
    case 0:
        PDC1 = 10*temp;
        break;
    case 1:
        PDC1 = 50*temp;
        break;
    case 2:
        PDC1 = 75*temp;
        break;
    case 3:
        PDC1 = maxDC;
        break;       
    }
    index++;
}