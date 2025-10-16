//S Avaneeth
//NNM24EE092
//This program is to find the largest number stored in an array and display the result in port2// 
#include <reg51.h> 
unsigned char array[5] ={0x01,0xa1,0x1a,0x31,0xd2}; 
unsigned char tempvariable=0x00, count, array_length;
void main(void) 
{ 
	P2=0x00;
  array_length=sizeof(array)/sizeof(char); 
  for(count=0; count<array_length; count++)  // to execute successive comparison of array data// 
  { 
    if (array[count]> tempvariable)       
    { 
      tempvariable=array[count]; 
    } 
  }  
  P2= tempvariable; 
} 