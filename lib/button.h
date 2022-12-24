/*********************************************************************************************************/
/*                                                                                                       */
/*  Nom : button.hpp                                                                                     */
/*  Auteurs :   Omar Ben-Thami,Mohammed Amine El Hila,Ayah Farhat,                                       */
/*              Nofissa Khaif ,Abdelkarim Merdjaoui,Sofiane Mouici                                       */
/*                                                                                                       */
/*  Fonctions de base afin de pouvoir utiliser un bouton poussoir relie a la broche D2                   */
/*      Concu pour etre utilise avec la carte Atmega 324PA                                               */
/*                                                                                                       */
/*  connections: Broche D2 en ENTREE                                                                     */
/*                                                                                                       */
/*********************************************************************************************************/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

const uint8_t DEBOUNCE_DELAY = 10;
const uint8_t BUTTON_PIN = 0x04;
const uint8_t BUTTON_PIN_NUMBER = 2;

void setButtonPinIn();
bool isButtonPressed();
bool isButtonReleased();
bool isButtonPinOn();
void initialisationInterruption(void);
