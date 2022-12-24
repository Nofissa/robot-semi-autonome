#include "breadboardbutton.h"
bool isBreadboardButtonPinOn()
{
    return !(PIND & BREADBOARDBUTTON_PIN);
}
void setBreadboardButtonPinIn()
{
    DDRD &= !_BV(BREADBOARDBUTTON_PIN_NUMBER);
}
bool isBreadboardButtonPressed()
{
    if (isBreadboardButtonPinOn())
    {
        _delay_ms(DEBOUNCE_DELAY1);
        return (isBreadboardButtonPinOn());
    }
    return false;
}

bool isBreadboardButtonReleased()
{
    if (!(isBreadboardButtonPinOn()))
    {
        _delay_ms(DEBOUNCE_DELAY1);
        return (!(isBreadboardButtonPinOn()));
    }
    return false;
}