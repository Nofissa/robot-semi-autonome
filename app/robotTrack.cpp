#include "robotTrack.h"

volatile uint8_t gCurrentState = 0;

void delayms(uint8_t delay)
{
    for (uint8_t i = 0; i < delay; i++)
    {
        _delay_ms(1);
    }
}

void playSong()
{
    int tempo = 200;
    char notes[] = "eeeeeeegcde fffffeeeeddedg";
    int duration[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

  
        char notesName[] = {'c', 'd', 'e', 'f', 'g'};
        int tones[] = {60, 62, 64, 65, 67};
    

    // Scan each char from "notes"
    for (int j = 0;j<26; j++)
    {
        if (notes[j] == ' ')
        {
            // If find a space it rests
            arreterSon();
        delayms(duration[j] * tempo);
        }
        else
        {
            for (int i = 0; i<5; i++)
            {
                // Bind the note took from the char array to the array notesName
                if (notes[j] == notesName[i])
                {
                    // Bind the notesName to tones
                    initialiserSon(tones[i]);
                    delayms(duration[j] * tempo);
                }
            }
            
        }

        // Pauses between notes
        arreterSon();
        delayms((tempo * 2) * duration[j]);
    }
}

bool isDeviatedRight(uint8_t lineSensor)
{
    return lineSensor == DEVIATED_RIGHT1 ||
           lineSensor == DEVIATED_RIGHT2 ||
           lineSensor == DEVIATED_RIGHT3;
}
bool isDeviatedLeft(uint8_t lineSensor)
{
    return lineSensor == DEVIATED_LEFT1 ||
           lineSensor == DEVIATED_LEFT2 ||
           lineSensor == DEVIATED_LEFT3;
}
bool isGoingStraight(uint8_t lineSensor)
{
    return lineSensor == GOING_STRAIGHT1 ||
           lineSensor == GOING_STRAIGHT2 ||
           lineSensor == GOING_STRAIGHT3 ||
           lineSensor == GOING_STRAIGHT4;
}
bool isAtIntersection(uint8_t lineSensor)
{
    return lineSensor == INTERSECTION1 ||
           lineSensor == INTERSECTION2 ||
           lineSensor == INTERSECTION3 ||
           lineSensor == INTERSECTION4 ||
           lineSensor == INTERSECTION5 ||
           lineSensor == INTERSECTION6 ||
           lineSensor == INTERSECTION7 ||
           lineSensor == INTERSECTION8 ||
           lineSensor == INTERSECTION9 ||
           lineSensor == INTERSECTION10 ||
           lineSensor == INTERSECTION11 ||
           lineSensor == INTERSECTION12;
}

void partirMinuterie()
{
    TCCR1B |= _BV(WGM12) | _BV(CS12) | _BV(CS10);
}

void switchState(STATES &state)
{
    switch (state)
    {
    case PARTIEA:
        state = PARTIEB;
        gCurrentState = 1;
        break;
    case PARTIEB:
        state = PARTIES;
        gCurrentState = 2;
        break;
    case PARTIES:
        state = PARTIEA;
        gCurrentState = 0;
        break;
    }
}

void doStateTask(const STATES &state, Led &led)
{
    switch (state)
    {
    case PARTIEA:
        led.setLedGreen();
        break;
    case PARTIEB:
        led.setLedRed();
        break;
    case PARTIES:
        led.setLedAmber();
        break;
    }
}

void flashColourOnce(const STATES &state, Led &led)
{
    switch (state)
    {
    case PARTIEA:
        led.setLedGreen();
        _delay_ms(125);
        break;
    case PARTIEB:
        led.setLedRed();
        _delay_ms(125);
        break;
    case PARTIES:
        for (uint8_t i = 0; i < 10; i++)
        {
            led.setLedAmber();
        }
        break;
    }
}
void selectMode(STATES &currentState, Led &led)
{

    doStateTask(currentState, led);

    while (!isButtonPressed())
    {
        doStateTask(currentState, led);
        if (isBreadboardButtonPressed())
        {
            switchState(currentState);
        }
        while (isBreadboardButtonPressed())
        {
            doStateTask(currentState, led);
        }
    }
}
void flashingSequence(STATES &currentState, Led &led)
{

    for (uint8_t i = 0; i < 8; i++)
    {
        led.setLedOff();
        _delay_ms(125);
        flashColourOnce(currentState, led);
    }
    led.setLedOff();
}

void turnRight(Motor motor)
{
    motor.turnRight();
    _delay_ms(600);
}

void memoryAccessDelay()
{
    _delay_ms(5);
}

bool isPoleClose(uint8_t distance)
{
    return distance <= 66 && distance >= 40;
}
bool isPoleFar(uint8_t distance)
{
    return distance <= 30 && distance >= 18;
}
void makePoleNoise(uint8_t proximity)
{
    switch (proximity)
    {
    case CLOSE:
        initialiserSon(80);
        _delay_ms(1000);
        arreterSon();
        break;
    case FAR:
        initialiserSon(45);
        _delay_ms(1000);
        arreterSon();
    }
}
uint8_t getDistance(can &myCan)
{
    uint8_t distance;
    distance = (myCan.lecture(PA0) >> 2);
    return distance;
}

bool isPartieB()
{
    return gCurrentState == 1;
}
bool isPartieS()
{
    return gCurrentState == 2;
}

