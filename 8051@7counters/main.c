#include <REGX52.H>

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    P2_0 = 0;        // Turn off LED initially
    TMOD = 0x05;     // Timer0 in Mode 1, counter mode (GATE=0, C/T=1)
    TH0 = 0;         // Clear counter high byte
    TL0 = 0;         // Clear counter low byte
    TR0 = 1;         // Start Timer0 (counter mode)

    while(1)
    {
        unsigned int counterValue = (TH0 << 8) | TL0;

        if(counterValue >= 5)  // After 5 pulses
        {
            P2_0 = 1;          // Turn on LED
            delay_ms(500);
            P2_0 = 0;
            delay_ms(500);
            TH0 = 0;           // Reset counter
            TL0 = 0;
        }
    }
}

/*
#include <REGX52.H>

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    unsigned int count = 0;
    P3_2 = 1;     // Make P3.2 input with internal pull-up
    P2_0 = 0;     // Initially turn off LED

    while(1)
    {
        if(P3_2 == 0)  // Button pressed
        {
            delay_ms(20);  // Debounce
            if(P3_2 == 0)
            {
                count++;
                while(P3_2 == 0);  // Wait for release
            }
        }

        if(count >= 5)
        {
            P2_0 = 1;  // Blink LED
            delay_ms(500);
            P2_0 = 0;
            delay_ms(500);
            count = 0;  // Reset count
        }
    }
}
*/