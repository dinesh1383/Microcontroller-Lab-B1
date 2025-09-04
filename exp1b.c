//Name:Rakshith
//NNM24EE086
//21-08-2025&Title:To familiarize logical and arithmetic instructions
#include <reg51.h>
unsigned char idata *internalmemory=0x60;
void main(void)
{
// logical AND to extract lower nibble of Accumulator and store result in internal memory
	ACC=0X78;
	*internalmemory=ACC&0x0f;
	*internalmemory++;  
// logical OR to add value 0xff to Accumulator and store result in internal memory//
ACC=0xf8;
*internalmemory=ACC|0xff;
*internalmemory++;
	// logical XOR to compliment bits of R4 and store result in internal memory//
*R4=0x55;
*internalmemory=*R4^0xff;
*internalmemory++;
	// logical NOT to compliment bits of Accumulator and store result in internal memory//
ACC=0x55;
*internalmemory=~ACC;
*internalmemory++;
// shift operation to extract higher nibble of Accumulator and store result in internal memory//
ACC=0x45;
*internalmemory=ACC&0xf0;
*internalmemory=*internalmemory >>4;
*internalmemory++;
// example of logical operation to SWAP nibble of variable and store result in internal memory//
variable=0xde;
temporary_variable=(variable &0x0f)<<4;
variable=(variable &0xf0)>>4;
*internalmemory=variable| temporary_variable;
}