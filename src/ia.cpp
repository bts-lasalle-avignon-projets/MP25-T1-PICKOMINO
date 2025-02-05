#include "ia.h"
#include "affichage.h"

#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <iostream>

void initialiserPartieIA(Jeu& jeu)
{
    srand(time(NULL));

    jeu.nbJoueursIA = saisirNombreJoueursIA(NB_JOUEURS_IA_MAX, NB_JOUEURS_IA_MIN);

    int nbOrdinateursIAMaxPossible = NB_JOUEURS_MAX - jeu.nbJoueursIA;

    jeu.nbOrdinateursIA =
      saisirNombreOrdinateursIA(nbOrdinateursIAMaxPossible, NB_ORDINATEURS_IA_MIN);
    jeu.nbJoueurs = jeu.nbJoueursIA + jeu.nbOrdinateursIA;
    initialiserJoueur(jeu.joueurs, jeu.nbJoueurs);
    jeu.plateau.numeroJoueur = 0;

    for(int i = 0; i < jeu.nbJoueurs; ++i)
    {
        if(i < jeu.nbJoueursIA)
        {
            saisirNomJoueur(jeu.joueurs[i].nom);
        }
        else
        {
            jeu.joueurs[i].nom = "IA " + std::to_string(i - jeu.nbJoueursIA + 1);
            initialiserJoueurIA(jeu.joueurs, i, true, afficherDifficultes(jeu.joueurs[i].nom));
        }
    }
    initialiserBrochette(jeu.plateau.brochettePickominos);
}

void jouerTourIA(Jeu& jeu)
{
    int  valeurDeChoisi;
    bool finTour = false;

    afficherJoueurTour(jeu.joueurs[jeu.plateau.numeroJoueur]);
    afficherBrochettePickominos(jeu.plateau.brochettePickominos);
    reinitialiserPlateau(jeu.plateau);

    do
    {
        lancerDes(jeu.plateau.nbDes, jeu.plateau.des);
        afficherDes(jeu.plateau.nbDes, jeu.plateau.des);

        if(verifierChoixImpossible(jeu.plateau))
        {
            afficherChoixImpossible();
            remettreTuileDansBrochette(jeu);
            finTour = true;
        }
        else
        {
            valeurDeChoisi = choisirFaceIA(jeu);
            gererDesRetenus(jeu, valeurDeChoisi);
            finTour = choisirFinTourIA(jeu.plateau);

            if(finTour)
            {
                gererFinTour(jeu, false);
            }
        }
    } while(!finTour);

    afficherJoueurs(jeu);
}

bool choisirFinTourIA(Plateau& plateau)
{
    if(plateau.desRetenus[FACE_VER - 1] > 0 && parcourirBrochette(plateau))
    {
        return true;
    }
    return false;
}

bool parcourirBrochette(Plateau& plateau)
{
    int totalDesRetenus = calculerTotalDesRetenus(plateau.desRetenus);
    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        if(totalDesRetenus ==
             plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].valeur &&
           plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].etat == VISIBLE)
        {
            return true;
        }
    }
    return false;
}

int choisirFaceIA(Jeu& jeu)
{
    switch(jeu.joueurs[jeu.plateau.numeroJoueur].niveauIA)
    {
        case NIVEAU_IA_FACILE:
            return choisirFaceAleatoire(jeu.plateau);
            break;
        case NIVEAU_IA_MOYEN:
            return choisirFacePlusGrandTotal(jeu.plateau);
            break;
        case NIVEAU_IA_DIFFICILE:
        default:
            break;
    }
    return -1;
}

int choisirFaceAleatoire(Plateau& plateau)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int facesDisponibles[NB_DES];
    int nombreFacesDisponibles = 0;

    for(int i = 0; i < plateau.nbDes; ++i)
    {
        facesDisponibles[nombreFacesDisponibles++] = plateau.des[i];
    }

    if(plateau.desRetenus[FACE_VER - 1] > 0)
    {
        int faceChoisie = rand() % nombreFacesDisponibles;
        return facesDisponibles[faceChoisie];
    }

    return FACE_VER;
}

int choisirFacePlusGrandTotal(Plateau& plateau)
{
    int faceOccurence[NB_FACES] = {0,0,0,0,0,0};
    int valeurTotalFace[NB_FACES] = {0,0,0,0,0,0};
    int faceOccurencePlusEleve = 0;

    if(plateau.desRetenus[FACE_VER - 1] > 0 || !presenceVerDansLancer(plateau))
    {
        for(int i = 0; i < plateau.nbDes; ++i)
        {
            if(plateau.desRetenus[plateau.des[i] - 1] == 0)
            {
                faceOccurence[plateau.des[i] - 1]++;
            }
            else
            {
                faceOccurence[plateau.des[i] - 1] = 0;
            }
        }

        for(int i = 0; i < NB_FACES; ++i)
        {
            valeurTotalFace[i] = faceOccurence[i] * (i + 1);
        }

        for(int i = 0; i < NB_FACES; ++i)
        {
            if(valeurTotalFace[i] == valeurTotalFace[faceOccurencePlusEleve])
            {
                if(i > faceOccurencePlusEleve)
                {
                    faceOccurencePlusEleve = i;
                }
            }
            else if(faceOccurencePlusEleve != 0)
            {
                if(valeurTotalFace[i] > valeurTotalFace[faceOccurencePlusEleve])
                {
                    faceOccurencePlusEleve = i;
                }
            }
            else
            {
                faceOccurencePlusEleve = i;
            }
        }
        return faceOccurencePlusEleve + 1;
    }
    return FACE_VER;

}

bool presenceVerDansLancer(Plateau& plateau)
{
    for(int i = 0; i < plateau.nbDes; ++i)
    {
        if(plateau.des[i] == FACE_VER)
        {
            return true;
        }
    }
    return false;
}
