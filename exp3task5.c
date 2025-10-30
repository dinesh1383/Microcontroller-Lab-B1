//Rakshith
//NNM24EE086
#include <MicroLABlet.h>
void main(void)
{
    unsigned char count;
    while(1)
    {
        for(count = 0x00; count < 0xFF; count++)
        {
            P2 = count;
            delay(100);
        }
        P2 = 0xFF;
        delay(100);
    }
}
