#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <string>
#include "pickomino.h"

int  saisirNombreJoueurs(int nbJoueursMax, int nbJoueursMin);
void saisirNomJoueur(std::string& nom);
void afficherJoueur(const Joueur& joueur);
void afficherBrochettePickominos(const Pickomino (&brochette)[NB_PICKOMINOS]);
void afficherJoueurTour(const Joueur& joueur);
void afficherDes(int nbDes, const int des[NB_DES]);

#endif