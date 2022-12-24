#include "partieS.h"

volatile bool isZigzagActivated = false;
volatile bool wasGoingLeft = false;
volatile bool endOfLine = false;
volatile bool parked = 0;
volatile uint8_t counter = 0;

void followLinePartieS(Motor motor)
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
        motor.moveForward();

    else if (lineSensor == END)
    {
        if (endOfLine)
        {
            motor.stopMotors();
            park(motor);
        }
    }
}

void zigzag(Motor motor, uint8_t &zigzagCounter)
{

    uint8_t lineSensor = PINC >> 3;
    switch (lineSensor)
    {
    case RIGHT_LINE:
        motor.stopMotors();
        wasGoingLeft = true;
        motor.turnLeft();
        break;

    case LEFT_LINE:
        motor.stopMotors();

        if (wasGoingLeft)
            zigzagCounter++;
        wasGoingLeft = false;
        motor.turnRight();
        break;
    }
}

void partieS(Motor motor, Led led, Memoire24CXXX mem, can myCan)
{
    uint8_t zigZagCounter = 0;
    cli();
    Timer timer = Timer(Timer::Select::TIMER1, 0, _BV(WGM12));
    timer.setCompareVal(Timer::Select::TIMER1, 34000);
    timer.setInterruptMask(Timer::Select::TIMER1, _BV(OCIE1A));
    partirMinuterie();
    sei();
    motor.moveForward();
    uint8_t count = 0;
    while (!parked)
    {
        if (isZigzagActivated)
        {
            if (count == 0)
            {
                turnRight(motor);
                count++;
            }

            zigzag(motor, zigZagCounter);

            if (zigZagCounter == 5)
            {
                cli();
                Timer timer = Timer(Timer::Select::TIMER1, 0, _BV(WGM12));
                timer.setCompareVal(Timer::Select::TIMER1, 60000);
                timer.setInterruptMask(Timer::Select::TIMER1, _BV(OCIE1A));
                partirMinuterie();
                sei();
                led.setLedRed();
                isZigzagActivated = false;
                turnRight(motor);
                _delay_ms(450);
            }
        }
        else
            followLinePartieS(motor);
    }
}

void park(Motor motor)
{
    motor.moveBackward();
    _delay_ms(2000);
    motor.stopMotors();
    motor.turnRight();
    _delay_ms(1500);
    motor.stopMotors();
    motor.moveForward();
    _delay_ms(1000);
    motor.stopMotors();
    parked = true;
}

void isrPartieS()
{
    if (counter == 0)
    {
        isZigzagActivated = 1;
        counter++;
    }
    else if (counter == 1)
    {
        endOfLine = true;
        TCNT1 = 0;
        OCR1A = 0;
        TCCR1A = 0;
        TCCR1B = 0;
        OCR1B = 0;
        TIMSK1 = 0;
    }
    TCCR1B = 0;
}
