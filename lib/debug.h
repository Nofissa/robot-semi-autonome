/**********************************************************************************************************/
/*                                                                                                       */
/*  Nom : debug.hpp                                                                                      */
/*  Auteurs :   Omar Ben-Thami,Mohammed Amine El Hila,Ayah Farhat,                                       */
/*              Nofissa Khaif ,Abdelkarim Merdjaoui,Sofiane Mouici                                       */
/*                                                                                                       */
/*  Fonctions qui permettent dutiliser RS232 pour envoyer une chaine                                     */
/*            de caractere du robot vers le PC                                                           */
/*                                                                                                       */
/*                                                                                                       */
/*********************************************************************************************************/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#include "rs232.h"

void printMessage(uint8_t data[], uint8_t nCaracters);