# 5 - Pulse Width Modulation (PWM)

- PWM used to control the amount of energy supplied to an actuator
    - ex. light source or any other device when employing digital control systems
    - require fast switches
        - switches are FETs with a low R_DS(ON)
- amount of power supplied to a load = pulse width modulated

![alt pwm](demo/pwm_principle.png)

<img style="float: right;" src="demo/pwm_calc.png"/>

## Calculating
- calculate the average voltage by integrating over the time period T

- s_avg = (T_on x s + T_off x 0) / T

- s_avg = 1/T x T x DC = s_hat x DC

- if frequency too low:
    - load will follow the pulse
- if frequency too high: 
    - might generate large amount of electromagnetic interference with other systems
    - expect high transmission losses

## Choosing PWM period
- PWM choice influences amount of ripple in the resulting signal
- experiment: PWM source driving an RC load
    - we are trying to control the voltage on the capacitor

![alt demo](demo/pwm_exp.png)


<img style="float: right;" src="demo/pwm_process.png"/>

## PWM Signal Generation
- main elements: timer/counter and a comparator whose outputs drive the PWM signal
- controlling duty cycle by changing the value in the **duty cycle register**
1. PWM signal **ON**
2. comparator: counter value >= **PWM duty cycle value**
3. PWM signal **OFF**
4. counter >= **PWM period value**
5. **RESET** to 0

- differentiate between center or edge aligned PWM generation

## PWM generation: dsPIC30F4011
- 3x PWM generators
    - 6 pins operating as pairs
    - 3x PWMxL, PWMxH (low-side and high-side drivers)

## Exercise

