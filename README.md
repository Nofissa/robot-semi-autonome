# semi-autonomous-robot
AUTEURS:
    Ben Thami Omar 
    El Hila Mohammed Amine
    Farhat Ayah
    Khaif Nofissa
    Merdjaoui Abdelkarim
    Sofiane Mouici

DESCRIPTION: 
    L'épreuve se déroule sur une table de 4 par 8 pieds sur laquelle se trouve du ruban noir que et des poteaux.
    Il existe trois points de départ possibles pour le robot : A, B et S. Chacun de ces points est associé à une couleur.
    A : vert
    B : rouge
    S : ambre
    Le mécanisme permettant de choisir le point de départ utilise le bouton Interrupt, le bouton blanc (branché sur le breadboard) 
    et la Del Libre.
    Le bouton blanc, qui doit être branché sur le breadboard, permet de changer la sélection. Chaque fois que le bouton est appuyé, 
    la sélection passe au prochain point. L’alternance se fait en boucle. Ainsi, passé le dernier point (S) la sélection revient au premier (A).

   La Del Libre indique quel est le point présentement sélectionné. Elle affiche donc la couleur associée au point tel que listé ci-haut.

   Le bouton Interrupt sert quant à lui à confirmer la sélection. Lorsqu’il est appuyé, la Del Libre doit clignoter 4 fois par seconde 
    pendant deux secondes puis s’éteindre. Le robot doit ensuite procéder au suivi du parcours à partir du point de départ sélectionné.

   Lorsque le robot est mis sous tension ou réinitialisé, la sélection doit initialement être le point A. La Del Libre doit donc être 
    allumée en vert.

   Une fois le robot mis sous tension par l’évaluateur, ce dernier sélectionnera le point de départ A. Un coup en marche, le robot doit 
    détecter et mémoriser l’emplacement des poteaux à l’aide de son capteur de distance. À chaque fois qu’un poteau est détecté, le robot 
    arrête puis émet un son pendant une seconde puis continue à avancer. Si le poteau détecté est près de lui (points F, H, K, N) le son 
    émis doit être aigu. Si le poteau est loin (points G, I, L, O), le son doit être grave.
    Depuis le marqueur B, le robot se met à avancer, effectue un virage à 90 degrés au point C, puis un autre au point D. Il continue et 
    se dirige vers l’embranchement au point E où il devra choisir le chemin exempt de poteau. Arrivé à J il avance pour placer son centre 
    de rotation vis-à-vis les points K et L. Si un poteau se trouve sur L, il effectue un virage de 15 degrés en sens horaire, pause pour 
    une seconde, fait le virage inverse et poursuit sont chemin vers M. Si un poteau se trouve plutôt sur K, il exécute la même séquence d’action, mais cette fois-ci le virage initial est en sens antihoraire. Finalement, s’il n’y a aucun poteau, il ne fait pas de virage. Il 
    devra plutôt reculer de 1.5 pouce, faire une pause d’une seconde, puis repartir en direction de M. Arrivé à ce point, le robot choisit
    à nouveau le chemin sans poteau. À P, le robot continue vers Q et fait un virage à 90 degrés, puis un autre à R et se dirige vers S. Lorsqu’il arrive à S, il ne s’arrête pas et enchaine avec la troisième partie.

   Un coup arrivé à X, le robot doit aussitôt effectuer une manœuvre pour aller se « stationner » entre les 4 points jaunes. Le robot 
    peut pointer soit vers le haut ou le bas de la table. Pourvu qu’il soit le plus possible centré entre les 4 points jaunes.

MATERIEL: 
    1 suiveur de ligne Cytron LSS05
    1 capteur de distance GP2Y0A21YK0F (ou GP2D12)





source(https://cours.polymtl.ca/inf1900/tp/projet/epreuves/)
