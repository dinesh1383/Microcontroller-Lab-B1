// Name:Prashasth K
// USN:NNM24EE083
#include <reg51.h>
unsigned char array[5]={0x01,0xA1,0x1A,0x31,0xD2};
unsigned char temp_variable=0x00,count,array_length;
void main(void)
{
	P2=0x00;
	array_length=sizeof (array)/sizeof (char);
		for(count=0; count<array_length; count++)
	{
		if(array[count]>temp_variable)
		{
			temp_variable=array[count];
		}
		}
		P2=temp_variable;
	}

