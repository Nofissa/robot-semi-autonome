#include "timer.h"
Timer::Timer(Select selectTimer, uint8_t tccrnA, uint8_t tccrnB)
{
    initializeTccrn(selectTimer, tccrnA, tccrnB);
}
Timer::~Timer()
{
}
void Timer::setInterruptMask(Select selectTimer, uint8_t timerInteruptMask)
{
    switch (selectTimer)
    {
    case Select::TIMER0:
        TIMSK0 |= timerInteruptMask;
        break;
    case Select::TIMER1:
        TIMSK1 |= timerInteruptMask;
        break;
    case Select::TIMER2:
        TIMSK2 |= timerInteruptMask;
        break;
    }
}
void Timer::initializeTccrn(Select selectTimer, uint8_t tccrnA, uint8_t tccrnB)
{
    switch (selectTimer)
    {
    case Select::TIMER0:
        TCCR0A |= tccrnA;
        TCCR0B |= tccrnB;
        break;
    case Select::TIMER1:
        TCCR1A |= tccrnA;
        TCCR1B |= tccrnB;
        break;
    case Select::TIMER2:
        TCCR2A |= tccrnA;
        TCCR2B |= tccrnB;
    }
}
void Timer::setCompareVal(Select selectTimer, uint16_t compareVal)
{
    switch (selectTimer)
    {
    case Select::TIMER0:
        OCR0A = compareVal;
        TCNT0 = 0;
        break;
    case Select::TIMER1:
        OCR1A = compareVal;
        TCNT1 = 0;
        break;
    case Select::TIMER2:
        OCR2A = compareVal;
        TCNT2 = 0;
        break;
    }
}
void Timer::endTimer(Select selectTimer)
{
    switch (selectTimer)
    {
    case Select::TIMER0:
        TCCR0B =0;
        break;
    case Select::TIMER1:
        TCCR1B =0;
        break;
    case Select::TIMER2:
        TCCR2B =0;
    }
}