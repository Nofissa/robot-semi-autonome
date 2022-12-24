/*
Travail : PROJET FINAL
Section # : 03
Équipe # : 486364
Correcteur : Charles De Lafontaine

Auteurs : Omar Ben Thami, Nofissa Khaif, Ayah Farhat, Sofiane Mouici, Abdelkarim Merdjaoui, Mohammed Amine El hila.

Description du programme :  Le code ci-dessous permet au robot choisir le chemin exempt de poteau. Si un poteau se 
                            trouve sur la première intersection, il effectue un virage de 15 degrés en sens horaire ou antihoraire, 
                            dépendaient de l’emplacement du poteau, puis pause pour une seconde, fait le virage inverse et poursuit sont chemin. 
                            Finalement, s’il n’y a aucun poteau, il ne fait pas de virage. Il devra plutôt reculer de 1.5 pouce, 
                            faire une pause d’une seconde, puis repartir.  Arrivé à ce point, le robot choisit à nouveau le chemin sans poteau.

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

void followLinePartieB(Motor motor, Led &led, Memoire24CXXX &mem, bool &allowEnd, bool &endOfPartieB);
void partieB(Motor motor, Led led, Memoire24CXXX mem, can myCan);
void isrPartieB();
void doIntersectionTask(Led& led, Motor& motor, Memoire24CXXX& mem, bool& allowEnd);
