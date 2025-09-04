//Name:Rakshith
//USN:NNM24EE086
#include <reg51.h>
unsigned char data1=0xc7, data2=0xb2, sum, difference, quotient, remainder;
unsigned int product;
void main(void)
 {
// add two number and display sum in port2//
sum=data1+data2; //observe PSW //
P2=sum;
// to extract carry from PSW and display in port1//
P1=PSW>>7;
	 
 // subtract two number and display difference in port2//
difference=data1-data2; //observe PSW // 
P2=difference;
// to extract borrow from PSW and display in port1//
P1=PSW>>7;
 
 // multiply two number and display product in port1 and port2//
product=data1*data2; 
P2=product&0x00ff;//lower byte of product//
P1=product>>8;//higher byte of product//
 
	 // divide two number and display quotient and remainder in port1 and port2//
quotient=data1/data2; //observe PSW //
remainder=data1%data2;
P2=quotient;
P1=remainder;
}