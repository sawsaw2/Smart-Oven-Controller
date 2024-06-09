#include "keypad.h"
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void keypad_init(void)
{
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4);
    PORTD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4));
    DDRB &= ~((1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7));
    PORTB |= (1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7));
}

char keypad(void)
{
    // Function implementation...
}

uint16_t keypad_get_number(void)
{
    // Function implementation...
}
