#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "keypad.h"
#include "motor.h"
#include "bake.h"
#include "utils.h"

int main(void)
{
    DDRA = 0xFF;
    DDRB = 0x00;
    PORTA = 0x00;
    PORTB = 0x00;
    DDRC = 0xFF;

    LCD_Init();
    keypad_init();
    Timer0_Init();
    Timer1_CTC_Init();

    LCD_String("Set Temp:  ");
    preset_temp = keypad_get_number();

    LCD_Clear();
    _delay_ms(2000);
    LCD_String("Set Time:  ");
    baking_time = keypad_get_number();
    bake();

    while (1)
    {
        while (baking_cycle_status)
        {
            control_temperature();
            check_door();
        }
        char temp_str[5];
        itoa(actual_temp[0], temp_str, 10);
        LCD_String_xy(0, 6, temp_str);
        itoa(baking_time, temp_str, 10);
        LCD_String_xy(1, 6, temp_str);

        OCR1A = 500;
        OCR1B = 250;
        _delay_ms(100);

        OCR1A = 375;
        OCR1B = 375;
        _delay_ms(100);

        OCR1A = 250;
        OCR1B = 500;
        _delay_ms(100);

        if (door_status == 0)
        {
            baking_cycle_status = 1;
        }
        else
        {
            baking_cycle_status = 0;
        }

        _delay_ms(1000);
    }
    return 0;
}
