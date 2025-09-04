//name:prashasth k
//usn:nnm24ee081
//date:21/08/2025
//title of exp:demonstration of various addressing modes and examining the practical implementation
#include <reg51.h>
unsigned char idata *R1=0x01, *internalmemory=0x44;
void main(void)
{
	ACC=0x66;
	*R1=ACC;
	ACC=* internalmemory;
}
