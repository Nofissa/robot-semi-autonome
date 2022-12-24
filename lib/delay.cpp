#include "delay.h"

void delayLoop(uint8_t nIterations)
{
	for (uint8_t i = 0; i < nIterations; ++i)
	{
		_delay_ms(DELAY_MULTIPLIER);
	}
}
