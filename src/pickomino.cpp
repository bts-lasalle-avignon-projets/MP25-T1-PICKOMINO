#include "pickomino.h"

#include <cstdlib>
#include <time.h>

void initialiserJoueur(Joueur (&joueurs)[NB_JOUEURS_MAX], int nbJoueurs)
{
    for(int i = 0; i < nbJoueurs; ++i)
    {
        joueurs[i].versTotal  = 0;
        joueurs[i].sommetPile = 0;
    }
}

void initialiserBrochette(Pickomino (&brochette)[NB_PICKOMINOS])
{
    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        brochette[i].valeur     = VALEUR_PICKOMINOS_MIN + i;
        brochette[i].nombreVers = ((brochette[i].valeur - VALEUR_PICKOMINOS_MIN) / NB_VERS_MAX) + 1;
        brochette[i].etat       = VISIBLE;
    }
}

void reinitialiserNombreDeEtDeRetenus(int desRetenus[NB_FACES], int &nbDes)
{
    nbDes = NB_DES;
    for (int i = 0; i < NB_FACES; ++i) 
    {
        desRetenus[i] = 0;
    }
}

void lancerDes(int nbDes, int des[NB_DES]) 
{
    for (int i = 0; i < nbDes; ++i) 
    {
        des[i] = rand() % 6 + 1;
    }
}