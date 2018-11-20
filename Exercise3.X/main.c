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
        for( j = 0; j < 2000; j++){ }
    }
}

int main() {
    
    gpIOSetup();    
    ledSetup();
    
    while(1){
        myDelay(1);
    }
    return 0;
}

