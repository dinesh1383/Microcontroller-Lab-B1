// S Avaneeth
// NNM24EE092
// Serial Communication with relay and buzzer interfacing
#include <MicroLABlet.h> 
unsigned char control,charactor_count; 
sbit buzzer=P3^5;
sbit relay=P2^0;
void main(void) 
{ 
  unsigned char Message[ ]="NMAM Institute of Technology"; 
  buzzer=0;  //output port 
  buzzer=1;  //disable buzzer 
  relay=0;  //output port 
  relay=1;  //disable relay 
  TMOD=0x20;   //Timer 1 Mode 2 
  TH1=0xFD;   //9600 Baud rate 
  SCON=0x50;   //Serial Mode 1 
  TR1=1;      
  for (charactor_count=0;charactor_count<=12;charactor_count++) 
  { 
    SBUF=Message[charactor_count]; //Each charactor of message to be transferred serially  
    while(TI==0); 
    TI=0; 
  } 
  while(1) 
  { 
    while(RI==0); 
    control=SBUF; 
    RI=0; 
    if (control=='B')   //To turn ON Buzzer 
    {  
      buzzer=0; 
    } 
    if (control=='R')   //To turn ON Relay 
    { 
      relay=0; 
    }  
    if (control=='O')   //To turn off Buzzer and Relay 
    { 
      relay=1; 
      buzzer=1; 
    } 
  }  
}