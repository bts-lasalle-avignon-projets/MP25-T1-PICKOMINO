#ifndef JEU_H
#define JEU_H

#include "pickomino.h"

void jouerPickomino();
void initialiserPartie(Jeu& jeu);
bool jouerTour(Jeu& jeu);
void verifierDisponibiliteDe(Jeu& jeu, int& valeurDeChoisi);
void gererDesRetenus(Jeu& jeu, int& valeurDeChoisi);
int  determinerJoueurGagnant(const Jeu& jeu);

#endif