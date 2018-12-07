/* 
 * File:   main.c
 * Author: frankzl
 *
 * Created on November 20, 2018, 5:12 PM
 */

#include "IOSetup.h"

void myDelay(unsigned int timeInMilliseconds){
    int i;
    for( i = 0; i < timeInMilliseconds; i++){
        int j;
        for( j = 0; j < 500; j++){ }
    }
}

void toggleLED1(){
    setLED_R0(~R0_LEDLatch);
    //R0_LEDLatch = ~ R0_LEDLatch;
}

void toggleLED2(){
    //LED2Latch = ~ LEDLatch;
}

int main() {
    
    gpIOSetup();
    
    int frequency = 1;
    
    while(1){
        if(frequency == 50){
            frequency = 0;
        }
        myDelay(frequency);
        toggleLED1();
        myDelay(frequency);
        toggleLED2();
        frequency ++;

    }
    return 0;
}

