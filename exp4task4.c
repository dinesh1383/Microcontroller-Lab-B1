

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
void display(unsigned char display_value)
{
    unsigned char fps, higher_nibble, lower_nibble;
    
    // Convert 8-bit value into two 4-bit hexadecimal digits (0-F)
    higher_nibble = display_value >> 4;
    lower_nibble = display_value & 0x0F;

    // Multiplexing loop (as seen in Experiment 4a, inner loop)
    // Runs 51 times (0 to 50) with 10ms delay per digit for a 1 second hold time
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
    // Define the two 8-bit numbers
    unsigned char minuend = 0xAA;    // Example: 170
    unsigned char subtrahend = 0x4B; // Example: 75
    unsigned char difference;        // Stores 170 - 75 = 95 (0x5F)

    // Initialization (P1 for data, P3 for control)
    P1 = 0x00;
    disp1_control = 0;
    disp2_control = 0;
    buzzer_control = 1; // Disable buzzer

    // Calculate the difference. The result is stored as an 8-bit number.
    difference = minuend - subtrahend;

    while(1)
    {
        // 1. Display the Minuend (0xAA)
        display(minuend); 

        // 2. Display the Subtrahend (0x4B)
        display(subtrahend);

        // 3. Display the Difference (0x5F)
        display(difference);
    }
}