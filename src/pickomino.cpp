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

void reinitialiserPlateau(Plateau& plateau)
{
    plateau.nbDes = NB_DES;
    for(int i = 0; i < NB_FACES; ++i)
    {
        plateau.desRetenus[i] = 0;
    }
    plateau.totalDes = 0;
}

void lancerDes(int nbDes, int des[NB_DES])
{
    for(int i = 0; i < nbDes; ++i)
    {
        des[i] = rand() % NB_FACES + 1;
    }
}

bool verifierChoixImpossible(const Plateau& plateau)
{
    for(int i = 0; i < plateau.nbDes; ++i)
    {
        int faceActuelle = plateau.des[i] - 1;

        if(faceActuelle >= 0 && faceActuelle < NB_FACES && plateau.desRetenus[faceActuelle] == 0)
        {
            return false;
        }
        else if(plateau.nbDes == 0)
        {
            return true;
        }
        else
        {
        }
    }

    return true;
}

void stockerDesRetenus(int valeurDeChoisi, Plateau& plateau)
{
    int nbDesRetire = 0;

    for(int i = 0; i < plateau.nbDes; i++)
    {
        if(plateau.des[i] == valeurDeChoisi)
        {
            plateau.desRetenus[valeurDeChoisi - 1]++;
            nbDesRetire++;
        }
    }

    plateau.nbDes = plateau.nbDes - nbDesRetire;
}

bool verifierDeDejaPris(int valeurDeChoisi, const Plateau& plateau)
{
    if(plateau.desRetenus[valeurDeChoisi - 1] > 0 && (valeurDeChoisi - 1) >= 0 &&
       (valeurDeChoisi - 1) < NB_FACES)
    {
        return true;
    }

    for(int i = 0; i < plateau.nbDes; ++i)
    {
        if(valeurDeChoisi == plateau.des[i])
        {
            return false;
        }
    }

    return true;
}

int calculerTotalDesRetenus(int totalDes, int desRetenus[NB_FACES])
{
    totalDes = 0;

    for(int i = 0; i < NB_FACES; ++i)
    {
        if(i + 1 == FACE_VER)
        {
            totalDes = totalDes + (desRetenus[i] * i);
        }
        else
        {
            totalDes = totalDes + (desRetenus[i] * (i + 1));
        }
    }

    return totalDes;
}

bool verifierPresenceVer(int desRetenus[NB_FACES])
{
    if(desRetenus[5] > 0)
    {
        return true;
    }

    return false;
}
bool verifierBrochetteVide(Pickomino (&brochette)[NB_PICKOMINOS])
{
    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        if(brochette[i].etat == VISIBLE)
        {
            return true;
        }
    }

    return false;
}