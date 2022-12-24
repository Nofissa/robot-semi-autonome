#include "partieB.h"

uint8_t rightTurnCounter = 0;
volatile bool isAtCenter = false;
bool allowTurnRight = false;
bool allowTurnLeft = true;
volatile uint8_t poleCounter = 0;
bool test = true;
uint8_t gCounter = 0;

void followLinePartieB(Motor motor, Led &led, Memoire24CXXX &mem, bool &allowEnd, bool &endOfPartieB)
{
    uint8_t lineSensor = PINC >> 3;
    if (isDeviatedRight(lineSensor))
    {
        motor.setSpeed(130);
        motor.turnLeft();
    }
    else if (allowTurnLeft && (lineSensor == TURN_LEFT || lineSensor == TURN_LEFT2))
    {
        led.setLedGreen();
        motor.turnLeft();
        _delay_ms(200);
    }
    else if (isDeviatedLeft(lineSensor))
    {
        motor.turnRight();
    }
    else if (allowTurnRight && (lineSensor == TURN_RIGHT || lineSensor == TURN_RIGHT2))
    {
        rightTurnCounter++;
        motor.turnRight();
        if (rightTurnCounter < 2)
            _delay_ms(200);
    }
    else if (isGoingStraight(lineSensor))
    {
        motor.moveForward();
    }
    else if (isAtIntersection(lineSensor))
    {
        doIntersectionTask(led, motor, mem, allowEnd);
    }
    else if (lineSensor == STOPPED && allowEnd)
    {
        motor.stopMotors();
        endOfPartieB = true;
    }

    if (isAtCenter)
    {
        motor.stopMotors();
        uint8_t pole;
        mem.lecture(1, &pole);
        memoryAccessDelay();
        if (pole == FAR)
        {
            motor.setSpeed(200);
            _delay_ms(500);
            motor.moveRightWheelBackward();
            _delay_ms(500);
            motor.stopMotors();
            _delay_ms(1000);
            motor.turnLeft();
            motor.setSpeed(MOTOR_SPEED);
        }
        else if (pole == CLOSE)
        {
            motor.setSpeed(200);
            _delay_ms(500);
            motor.turnLeft();
            _delay_ms(500);
            motor.stopMotors();
            _delay_ms(1000);
            motor.moveRightWheelBackward();
            motor.setSpeed(MOTOR_SPEED);
        }
        else if (pole == NO_POLL)
        {
            motor.moveBackward();
            _delay_ms(1000);
            motor.stopMotors();
            _delay_ms(1000);
        }
        isAtCenter = false;
    }
}

void partieB(Motor motor, Led led, Memoire24CXXX mem, can myCan)
{
    bool allowEnd = false;
    bool endOfPartieB = false;
    for (int i = 0; i < 5; i++)
    {
        uint8_t pole1;
        mem.lecture(i, &pole1);
        memoryAccessDelay();
    }
    motor.moveForward();
    _delay_ms(800);
    while (!endOfPartieB)
    {
        followLinePartieB(motor, led, mem, allowEnd, endOfPartieB);
    }
}

void isrPartieB()
{
    gCounter++;
    if (gCounter == 2)
    {
        if (test == true)
        {

            isAtCenter = true;
            allowTurnRight = true;
            poleCounter = 2;
            test = false;
        }
        TCCR1B = 0;
    }
}

void doIntersectionTask(Led &led, Motor &motor, Memoire24CXXX &mem, bool &allowEnd)
{
    uint8_t pole;
    if (poleCounter == 0)
    {
        allowTurnLeft = false;
        cli();
        Timer timer = Timer(Timer::Select::TIMER1, 0, _BV(WGM12));
        timer.setCompareVal(Timer::Select::TIMER1, 43000);
        timer.setInterruptMask(Timer::Select::TIMER1, _BV(OCIE1A));
        partirMinuterie();
        sei();
        led.setLedRed();
        mem.lecture(2, &pole);
        poleCounter++;
    }
    else if (poleCounter == 2)
    {
        led.setLedGreen();
        motor.stopMotors();
        _delay_ms(400);
        mem.lecture(0, &pole);
        _delay_ms(10);
        poleCounter++;
        allowEnd = true;
    }
    if (pole == CLOSE)
    {
        motor.stopMotors();
        _delay_ms(400);
        motor.turnRight();
        _delay_ms(500);
    }
    else if (pole == FAR)
    {
        motor.stopMotors();
        _delay_ms(400);
        motor.turnLeft();
        _delay_ms(500);
    }
}