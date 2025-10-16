// S Avaneeth
// NNM24EE092
// Blink fifth LED with a 1s delay between each state
#include <MicroLABlet.h> 
sbit fifth_LED=P2^4;  
void main(void) 
{  
  unsigned char count; 
  P2=0x00;                                  
  for(count=0;count<5;count++) 
  { 
    fifth_LED =1;   
    delay(1000); 
    fifth_LED =0;  
    delay(1000); 
  }
} 