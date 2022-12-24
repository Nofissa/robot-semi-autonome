#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
#include "pwm.h"
#pragma once

class Motor
{
public:
    Motor(uint8_t speed_);
    void turnLeft();
    void turnRight();
    void moveForward();
    void moveBackward();
    void setSpeed(uint8_t speed);
    void moveRightWheelBackward();
    uint8_t getSpeed();
    void stopMotors();

private:
    uint8_t WheelErrorPercentage_;
    uint8_t speed_;
};