#include "pickomino.h"

void initialiserJoueur(Joueur (&joueurs)[NB_JOUEURS_MAX], int nbJoueurs)
{
    for ( int i = 0; i < nbJoueurs; ++i)
    {
        joueurs[i].versTotal = 0;
        joueurs[i].sommetPile = 0;
        for (int j = 0; j < NB_PICKOMINOS; ++j)
        {
            joueurs[i].pilePickomino[j] = 0;
        }

    }
}

void initialiserBrochette(Pickomino (&brochette)[NB_PICKOMINOS])
{
    for (int i = 0; i < NB_PICKOMINOS; ++i)
    {
        brochette[i].valeur = VALEUR_PICKOMINOS_MIN + i;

        int intervalle = (brochette[i].valeur - 21) / 4;
        brochette[i].nombreVers = intervalle + 1;
        
        brochette[i].etat = VISIBLE;
        
    }
}