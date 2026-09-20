# PIC18F4580 PWM – Variable Duty Cycle Control

## Overview

This project demonstrates PWM (Pulse Width Modulation) using the PIC18F4580 microcontroller.

The PWM signal is generated using the CCP1 module on the RC2 pin. The duty cycle is gradually increased from 0% to 100% and then decreased back to 0%.

# Hardware Used

- PIC18F4580 Microcontroller
- RC2 / CCP1 pin for PWM output
- Crystal oscillator
- LED or other PWM-controlled load
- Proteus (for simulation)

# Working

- RC2 is configured as an output pin.
- CCP1 is configured in PWM mode.
- Timer2 is used as the PWM time base.
- PR2 is set to 249 for the PWM period.
- The PWM duty cycle uses a **10-bit value (0–1023).
- The upper 8 bits are loaded into CCPR1L.
- The lower 2 bits are configured using DC1B1:DC1B0 bits of CCP1CON.
- The duty cycle is continuously increased and decreased to demonstrate PWM control.

# PWM Duty Cycle

text
0% → 25% → 50% → 75% → 100%
100% → 75% → 50% → 25% → 0%


The changing duty cycle can be observed on the PWM output at RC2/CCP1.

## Important Registers

| Register | Purpose |
| TRISC | Configures RC2 as output |
| ADCON1 | Configures pins as digital |
| PR2 | Sets the PWM period |
| CCP1CON | Configures CCP1 in PWM mode and lower duty bits |
| CCPR1L | Stores the upper 8 bits of the PWM duty cycle |
| T2CON | Configures and enables Timer2 |

# Key Concept

The PIC18F4580 PWM module uses a 10-bit duty-cycle value:

c
CCPR1L = duty >> 2;
CCP1CONbits.DC1B = duty & 0x03;


This separates the 10-bit duty value into:

- Upper 8 bits → CCPR1L
- Lower 2 bits → DC1B1:DC1B0

This project helped me understand PWM generation, CCP modules, Timer2 configuration, duty-cycle control, and PIC18F4580 registers.
