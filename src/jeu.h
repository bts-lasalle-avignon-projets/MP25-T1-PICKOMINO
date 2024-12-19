#ifndef JEU_H
#define JEU_H

#include "pickomino.h"

#define AFFICHER_REGLES 1
#define JOUER           2
#define QUITTER         3

void jouerPickomino();
void initialiserPartie(Jeu& jeu);
bool jouerTour(Jeu& jeu);
void verifierDisponibiliteDe(const Jeu& jeu, int& valeurDeChoisi);
void gererDesRetenus(Jeu& jeu, const int& valeurDeChoisi);
void gererFinTour(Jeu& jeu, bool tourPerdu);
int  determinerVainqueurEgalite(const Joueur& joueur);
int  determinerJoueurGagnant(const Jeu& jeu);
void jouerPartie(Jeu& jeu);

#endif
