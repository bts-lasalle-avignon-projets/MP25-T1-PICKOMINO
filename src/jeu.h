#ifndef JEU_H
#define JEU_H

#include "pickomino.h"

void jouerPickomino();
void initialiserPartie(Jeu& jeu);
bool jouerTour(Jeu& jeu);
void verifierDisponibiliteDe(Jeu& jeu, int& valeurDeChoisi);
void gererDesRetenus(Jeu& jeu, int& valeurDeChoisi);
<<<<<<< HEAD
void gererFinTour(Jeu& jeu, bool tourPerdu);
int  determinerJoueurGagnant(const Jeu& jeu);
=======
void gererFinTour(Jeu& jeu);
>>>>>>> 7f6c6ce4ed9c278a9637db6e0629d9a415a1d3e1

#endif
