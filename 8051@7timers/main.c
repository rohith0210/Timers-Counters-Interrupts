#include<regx52.h>

void delay_50ms();

void main(){
   P2_0 = 0;
   TMOD = 0x01;
   
   while(1){
    int i;
	for(i = 0;i <20;i++){
	  delay_50ms();
	}
	 P2_0 = ~ P2_0 ;
   }
}
/*void main(){
	while(1){
  P2 = 0xFF;
	delay_50ms();
	P2 = 0x00;
	delay_50ms();
	}
}another way to represent the main function
*/
void delay_50ms(){
    TH0 = 0xFC; //better change to visible exact blinking !!
	TL0 = 0x66;	
	TF0 = 0;
	TR0 = 1;
	
	while(TF0 == 0);
	
	TR0 = 0;
	TF0 = 0;

}