# Digital I/O

- pins are shared between several peripherals
- example when PWM1 peripheral is enabled you cannot use pin 37 and 38 as digital I/o
- disable peripheral if you want to use pin as digital I/O

## Control a port PIN
- **TRIS**
    - 0: port as output
    - 1: port as input (default)
- **PORT**
    - **READ**: logic state of the pin after the Schmitt trigger
    - WRITE: controller will actually set the latch (**LAT**)
- **LATCH**
    - **WRITE**
    - always has the state you have set it to


![demo screenshot](pics/pins.png)
![demo screenshot](pics/structure.png)
![demo screenshot](pics/struct_indi.png)

## I/O Programming
- operations performed by READ and WRITE to **SFRs** associated with the digital I/O pin
- all I/O ports organized in groups of 16 (A,B,C etc.)
- registers are called **TRISD, PORTD and LATD** for port D
- shared port D only controls 4 pins despite having 16x3 bits

![demo portd](pics/portd.png)

- to set tristate bit for bit 2 of port D:
    - TRISDbits.TRISD2 = 1
    - use &, | and a mask in C to set individual bits

## Analogue Side of Digital Ports
|                               | max
| ----------------------------- |:----:|
| current by any I/O pin        | 25 mA|
| combined current by all ports | 200mA|
| current of V_dd and V_ss pins | 250mA|
| voltage on any pin w.r.t. to V_ss | -0.3 V .. V_dd + 0.3V
| clamping current              | 20mA

## Exercises
1. Write down based on the circuit diagram, which pins/registers are used as inputs and outputs for
    - **S3, LED2, LED3 and LED4**.
2. Create **IOSetup.c and IOSetup.h** and add them to your project.
    - Write a function in IOSetup.c that configures the I/Os for S3, LED2, LED3 and LED4 as inputs and outputs respectively.
    - Declare this function in **IOSetup.h** and also #define the inputs and outputs:
        - e.g. **#define LED2Latch LATDbits.LATD1**
3. Include IOSetup.h in main.c. Write a while(1) loop in main.c. In this while(1) loop, continuously read the switch S3 and switch on LED2 when the switch is pressed
4. Implement toggle functionality. When S3 is pressed the first time, LED2 is switched on. Is debouncing required?
5. Write a debouncing function. The function should measure the state of the switch S3 10x with 1 ms between samples. It should return a logic '1' only if all ten samples are '1'. Otherwise the function returns '0'. Use the output of this function to switch or toggle LED2
6. Toggle LED3 automatically with a rate of 5Hz when S3 is pressed. Measure this output with the scope to verify its accuracy. Take a screenshot for your log-book.
7. Implement the following two main() functions, observe the behaviour on
the target and explain what happens. You can either use the port names
as shown below or (better) use your own definition of the outputs as shown
in the #define example above. Hint:take a closer look at the instruction
cycle, consider the read-modify-write problem.

```C
    a)

        int main(void){
            gpIOSetup();
            PORTDbits.RD3=1; //sets LED3 port bit, you may use LED3Port=1;
            PORTDbits.RD1=1; //sets LED2 port bit, you may use LED2Port=1;
            while(1);
                return 0; //we should never really return
        };

    b)

        int main(void)
        {
            gpIOSetup();
            LATDbits.LATD3=1; //sets the LED3 latch, you may use LED3Latch=1;
            LATDbits.LATD1=1; //sets the LED2 latch, you may use LED2Latch=1;
        }
```
