# Exercise 2 - Cheat Sheet

In brief, we set up our dsPIC system as follows:
- external quartz oscillator with 8x PLL. This means with an external hardware oscillator of 8Mhz the controller will run on 64Mhz
- clock switching is off
- watchdog is disabled
- brown-out reset disabled
- master clear pin enabled
- power-on reset delay 64ms
- low-side PWM output is active high
