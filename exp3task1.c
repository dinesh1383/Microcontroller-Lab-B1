

#include <MicroLABlet.h>
sbit LED5=P2^4;
void main(void)
{
    while(1)
    {
        LED5=1;
        delay(1000);
        LED5=0;
        delay(1000);
    }
}