#ifndef IA_H
#define IA_H

#include "pickomino.h"
#include "jeu.h"

#define NB_ORDINATEURS_IA_MIN 1
#define NB_ORDINATEURS_IA_MAX 6

#define NB_JOUEURS_IA_MIN 1
#define NB_JOUEURS_IA_MAX 6

#define AGE_IA 100

void jouerTourIA(Jeu& jeu);
void initialiserPartieIA(Jeu& jeu);
bool choisirFinTourIA(Plateau& plateau);
bool parcourirBrochette(Plateau& plateau);
int  choisirFaceIA(Jeu& jeu);
int  choisirFaceAleatoire(Plateau& plateau);
int  choisirFacePlusGrandTotal(Plateau& plateau);
void compterOccurencesDeChaqueFace(Plateau& plateau, int faceOccurence[NB_FACES]);
void calculerMeilleurFace(Plateau& plateau,
                          int      valeurTotalFace[NB_FACES],
                          int&     faceOccurencePlusEleve);
bool presenceVerDansLancer(Plateau& plateau);

#endif