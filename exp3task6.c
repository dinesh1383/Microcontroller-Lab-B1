

#include <MicroLABlet.h>
void main(void)
{
    unsigned char count;
    while(1)
    {
        for(count = 0xFF; count > 0x00; count--)
        {
            P2 = count;
            delay(100);
        }
        P2 = 0x00;
        delay(100);
    }
}