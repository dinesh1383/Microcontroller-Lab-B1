//Name:Rakshith
//USN:NNM24EE086
//Date:21/08/2025
#include <reg51.h>
unsigned char idata *R1=0x01, *internalmemory=0x44;
void main(void)
{
	ACC=0x66;      
	*R1=ACC;
	ACC=*internalmemory;
}