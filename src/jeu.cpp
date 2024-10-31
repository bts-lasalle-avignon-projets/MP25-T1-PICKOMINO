#include "jeu.h"
#include "affichage.h"

#include <cstdlib>
#include <ctime>

void jouerPickomino()
{
    Jeu jeu;

    initialiserPartie(jeu);
    jeu.plateau.numeroJoueur = 0;
    afficherJoueurTour(jeu.joueurs[jeu.plateau.numeroJoueur]);
    jouerTour(jeu);
}

void initialiserPartie(Jeu& jeu)
{
    srand(time(NULL));

    jeu.nbJoueurs = saisirNombreJoueurs(NB_JOUEURS_MAX, NB_JOUEURS_MIN);

    for(int i = 0; i < jeu.nbJoueurs; ++i)
    {
        saisirNomJoueur(jeu.joueurs[i].nom);
        initialiserJoueur(jeu.joueurs, jeu.nbJoueurs);
    }

    for(int i = 0; i < jeu.nbJoueurs; ++i)
    {
        afficherJoueur(jeu.joueurs[i]);
    }

    initialiserBrochette(jeu.plateau.brochettePickominos);
    afficherBrochettePickominos(jeu.plateau.brochettePickominos);
}

bool jouerTour(Jeu& jeu)
{
    reinitialiserNombreDeEtDeRetenus(jeu.plateau.desRetenus, jeu.plateau.nbDes);

    lancerDes(jeu.plateau.nbDes, jeu.plateau.des);
    afficherDes(jeu.plateau.nbDes, jeu.plateau.des);
    
    return true;
}