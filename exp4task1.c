//Rakshith
//NNM24EE086
#include <MicroLABlet.h>
#define enable 1
#define disable 0
sbit disp1_control = P3^6;
sbit disp2_control = P3^7;
sbit buzzer_control = P3^5; // Based on Experiment 4a setup

// Hex codes for 0-F digits (from Table 2, page 37)
unsigned char hexcode_digit[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, // 0-7
    0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71  // 8-F
};

void display(unsigned char display_value)
{
    unsigned char fps, higher_nibble, lower_nibble;
   
    // Extract the higher and lower nibbles (hexadecimal digits)
    higher_nibble = display_value >> 4;
    lower_nibble = display_value & 0x0F;
    // Multiplexing loop (as seen in Experiment 4a, inner loop)
    for(fps = 0; fps <= 50; fps++)
    {
        // Display High Nibble (Left Digit)
        disp1_control = enable;
        disp2_control = disable;
        P1 = hexcode_digit[higher_nibble];
        delay(10); 
        // Display Low Nibble (Right Digit)
        disp1_control = disable;
        disp2_control = enable;
        P1 = hexcode_digit[lower_nibble];
        delay(10);
    }
}

void main(void)
{
    unsigned char count;
    // Initialization (P1 for data, P3 for control)
    P1 = 0x00;
    disp1_control = 0;
    disp2_control = 0;
    buzzer_control = 1; // Disable buzzer (default in 4a, 4b)
    while(1)
    {
        // Loop from 0x00 to 0xFE, incrementing by 2 (even numbers only)
        for (count = 0x00; ; count += 2)
        {
            display(count);

            // Break the loop after 0xFE to restart at 0x00
            if (count == 0xFE)
            {
                break; 
            }
        }
    }
}
