/*********************************************************************************************************/
/*                                                                                                       */
/*  Nom : rs232.hpp                                                                                      */
/*  Auteurs :   Omar Ben-Thami,Mohammed Amine El Hila,Ayah Farhat,                                       */
/*              Nofissa Khaif ,Abdelkarim Merdjaoui,Sofiane Mouici                                       */
/*                                                                                                       */
/*  Fonctions de base pour utiliser la memoire rs232 pour pouvoir debugger au besoin                     */
/*                                                                                                       */
/*                                                                   */
/*                                                                                                       */
/*********************************************************************************************************/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>

void initialisationUART(void);
void transmissionUART(uint8_t donnee);
uint8_t receptionUART();