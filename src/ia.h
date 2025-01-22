#ifndef IA_H
#define IA_H

#include "pickomino.h"
#include "jeu.h"
#include "affichage.h"

#define NB_ORDINATEURS_IA_MIN 1
#define NB_ORDINATEURS_IA_MAX 6

#define NB_JOUEURS_IA_MIN 1
#define NB_JOUEURS_IA_MAX 6

void jouerPartieIAFacile(Jeu& jeu);
void jouerTourIA(Jeu& jeu);
void initialiserPartieIA(Jeu& jeu, int difficulteChoisie);
bool choisirFinTourIA(Plateau& plateau);
bool parcourirBrochette(Plateau& plateau);

#endif