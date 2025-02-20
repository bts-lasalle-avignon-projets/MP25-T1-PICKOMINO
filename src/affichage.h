#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <string>
#include "pickomino.h"

int         saisirNombreJoueurs(int nbJoueursMax, int nbJoueursMin);
void        saisirNomJoueur(std::string& nom, int& age);
int         saisirNombreJoueursIA(int nbJoueursIAMax, int nbJoueursIAMin);
int         saisirNombreOrdinateursIA(int nbOrdinateursIAMax, int nbOrdinateursIAMin);
void        saisirNomJoueur(std::string& nom, int& age);
void        afficherJoueurs(const Jeu& jeu);
void        afficherJoueur(const Joueur& joueur);
void        afficherBrochettePickominos(const Pickomino (&brochette)[NB_PICKOMINOS]);
void        afficherJoueurTour(const Joueur& joueur);
void        afficherDes(int nbDes, const int des[NB_DES]);
void        afficherChoixImpossible();
int         choisirDesRetenus();
void        afficherVerifierDeDejaPris();
void        afficherDesRetenus(const int desRetenus[NB_FACES]);
void        afficherCalculTotalDesRetenus(int totalDes);
bool        choisirFinTour();
void        afficherJoueurGagnant(const std::string& nom, int versTotal);
void        afficherAccueil();
int         afficherMenu();
void        afficherRegles();
void        afficherSaisieInvalide();
void        afficherSeparation();
std::string lireFichier(const std::string& chemin);
void        traiterTrame(const std::string& trame);
void        effacerHistorique();
void        afficherHistorique();
int         afficherDifficultes(const std::string& nomIA);

#endif