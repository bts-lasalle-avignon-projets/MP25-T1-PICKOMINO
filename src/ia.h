#ifndef IA_H
#define IA_H

#include "pickomino.h"
#include "jeu.h"

#define NB_ORDINATEURS_IA_MIN 1
#define NB_ORDINATEURS_IA_MAX 6

#define NB_JOUEURS_IA_MIN 0
#define NB_JOUEURS_IA_MAX 6

void jouerTourIA(Jeu& jeu);
void initialiserPartieIA(Jeu& jeu);
bool choisirFinTourIA(Plateau& plateau);
bool parcourirBrochette(Plateau& plateau);
int  choisirFaceIA(Jeu& jeu);
int  choisirFaceAleatoire(Plateau& plateau);
int  choisirFacePlusGrandTotal(Plateau& plateau);
bool presenceVerDansLancer(Plateau& plateau);

#endif