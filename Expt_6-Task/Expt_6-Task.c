// S Avaneeth
// NNM24EE092
// To display the Name and USN in LCD 
#include <MicroLABlet.h> 
#define control_register 0x00 
#define data_register 0x01 
#define LCD_data P1 
#define declare_output_port 0X00 
sbit LCD_enable=P3^7; 
sbit LCD_register_select=P3^6; 
sbit buzzer_control=P3^5; 
unsigned char  message_one[ ]={ "   S AVANEETH   " }; 
unsigned char  message_two[ ]={ "   NNM24EE092   " }; 
void LCD_Initialization(); 
void LCD_message_write( char message_charactor); 
void LCD_command_write(char command_value); 
void main ( ) 
{ 
  char charactor_count; 
  P3=declare_output_port; 
  P1= declare_output_port; 
  buzzer_control=0; //output port 
  buzzer_control=1; //disable buzzer 
  LCD_Initialization( ); 
  LCD_command_write(0X80); 
  while(message_one[charactor_count]!='\0') 
  { 
    LCD_message_write(message_one[charactor_count]); 
    charactor_count++;  
  } 
  charactor_count=0; 
  LCD_command_write(0XC0); 
  while(message_two[charactor_count]!='\0')  
  { 
    LCD_message_write(message_two[charactor_count]); 
    charactor_count++; 
  } 
  while(1); 
}
void LCD_Initialization( ) 
{ 
  LCD_command_write(0X38); 
  LCD_command_write(0X10); 
  LCD_command_write(0X0C); 
  LCD_command_write(0X06); 
  LCD_command_write(0X01); 
} 
void LCD_command_write(char command_value) 
{  
  LCD_data= command_value; 
  LCD_register_select= control_register; 
  LCD_enable=1; 
  delay(10); 
  LCD_enable=0; 
  delay(10); 
} 
void LCD_message_write( char message_charactor) 
{  
  LCD_data= message_charactor; 
  LCD_register_select= data_register; 
  LCD_enable=1; 
  delay(10); 
  LCD_enable=0; 
  delay(10); 
}