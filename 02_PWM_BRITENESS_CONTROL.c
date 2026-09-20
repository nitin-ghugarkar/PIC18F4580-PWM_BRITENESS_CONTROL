#include <p18f4580.h>

//===========CONFIGURATION BITS =============/
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

void delay();

void main ()
{
    unsigned int duty;

    TRISCbits.RC2 = 0;   // RC2 (CCP1) as output

    ADCON1 = 0x0F;       // All pins digital

    //======== PWM Initialization ======/
    PR2 = 249;           // For ~1.25 kHz

    CCP1CON = 0x0C;      // PWM mode
    T2CON = 0x07;        // Timer2 ON, prescaler = 16

    while(1)
    {
        // Increase duty cycle (0% ? 100%)
        for(duty = 0; duty < 1023; duty++)
        {
            CCPR1L = duty >> 2;                 // Upper 8 bits
            CCP1CONbits.DC1B = duty & 0x03;     // Lower 2 bits
            delay();
        }

        // Decrease duty cycle (100% ? 0%)
        for(duty = 1023; duty > 0; duty--)
        {
            CCPR1L = duty >> 2;
            CCP1CONbits.DC1B = duty & 0x03;
            delay();
        }
    }
}

/* Simple delay */
void delay()
{
    int i, j;
    for(i=0; i<20; i++)
        for(j=0; j<50; j++);
}