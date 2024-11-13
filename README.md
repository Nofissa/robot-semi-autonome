# Robot Semi-Autonome
Développement d'un robot semi-autonome capable de suivre un parcours prédéfini en détectant et en évitant des obstacles à l’aide de capteurs. Le robot utilise un capteur de ligne et un capteur de distance pour se guider et émettre des signaux sonores en fonction de la distance aux poteaux. Un système de sélection de point de départ, contrôlé par des boutons et une DEL, permet de choisir parmi trois parcours initiaux (A, B ou S) avec confirmation visuelle et sonore.

## Table des Matières
- [Description](#description)
- [Matériel Utilisé](#matériel-utilisé)
- [Fonctionnalités](#fonctionnalités)
- [Utilisation](#utilisation)
- [Auteurs](#auteurs)


# Description
Le robot semi-autonome évolue sur une table de 4 par 8 pieds, avec des rubans noirs marquant les chemins et des poteaux comme obstacles. Il possède trois points de départ possibles (A, B, S), sélectionnables via un bouton dédié et confirmés par une DEL colorée. Chaque point de départ est associé à une couleur : A (vert), B (rouge), et S (ambre).

Lors de son parcours :
- Le robot détecte et mémorise l’emplacement des poteaux.
- Un signal sonore indique la distance des poteaux : aigu pour les poteaux proches et grave pour les poteaux éloignés.
- Le robot adapte sa trajectoire selon l'absence ou la présence de poteaux aux intersections, en choisissant les chemins dégagés.

# Matériel Utilisé
- Suiveur de ligne Cytron LSS05
- Capteur de distance : GP2Y0A21YK0F ou GP2D12

# Fonctionnalités
- Suivi de Ligne : Suit un ruban noir et ajuste sa trajectoire selon les obstacles.
- Détection d'Obstacles : Utilisation du capteur de distance pour détecter les poteaux sur le parcours.
- Signalisation Sonore : Différencie les poteaux proches et éloignés par des sons aigus ou graves.
- Sélection de Point de Départ : Choix parmi trois points (A, B, S) avec confirmation par une DEL.

# Utilisation
- Sélection du point de départ : Appuyer sur le bouton pour faire défiler les points (A, B, S). Confirmer la sélection avec le bouton   Interrupt.
- Mise sous tension : Une fois le point de départ sélectionné, le robot commence à suivre le parcours, détectant les poteaux et ajustant sa trajectoire en conséquence.
- Arrivée : À la fin du parcours, le robot effectue une manœuvre pour se stationner au centre des quatre points jaunes.


# Auteurs
- Nofissa Khaif
- Omar Benthami
- Ayah Farhat
- Mohammed Amine El Hila
- Sofiane Mouici
- Abdelkarim Merdjaoui
