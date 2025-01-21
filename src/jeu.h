#ifndef JEU_H
#define JEU_H

#include "pickomino.h"

#define AFFICHER_REGLES         1
#define JOUER                   2
#define JOUER_CONTRE_ORDINATEUR 3
#define HISTORIQUE              4
#define QUITTER                 5

#define DIFFICULTE_FACILE    6
#define DIFFICULTE_MOYEN     7
#define DIFFICULTE_DIFFICILE 8

void jouerPickomino();
void initialiserPartie(Jeu& jeu);
bool jouerTour(Jeu& jeu);
void verifierDisponibiliteDe(const Jeu& jeu, int& valeurDeChoisi);
void gererDesRetenus(Jeu& jeu, const int& valeurDeChoisi);
void gererFinTour(Jeu& jeu, bool tourPerdu);
int  determinerJoueurGagnant(const Jeu& jeu);
void jouerPartie(Jeu& jeu);
void ajouterTuileDansPile(Joueur& joueur, int nouvelleTuile);
void choisirDifficulte(Jeu& jeu, int optionDifficulteChoisie);

#endif
