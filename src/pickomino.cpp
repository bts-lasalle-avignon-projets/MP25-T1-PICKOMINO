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

bool verifierChoixImpossible(int desRetenus[NB_FACES], int des[NB_DES], int &nbDes) 
{
    for(int i = 0; i < nbDes; ++i) 
    {
        int faceActuelle = des[i] - 1;

        if(faceActuelle >= 0 && faceActuelle < NB_FACES && desRetenus[faceActuelle] == 0) 
        {
            return false;
        }
        else if(nbDes == 0)
        {
            return true;
        }
        else
        {
        }
    }
    
    return true;
}

void stockerDesRetenus(int valeurDeChoisi, int desRetenus[NB_FACES], int des[NB_DES], int &nbDes)
{
    int nbDesRetire = 0;

    for(int i = 0; i < nbDes; i++) 
    {
        if(des[i] == valeurDeChoisi) 
        {
            desRetenus[valeurDeChoisi - 1]++;
            nbDesRetire++;
        }
    }

    nbDes = nbDes - nbDesRetire;
}

bool verifierDeDejaPris(int valeurDeChoisi, int desRetenus[NB_FACES], int nbDes, int des[NB_DES])
{
    if(desRetenus[valeurDeChoisi - 1] > 0 && (valeurDeChoisi - 1) >= 0 && (valeurDeChoisi - 1) < NB_FACES)
    {
        return true;
    }
    
    for(int i = 0; i < nbDes; ++i)
    {
        if(valeurDeChoisi == des[i])
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