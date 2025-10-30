// S Avaneeth
// NNM24EE092
// To display digits key value in both seven segment displays when the corresponding key in hex keypad is pressed 
#include <MicroLABlet.h> 
#include <readkey.c> 
sbit buzzer_control = P3^5; 
unsigned char key_value=0, check ; 
void main ( ) 
{ 
  buzzer_control=0; //output port 
	P2=0x0F; //higher nibble output port and lower nibble input port 
  buzzer_control = 1; //disable buzzer 
  while(1) 
  {  
    P2=0x0F; 
    check=P2; 
    if(check!=0x0F) 
    { 
      key_value= readkey(); 
    } 
    display(key_value);  
  }    
}