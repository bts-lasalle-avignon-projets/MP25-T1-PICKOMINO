#ifndef JEU_H
#define JEU_H

#include "pickomino.h"

void jouerPickomino();
void initialiserPartie(Jeu& jeu);
bool jouerTour(Jeu& jeu);
void verifierDisponibiliteDe(const Jeu& jeu, int& valeurDeChoisi);
void gererDesRetenus(Jeu& jeu, const int& valeurDeChoisi);
void gererFinTour(Jeu& jeu);
int  determinerJoueurGagnant(const Jeu& jeu);
void jouerPartie(Jeu& jeu);

#endif
