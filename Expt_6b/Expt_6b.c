// S Avaneeth
// NNM24EE092
// To display key value in LCD
#include <MicroLABlet.h> 
unsigned char message_one[ ] = {" press any key "};  
unsigned char message_two[ ] = {" key value is= "};  
unsigned char ascii[ ]={"0123456789ABCDEF"};  
void main( ) 
{ 
  unsigned char key_value,charactor_count; 
  LCD_Initialization ( ); 
  while(message_one[charactor_count]!='\0') 
  { 
    LCD_message_write(message_one[charactor_count]); 
    charactor_count++; 
  } 
  charactor_count=0; 
  LCD_command_write(0XC0); 
  while(message_one[charactor_count]!='\0') 
  { 
    LCD_message_write(message_two[charactor_count]); 
    charactor_count++; 
  } 
  while(1) 
  { 
    key_value=readkey( ); 
    LCD_command_write (0XCE); 
    LCD_message_write (ascii[key_value]); 
    while(key_value== readkey ( )); 
  } 
}