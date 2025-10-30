#include <MicroLABlet.h>

sbit ADC_start = P2^6;
sbit ADC_end_of_conversion = P2^7;
sbit ADC_output_enable = P2^5;

#define ADC_data P0
#define declare_output_port 0x00
#define declare_input_port 0xFF

unsigned char ADC_value;
unsigned char read_ADC();
unsigned char charactor_count;
void _nop_(void);

unsigned char message_one[] = {"ADC I/P Voltage"};
unsigned char message_two[] = {"= V    "};  // Space for fractional digits
unsigned char ascii[] = "0123456789";

void main(void)
{
    unsigned char ADC_output;
    float voltage;
    unsigned char int_part, frac1, frac2;

    ADC_data = declare_input_port;
    P2 = declare_output_port;
    ADC_start = 0;
    ADC_end_of_conversion = 1;
    ADC_output_enable = 0;

    LCD_Initialization();
    LCD_command_write(0x80);  // First line
    while (message_one[charactor_count] != '\0') {
        LCD_message_write(message_one[charactor_count]);
        charactor_count++;
    }

    charactor_count = 0;
    LCD_command_write(0xC0);  // Second line
    while (message_two[charactor_count] != '\0') {
        LCD_message_write(message_two[charactor_count]);
        charactor_count++;
    }

    while (1) {
        ADC_output = read_ADC();
        voltage = (ADC_output * 5.0) / 255.0;  // Convert to voltage

        int_part = (unsigned char)voltage;
        frac1 = (unsigned char)((voltage - int_part) * 10);
        frac2 = (unsigned char)(((voltage - int_part) * 100)) % 10;

        LCD_command_write(0xC8);  // Position after '='
        LCD_message_write(ascii[int_part]);
        LCD_message_write('.');
        LCD_message_write(ascii[frac1]);
        LCD_message_write(ascii[frac2]);
    }
}

unsigned char read_ADC()
{
    ADC_start = 1;
    _nop_(); _nop_(); _nop_(); _nop_();
    ADC_start = 0;
    _nop_(); _nop_(); _nop_();
    while (ADC_end_of_conversion == 1);
    ADC_output_enable = 1;
    _nop_(); _nop_(); _nop_(); _nop_();
    ADC_value = ADC_data;
    ADC_output_enable = 0;
    _nop_(); _nop_(); _nop_(); _nop_();
    return ADC_value;
}