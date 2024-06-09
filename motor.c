#include "motor.h"
#include <avr/io.h>

void motor_forward(void)
{
    PORTB |= (1 << MOTOR_PIN1);
    PORTB &= ~(1 << MOTOR_PIN2);
    PORTB |= (1 << MOTOR_ENABLE);
}

void motor_backward(void)
{
    PORTB &= ~(1 << MOTOR_PIN1);
    PORTB |= (1 << MOTOR_PIN2);
    PORTB |= (1 << MOTOR_ENABLE);
}

void motor_stop(void)
{
    PORTB &= ~(1 << MOTOR_ENABLE);
}
