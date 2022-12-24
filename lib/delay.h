/*********************************************************************************************************/
/*                                                                                                       */
/*  Nom : delay.hpp                                                                                      */
/*  Auteurs :   Omar Ben-Thami,Mohammed Amine El Hila,Ayah Farhat,                                       */
/*              Nofissa Khaif ,Abdelkarim Merdjaoui,Sofiane Mouici                                       */
/*                                                                                                       */
/*  Fonctions de base afin de pouvoir utiliser des delays avec                                           */
/*           differentes mesures sans devoir faire des conversions                                       */
/*                                                                                                       */
/*                                                                                                       */
/*********************************************************************************************************/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>

const uint8_t DELAY_MULTIPLIER = 100;
void delayLoop(uint8_t nIterations);