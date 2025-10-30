//Rakshith
//NNM24EE086
#include <MicroLABlet.h>
void main(void)
{
    unsigned char data1=0x15;
    unsigned char data2=0x2A;
    unsigned char sum;
    sum = data1 + data2;
    P2 = sum;
    while(1);
}
