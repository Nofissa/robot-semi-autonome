#include "button.h"

bool isButtonPinOn()
{
    return ((PIND & BUTTON_PIN));
}

void setButtonPinIn()
{
    DDRD &= !_BV(BUTTON_PIN_NUMBER);
}

bool isButtonPressed()
{
    if (isButtonPinOn())
    {
        _delay_ms(DEBOUNCE_DELAY);
        return (isButtonPinOn());
    }
    return false;
}

bool isButtonReleased()
{
    if (!(isButtonPinOn()))
    {
        _delay_ms(DEBOUNCE_DELAY);
        return (!(isButtonPinOn()));
    }
    return false;
}