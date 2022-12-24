#include "partieA.h"
bool endPartieA = false;
void followLinePartieA(Motor motor)
{
    uint8_t lineSensor = PINC >> 3;
    if (isDeviatedRight(lineSensor))
    {
        motor.turnLeft();
    }
    else if (isDeviatedLeft(lineSensor))
    {
        motor.turnRight();
    }
    else if (isGoingStraight(lineSensor))
    {
        motor.moveForward();
    }
    else if (lineSensor == STOPPED)
    {
        motor.stopMotors();
        endPartieA = true;
    }
}

void clearMemory(Memoire24CXXX &mem)
{
    for (int i = 0; i < 5; i++)
    {
        mem.ecriture(i, 0);
        memoryAccessDelay();
        uint8_t pole1;
        mem.lecture(i, &pole1);
        memoryAccessDelay();
    }
}

void followLineOnly(Motor motor, uint16_t delay)
{
    for (uint8_t i = 0; i < delay; i++)
    {
        for (uint8_t j = 0; j < 10; j++)
        {
            followLinePartieA(motor);
            _delay_ms(1);
        }
    }
}


void partieA(Motor motor, Led led, Memoire24CXXX mem, can myCan)
{
    uint8_t poleCount = 0;
    uint8_t address = 0;
    clearMemory(mem);
    motor.moveForward();
    _delay_ms(800);

    while (!endPartieA)
    {
        followLinePartieA(motor);
        uint8_t distance;
        distance = getDistance(myCan);
        if (isPoleClose(distance)||isPoleFar(distance))
        {


            followLineOnly(motor, 6);
            distance = getDistance(myCan);
            if (isPoleClose(distance))
            {
                followLineOnly(motor, 6);
                distance = getDistance(myCan);
                if (isPoleClose(distance))
                {
                    poleCount++;
                    mem.ecriture(address, CLOSE);
                    memoryAccessDelay();
                    address++;
                    led.setLedRed();
                    motor.stopMotors();
                    makePoleNoise(CLOSE);
                    followLineOnly(motor, 150);
                    led.setLedOff();
                }
            }
            else if (isPoleFar(distance))
            {
                followLineOnly(motor, 6);
                distance = getDistance(myCan);
                if (isPoleFar(distance))
                {
                    mem.ecriture(address, FAR);
                    memoryAccessDelay();
                    address++;
                    poleCount++;
                    led.setLedGreen();
                    motor.stopMotors();
                    makePoleNoise(FAR);
                    followLineOnly(motor, 150);
                    led.setLedOff();
                }
            }
        }
        else
        {
            led.setLedOff();
        }
    }
    if (poleCount == 2)
    {
        uint8_t donnee;
        mem.lecture(1, &donnee);
        memoryAccessDelay();
        mem.ecriture(2, donnee);
        memoryAccessDelay();
        mem.ecriture(1, 0);
        memoryAccessDelay();
    }
    mem.ecriture(3, poleCount);
    memoryAccessDelay();
    for (int i = 0; i < 4; i++)
    {
        uint8_t pole1;
        mem.lecture(i, &pole1);
        memoryAccessDelay();
    }
}
