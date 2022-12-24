/*
Travail : PROJET FINAL
Section # : 03
Équipe # : 486364
Correcteur : Charles De Lafontaine

Auteurs : Omar Ben Thami, Nofissa Khaif, Ayah Farhat, Sofiane Mouici, Abdelkarim Merdjaoui, Mohammed Amine El hila.

Description du programme :  Robot qui effectue un parcours évitant des obstacles en prenant une direction inverse.
                            Il effectue à la suite de cela un parcours entre deux lignes en effectuant des zigzags
                            pour ensuite effectuer une manoeuvre de stationnement. Se référer à l'image ci-dessous.

                            circuit : https://cours.polymtl.ca/inf1900/tp/projet/epreuves/images/table.png


Identifications matérielles (broches I/O):
       Entrées:
              -> BROCHE-A :: A1                  (Capteur de distance)
              -> BROCHE-C :: C3 à C8.            (Capteur de ligne noir)
              -> BROCHE-D :: D2 et D3            (Pour les bouttons)

       Sorties:
               -> BROCHE-A :: A2, A3
               -> BROCHE-B :: B1, B2             (Pour la DEL)
                              B3 et B6           (Pour les moteurs)
               -> BROCHE-D :: D5 et D6           (Pour le piezo)
*/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include "partieA.h"
#include "partieB.h"
#include "partieS.h"

void runTrack(STATES &currentState, Led &led, Motor &motor, Memoire24CXXX &mem, can &myCan)
{

    switch (currentState)
    {
    case PARTIEA:
        partieA(motor, led, mem, myCan);
        break;
    case PARTIEB:
        partieB(motor, led, mem, myCan);
        switchState(currentState);
        motor.moveForward();
        _delay_ms(225);
        led.setLedRed();
    case PARTIES:
        partieS(motor, led, mem, myCan);
        led.setLedRed();
        playSong();
        break;
    }
}

void isrRoutine()
{
    if (isPartieB())
    {
        isrPartieB();
    }
    else if (isPartieS())
    {
        isrPartieS();
    }
}

ISR(TIMER1_COMPA_vect)
{
    isrRoutine();
}

int main()
{
    Led led(&PORTB, 1, 0);
    const uint8_t MOTOR_SPEED = 170;
    Motor motor(MOTOR_SPEED);
    Memoire24CXXX mem;
    can myCan;
    DDRA = 0x00;
    DDRB = 0xFF;
    DDRC = 0x00;
    DDRD = 0xF0;
    STATES currentState = PARTIEA;
    selectMode(currentState, led);
    flashingSequence(currentState, led);
    runTrack(currentState, led, motor, mem, myCan);

    return 0;
}