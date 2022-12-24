/*
Travail : PROJET FINAL
Section # : 03
Équipe # : 486364
Correcteur : Charles De Lafontaine

Auteurs : Omar Ben Thami, Nofissa Khaif, Ayah Farhat, Sofiane Mouici, Abdelkarim Merdjaoui, Mohammed Amine El hila.

Description du programme :  Le code ci-dessous permet au robot de suivre un parcours à l’aide d’un suiveur de ligne 
                            et de capter des objets à proximité à l’aide d’un capteur de distance infrarouge.  
                            À chaque fois qu’un poteau est détecté, le robot arrête puis émet un son pendant une seconde 
                            puis continue à avancer. Si le robot détecte un objet proche, il émet un son aigu. 
                            S’il détecte un objet loin, il émet un son grave.

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

void partieA(Motor motor, Led led, Memoire24CXXX mem, can myCan);
void followLinePartieA(Motor motor);
void followLineOnly(Motor motor, uint16_t delay);
void clearMemory(Memoire24CXXX &mem);