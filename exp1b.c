// name:prashasth k
//usn:nnm24ee083
//21/08/2025 title:to familirize logical and arithmetic operations
#include<reg51.h>
unsigned char idata *internalmemory=0x60,*R4=0x55;
	void main(void)
	{
		//logical AND to extract lower nibble of Accumulator and store result in internal memory//
	ACC=0x78;
		*internalmemory=ACC&0x0f;
		*internalmemory++;
	//logical OR to add value 0xff to Accumulator and store result in internal memory//
ACC=0xe8;
*internalmemory=ACC|0xff;
*internalmemory++;
	 //logical XOR to compliment bits of R4 and store result in internal memory//

*internalmemory=*R4^0xff;
*internalmemory++;
//logical NOT to compliment bits of Accumulator and store result in internal memory//
ACC=0x55;
*internalmemory=~ACC;
*internalmemory++;	
	// shift operation to extract higher nibble of Accumulator and store result in internal memory//
ACC=0x45;
*internalmemory=ACC&0xf0;
*internalmemory=*internalmemory >>4;
*internalmemory++;
}

		