#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
#pragma once

void setPwmLeftWheel(uint8_t speed);
void setPwmRightWheel(uint8_t speed);
void setPwmBothWheels(uint8_t speed);
