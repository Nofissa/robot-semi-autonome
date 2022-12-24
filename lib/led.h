/*********************************************************************************************************/
/*                                                                                                       */
/*  Nom : led.hpp                                                                                        */
/*  Auteurs :   Omar Ben-Thami,Mohammed Amine El Hila,Ayah Farhat,                                       */
/*              Nofissa Khaif ,Abdelkarim Merdjaoui,Sofiane Mouici                                       */
/*                                                                                                       */
/*  Fonctions de base afin de pouvoir utiliser une del bicolore connectee a une broche choisie           */
/*          par lutilisateur                                                                             */
/*      Concu pour etre utilise avec la carte Atmega 324PA                                               */
/*                                                                                                       */
/*  connections: broches qulconques connectes a la del bicolore en mode SORTIE                           */
/*                                                                                                       */
/*********************************************************************************************************/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

const uint8_t LED_GREEN = 0x01;
const uint8_t LED_OFF = 0x00;
const uint8_t LED_RED = 0x02;
const uint8_t DELAY_GREEN_FOR_AMBER = 10;
const uint8_t DELAY_RED_FOR_AMBER = 2;

class Led
{
public:
    Led();
    Led(volatile uint8_t *port, uint8_t positiveLedPin, uint8_t negativeLedPin);
    bool isPortAssigned();
    void setPort(volatile uint8_t *port);
    volatile uint8_t *getPort();
    void initializePort();
    void setPositiveLedPin(uint8_t positiveLedPin);
    uint8_t getPositiveLedPin();
    void setNegativeLedPin(uint8_t negativeLedPin);
    uint8_t getNegativeLedPin();
    void setLedGreen();
    void setLedAmber();
    void setLedRed();
    void setLedOff();
    void setLedColour(uint8_t colour);

private:
    volatile uint8_t *_port;
    uint8_t _positiveLedPin;
    uint8_t _negativeLedPin;
};