//Rakshith
//NNM24EE086
#include <MicroLABlet.h>
#define enable 1
#define disable 0

// Based on Experiment 4a setup: P3.6 and P3.7 control the displays
sbit disp1_control = P3^6;
sbit disp2_control = P3^7;
sbit buzzer_control = P3^5; // Placeholder for unused peripheral control

// Hex codes for 0-F digits (from Table 2, page 37)
unsigned char hexcode_digit[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, // 0-7
    0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71  // 8-F
};

// Function to display an 8-bit hexadecimal value on the two 7-segment displays
// Loop count changed from 50 to 101 for a 2-second display time (102 * 20ms = 2040ms)
void display(unsigned char display_value)
{
    unsigned char fps, higher_nibble, lower_nibble;
    
    // Convert 8-bit value into two 4-bit hexadecimal digits (0-F)
    higher_nibble = display_value >> 4;
    lower_nibble = display_value & 0x0F;

    // Multiplexing loop for 2 second display duration (0.5 Hz)
    for(fps = 0; fps <= 101; fps++)
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
    // The first 8 Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13
    unsigned char fib_series[] = {0, 1, 1, 2, 3, 5, 8, 13};
    unsigned char index;

    // Initialization (P1 for data, P3 for control)
    P1 = 0x00;
    disp1_control = 0;
    disp2_control = 0;
    buzzer_control = 1; // Disable buzzer

    while(1)
    {
        // Iterate through the first 8 numbers of the array
        for (index = 0; index < 8; index++)
        {
            display(fib_series[index]);
        }
    }
}
