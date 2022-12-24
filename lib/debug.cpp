#include "debug.h"

void printMessage(uint8_t data[], uint8_t nCaracters)
{
    for (int i = 0; i < nCaracters; ++i)
    {
        transmissionUART(data[i]);
    }
}