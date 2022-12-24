#pragma once

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "avr/io.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "led.h"
#include "pwm.h"
#include "timer.h"
#include "rs232.h"
#include "memoire_24.h"
#include "delay.h"
#include "can.h"
#include "button.h"
#include "motor.h"
#include "debug.h"
#include "son.h"
#include "breadboardbutton.h"
#include <math.h>

const uint8_t MOTOR_SPEED = 170;

enum POLL_PROXIMITY
{
    CLOSE = 1,
    FAR = 2,
    NO_POLL = 0
};
enum SENSOR_STATES
{
    DEVIATED_RIGHT1 = 0b10000,
    DEVIATED_RIGHT2 = 0b11000,
    DEVIATED_RIGHT3 = 0b01000,
    TURN_LEFT = 0b11100,
    TURN_LEFT2 = 0b11110,

    DEVIATED_LEFT1 = 0b00001,
    DEVIATED_LEFT2 = 0b00011,
    DEVIATED_LEFT3 = 0b00010,
    TURN_RIGHT = 0b00111,
    TURN_RIGHT2 = 0b01111,

    GOING_STRAIGHT1 = 0b01100,
    GOING_STRAIGHT2 = 0b00110,
    GOING_STRAIGHT3 = 0b00100,
    GOING_STRAIGHT4 = 0b01110,

    STOPPED = 0b11111,
    END = 0b00000,
    INTERSECTION12 = 0b10001,
    INTERSECTION1 = 0b01010,
    INTERSECTION2 = 0b11011,
    INTERSECTION3 = 0b01101,
    INTERSECTION4 = 0b11001,
    INTERSECTION5 = 0b01001,
    INTERSECTION6 = 0b11010,
    INTERSECTION7 = 0b10010,
    INTERSECTION8 = 0b10100,
    INTERSECTION9 = 0b01011,
    INTERSECTION11 = 0b00101,
    INTERSECTION10 = 0b10110
};

enum STATES
{
    PARTIEA,
    PARTIEB,
    PARTIES
};

enum LINES
{
    LEFT_LINE = 0b10000,
    RIGHT_LINE = 0b00001
};

void delayms();
void playSong();
bool isDeviatedRight(uint8_t lineSensor);
bool isDeviatedLeft(uint8_t lineSensor);
bool isGoingStraight(uint8_t lineSensor);
bool isAtIntersection(uint8_t lineSensor);
void partirMinuterie();
void switchState(STATES &state);
void doStateTask(const STATES &state, Led &led);
void flashColourOnce(const STATES &state, Led &led);
void flashingSequence(STATES &currentState, Led &led);
void selectMode(STATES &currentState, Led &led);
void turnRight(Motor motor);
void memoryAccessDelay();
bool isPoleClose(uint8_t distance);
bool isPoleFar(uint8_t distance);
void makePoleNoise(uint8_t proximity);
uint8_t getDistance(can &myCan);
void isrRoutine();
bool isPartieB();
bool isPartieS();