#include "pwm.h"

void setPwmLeftWheel(uint8_t speed)
{
    OCR0A = speed;
    TCCR0A |= _BV(WGM00) | _BV(COM0A1);
    TCCR0A &= ~_BV(COM0A0);
    TCCR0B |= _BV(CS01);
}

void setPwmRightWheel(uint8_t speed)
{
    OCR0B = speed;
    TCCR0A |= _BV(WGM00) | _BV(COM0B1);
    TCCR0A &= ~_BV(COM0B0);
    TCCR0B |= _BV(CS01);
}

void setPwmBothWheels(uint8_t speed)
{
    setPwmLeftWheel(speed);
    setPwmRightWheel(speed);
}