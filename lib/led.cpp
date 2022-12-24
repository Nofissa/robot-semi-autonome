#include "led.h"

Led::Led(volatile uint8_t *port, uint8_t positiveLedPin, uint8_t negativeLedPin)
{
    _port = port;
    _positiveLedPin = positiveLedPin;
    _negativeLedPin = negativeLedPin;
    initializePort();
}

Led::Led()
{
    _port = nullptr;
}

void Led::initializePort()
{
    if (*_port == PORTA)
    {
        DDRA |= ((1 << _negativeLedPin) | (1 << _positiveLedPin));
    }
    else if (*_port == PORTB)
    {
        DDRB |= ((1 << _negativeLedPin) | (1 << _positiveLedPin));
    }
    else if (*_port == PORTC)
    {
        DDRC |= ((1 << _negativeLedPin) | (1 << _positiveLedPin));
    }
    else
        DDRD |= ((1 << _negativeLedPin) | (1 << _positiveLedPin));
}

bool Led::isPortAssigned()
{
    if (_port == nullptr)
    {
        return false;
    }
    return true;
}

void Led::setPort(volatile uint8_t *port)
{
    _port = port;
}

volatile uint8_t *Led::getPort()
{
    return _port;
}

void Led::setPositiveLedPin(uint8_t positiveLedPin)
{
    _positiveLedPin = positiveLedPin;
}

uint8_t Led::getPositiveLedPin()
{
    return _positiveLedPin;
}

void Led::setNegativeLedPin(uint8_t negativeLedPin)
{
    _negativeLedPin = negativeLedPin;
}

uint8_t Led::getNegativeLedPin()
{
    return _negativeLedPin;
}

void Led::setLedRed()
{
    if (isPortAssigned())
    {
        *_port &= ~_BV(_positiveLedPin);
        *_port |= _BV(_negativeLedPin);
    }
}

void Led::setLedGreen()
{
    if (isPortAssigned())
    {
        *_port |= _BV(_positiveLedPin);
        *_port &= ~_BV(_negativeLedPin);
    }
}

void Led::setLedOff()
{
    *_port &= ~(_BV(_positiveLedPin) | _BV(_negativeLedPin));
}

void Led::setLedAmber()
{
    if (isPortAssigned())
    {
        setLedRed();
        _delay_ms(DELAY_RED_FOR_AMBER);
        setLedGreen();
        _delay_ms(DELAY_GREEN_FOR_AMBER);
    }
}