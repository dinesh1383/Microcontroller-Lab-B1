// S Avaneeth
// NNM24EE092
// To display digits from 00 to 10 up-counter in seven segment display
#include <MicroLABlet.h> 
#define declare_output_port 0x00 
#define enable 1 
#define disable 0 
sbit buzzer_control = P3^5; 
sbit disp1_control= P3^6 ; 
sbit disp2_control=P3^7 ; 
char array_counter, length, fps, higher_nibble, lower_nibble; 
void main(void)
{  
  unsigned char hexcode_digit[ ]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71}; 
  P1=declare_output_port; 
  disp1_control= 0;                                     
  disp2_control=0;      
  buzzer_control = 0;                
  buzzer_control = 1;                             
  while(1)        
  {  
    for (array_counter=0; array_counter<=10; array_counter++)
	  { 
      higher_nibble=array_counter/10; 
      lower_nibble=array_counter%10; 
      for(fps=0;fps<=50;fps++) 
      { 
        disp1_control=enable;   
        disp2_control=disable; 
        P1= hexcode_digit [higher_nibble];  
        delay(10); 
        disp1_control=disable; 
        disp2_control=enable;     
        P1= hexcode_digit [lower_nibble];  
        delay(10); 
      } 
    }     
	}  
 }      