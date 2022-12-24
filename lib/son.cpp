#include <avr/io.h>
#include "son.h"
#include "timer.h"

void initialiserSon(uint8_t operande)
{
    DDRD |= (1 << PD4) | (1 << PD5);
    PORTD &= ~(1 << PD4);

    const float tableauFrequences[nElementsTableau_] = {0.11000, 0.11654, 0.12347, 0.13081,
                                                        0.13859, 0.14683, 0.15556, 0.16481,
                                                        0.17461, 0.18500, 0.19600, 0.20765,
                                                        0.22000, 0.23308, 0.24694, 0.26163,
                                                        0.27718, 0.29366, 0.31113, 0.32963,
                                                        0.34923, 0.36999, 0.39200, 0.41530,
                                                        0.44000, 0.46616, 0.49388, 0.52325,
                                                        0.55437, 0.58733, 0.62225, 0.65926,
                                                        0.69846, 0.73999, 0.78399, 0.83061,
                                                        0.88000};

    float tableauNotes[nElementsTableau_] = {};

    for (uint8_t i = 0; i < nElementsTableau_; i++)
    {
        // OCRNA = (8000/x - 512) * (1/512) ...(x = frequence ocrnx)
        tableauNotes[i] = ((8000 - (512 * tableauFrequences[i])) / (512 * tableauFrequences[i]));
    }

    TCNT1 = 0;
    TCCR1A |= (1 << COM1A0);
    TCCR1B |= (1 << CS12);
    TCCR1B |= (1 << WGM12);
    TCCR1C = 0;
    OCR1A = tableauNotes[operande - premiereValeure_];
}

void arreterSon()
{
   // DDRD = 0x00;
    TCNT1 = 0;
    OCR1A = 0;
    TCCR1A = 0;
    TCCR1B = 0;
    OCR1B = 0;
    TIMSK1 = 0;
}
