#include<regx52.h>



void delay_ms(unsigned int ms){
  unsigned int i,j;
	for(i = 0;i<ms;i++)
		for(j = 0;j<1275 ; j++);
}

void External0_ISR(void)interrupt 0{
  P1_0 = ~P1_0;
  delay_ms(200);	
}

void main(){
	P1_0 = 0;
  EA = 1;
	EX0 = 1;
	IT0 = 1;
  	
}






/*
#include <REGX52.H>

// Function to provide a delay
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

// Interrupt Service Routine for INT0
void External0_ISR(void) interrupt 0
{
    P1_0 = ~P1_0;     // Toggle LED on P1.0
    delay_ms(200);    // Simple delay for visible blink
}

void main()
{
    P1_0 = 0;        // Initialize LED OFF
    IT0 = 1;         // INT0 triggered on falling edge
    EX0 = 1;         // Enable External Interrupt 0
    EA = 1;          // Enable global interrupts

    while(1)
    {
        // Main loop does nothing, waits for interrupt
    }
}
*/