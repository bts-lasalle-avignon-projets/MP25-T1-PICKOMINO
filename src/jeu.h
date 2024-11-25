#ifndef JEU_H
#define JEU_H

#include "pickomino.h"

void jouerPickomino();
void initialiserPartie(Jeu& jeu);
bool jouerTour(Jeu& jeu);
void verifierDisponibiliteDe(Jeu& jeu, int& valeurDeChoisi);
void gererDesRetenus(Jeu& jeu, const int& valeurDeChoisi);
void gererFinTour(Jeu& jeu);
bool estPartieFinie(const Pickomino (&brochette)[NB_PICKOMINOS]);

#endif
