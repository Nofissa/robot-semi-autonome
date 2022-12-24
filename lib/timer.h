#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>

class Timer
{
public:
   enum class Select
   {
      TIMER0,
      TIMER1,
      TIMER2,
   };

   Timer(Timer::Select selectTimer, uint8_t tccrnA, uint8_t tccrnB);
   ~Timer();

   void initializeTccrn(Timer::Select selectTimer, uint8_t tccrnA, uint8_t tccrnB);
   void setCompareVal(Timer::Select selectTimer, uint16_t compareVal);
   void setInterruptMask(Timer::Select selectTimer, uint8_t timerInteruptMask);
   void endTimer(Timer::Select selectTimer);
};

#endif