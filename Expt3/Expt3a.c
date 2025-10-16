// S Avaneeth
// NNM24EE092
// Blinking LED array with 1s delay
#include <MicroLABlet.h> 
void main(void) 
{  
 P2=0x00;      
 while(1)                                  
  { 
  P2=0xf0;  
  delay(1000); //internal delay function of 1ms// 
  P2=0x00;  
  delay(1000);   
  }
}	