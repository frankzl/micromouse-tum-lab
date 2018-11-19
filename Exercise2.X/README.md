# Exercise 2 - Cheat Sheet

In brief, we set up our dsPIC system as follows:
- external quartz oscillator with 8x PLL. This means with an external hardware oscillator of 8Mhz the controller will run on 64Mhz
- clock switching is off
- watchdog is disabled
- brown-out reset disabled
- master clear pin enabled
- power-on reset delay 64ms
- low-side PWM output is active high
- high-side PWM output is active low
- PWM pins are controller via the PWM module

<hr/>

## Questions ##

1. How can I watch a variable changing?
    - In the bottom menu there should be a tab named "variables" during the debug mode
2. How can I watch the special function registers (SFR)? What does the program counter do when I step through my program? How does this relate to the program memory?
    - Window > Target Memory Views > SFRs
3. How does my C-code translate into assembly code? Can I simulate assembly commands?
4. Set the simulator to 16MHz (Project Properties -> Simulator) and use the Stopwatch to measure how long it takes to complete the while loop.
    - Takes 437.5 ns
5. Can you work out how long one instruction cycle takes? How long does the increment command (i++) take? What is the relationship between the system frequency of 64MHz and the cycle frequency of 16MHz?
    - i++: 62.5 ns
6. Can you write a for-loop or a function that takes exactly 50ms to complete? Can you write a general purpose delay function based on this. For example, the function could have the following form: void myDelay(unsigned int timeInMilliseconds); .
