/*
Travail : PROJET FINAL
Section # : 03
Équipe # : 486364
Correcteur : Charles De Lafontaine

Auteurs : Omar Ben Thami, Nofissa Khaif, Ayah Farhat, Sofiane Mouici, Abdelkarim Merdjaoui, Mohammed Amine El hila.

Description du programme :  Le code ci-dessous permet au robot de changer son mode de suivi du parcours afin d’effectuer 
                            une manoeuvre en zigzag. En effet, plutôt que de suivre une ligne, il devra emprunter le couloir et y évoluer 
                            à l’intérieur en « rebondissant » d’un segment à l’autre. À la fin de cette manoeuvre, le robot se stationnera à l’endroit défini.

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
#pragma once 
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include "robotTrack.h"
void followLinePartieS(Motor motor);
void zigzag(Motor motor, uint8_t &zigzagCounter);
void partieS(Motor motor, Led led, Memoire24CXXX mem, can myCan);
void park(Motor motor);
void isrPartieS();
