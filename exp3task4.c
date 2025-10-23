

#include <MicroLABlet.h>
void main(void)
{
    unsigned char idata *number_ptr = 0x30;
    unsigned char check_value;
    *number_ptr = 0x55;
    check_value = *number_ptr;
    while(1)
    {
        if ((check_value & 0x01) == 0)
        {
            P2 = 0x0F;
        }
        else
        {
            P2 = 0xF0;
        }
    }
}