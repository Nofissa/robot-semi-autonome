#include "motor.h"

Motor::Motor(uint8_t speed)
{
    speed_ = speed;
}

void Motor::setSpeed(uint8_t speed)
{
    this->speed_ = speed;
}

uint8_t Motor::getSpeed()
{
    return this->speed_;
}

void Motor::turnLeft()
{
    stopMotors();
    setPwmRightWheel(speed_);
    DDRB |= _BV(PB4);
    PORTB &= ~_BV(PB5);
}

void Motor::turnRight()
{
    stopMotors();
    setPwmLeftWheel(speed_);
    DDRB |= _BV(PB3);
    PORTB &= ~_BV(PB2);
}

void Motor::moveForward()
{
    setPwmBothWheels(speed_);
    DDRB |= _BV(PB3) | _BV(PB4);
    PORTB &= ~(_BV(PB2) | _BV(PB5));
}

void Motor::moveBackward()
{
    setPwmBothWheels(speed_);
    DDRB |= _BV(PB2) | _BV(PB3) | _BV(PB4) | _BV(PB5);
    PORTB |= _BV(PB2) | _BV(PB5);
}


void Motor::moveRightWheelBackward()
{
    setPwmRightWheel(speed_);
    DDRB |= _BV(PB2) | _BV(PB3) | _BV(PB4) | _BV(PB5);
    PORTB |= _BV(PB2)| _BV(PB5);
}


void Motor::stopMotors()
{
    OCR0A = 0;
    OCR0B = 0;
}