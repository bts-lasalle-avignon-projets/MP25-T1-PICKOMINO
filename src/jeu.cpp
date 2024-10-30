#include "jeu.h"
#include "affichage.h"
#include "pickomino.h"

Jeu jeu;

void jouerPickomino()
{
    initialiserPartie();
}

void initialiserPartie()
{
    srand(time(NULL));

    jeu.nbJoueurs = saisirNombreJoueurs(NB_JOUEURS_MAX, NB_JOUEURS_MIN);

    for (int i = 0; i < jeu.nbJoueurs; ++i)
    {
        saisirNomJoueur(jeu.joueurs[i].nom);
        initialiserJoueur(jeu.joueurs, jeu.nbJoueurs);
    }

    for (int i = 0; i < jeu.nbJoueurs; ++i) 
    {
        afficherJoueur(jeu.joueurs[i].nom, jeu.joueurs[i].versTotal, jeu.joueurs[i].sommetPile, jeu.joueurs[i].pilePickomino);
    }

    initialiserBrochette(jeu.plateau.brochettePickominos);
    afficherBrochettePickominos(jeu.plateau.brochettePickominos);
}