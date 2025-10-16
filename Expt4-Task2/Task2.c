// S Avaneeth
// NNM24EE092
// Blink first and second LED alternately with a 1 second delay
#include <MicroLABlet.h> 
void main(void) 
{  
  P2=0x00;      
  while(1)                                  
  { 
    P2=0x80;  
    delay(1000);
    P2=0x40;  
    delay(1000);   
  }
}		 