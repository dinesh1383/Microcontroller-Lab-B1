// S Avaneeth
// NNM24EE092
// LED blinking for 100ms
#include <MicroLABlet.h>
void main(void) 
{  
 P2=0x00;      
 while(1)                                  
 { 
  P2=0xaa;  
  delay(1000); 
  P2=0x55;  
  delay(1000);   
 }
}