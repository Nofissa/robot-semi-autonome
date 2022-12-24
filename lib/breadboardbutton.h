#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
const uint8_t DEBOUNCE_DELAY1 = 10;
const uint8_t BREADBOARDBUTTON_PIN = 0x08;
const uint8_t BREADBOARDBUTTON_PIN_NUMBER = 3;
void setBreadboardButtonPinIn();
bool isBreadboardButtonPressed();
bool isBreadboardButtonReleased();
bool isBreadboardButtonPinOn();
void initialisationInterruption(void);