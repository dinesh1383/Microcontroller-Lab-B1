// S Avaneeth
// NNM24EE092
// To display up and down counter in seven segment display based on switches SW1 and SW2
#include <MicroLABlet.h> 
#define declare_output_port 0x00 
#define declare_input_port 0xFF 
sbit buzzer_control = P3^5; 
sbit key1=P3^4;
sbit key2=P3^3; 
void display(unsigned char display_value); 
void main(void) 
{ 
  unsigned char array_counter=0,flag=0; 
  P1=declare_output_port;  
  key1 = 1; 
  key2 = 1; 	
  buzzer_control = 0;
  buzzer_control = 1;
  while(1) 
  { 
    if(key1==1|key2==0)   
    {  
      break; 
    } 
  } 
  while(1)        
  {  
    if (key1==1) 
    {  
      flag=1; 
    } 
    if (key2==0) 
    { 
      flag=0; 
    } 
    if(flag==1) 
    {  
      array_counter++; 
      if (array_counter>10) 
      { 
				array_counter=0; 
      } 
    }   
    if(flag==0) 
    {   
      array_counter--; 
      if(array_counter==0xff) 
      { 
        array_counter=10; 
      } 
    }     
    display(array_counter);    
  }  
}  