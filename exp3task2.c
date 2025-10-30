 //Rakshith
//NNM24EE086
#include <MicroLABlet.h>
sbit LED1=P2^0;
sbit LED2=P2^1;
void main(void)
{
    while(1)
    {
        LED1=1;
        LED2=0;
        delay(1000);
        LED1=0;
        LED2=1;
        delay(1000);
    }
}
