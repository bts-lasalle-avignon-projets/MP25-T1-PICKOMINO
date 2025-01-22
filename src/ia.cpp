#include "ia.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void jouerPartieIAFacile(Jeu& jeu)
{
    afficherAccueil();
    initialiserPartieIA(jeu, DIFFICULTE_FACILE);
    int numeroJoueurHumain = 1;

    do
    {
        if(jeu.plateau.numeroJoueur < numeroJoueurHumain)
        {
            jouerTour(jeu);
        }
        else
        {
            jouerTourIA(jeu);
        }

        jeu.plateau.numeroJoueur = (jeu.plateau.numeroJoueur + 1) % jeu.nbJoueurs;

    } while(verifierBrochetteVide(jeu.plateau.brochettePickominos));

    int joueurGagnant = determinerJoueurGagnant(jeu);
    ajouterPartieHistorique(jeu.joueurs[joueurGagnant].nom, jeu.joueurs[joueurGagnant].versTotal);
    afficherJoueurGagnant(jeu.joueurs[joueurGagnant].nom, jeu.joueurs[joueurGagnant].versTotal);
}

void initialiserPartieIA(Jeu& jeu, int difficulteChoisie)
{
    srand(time(NULL));

    int nombreJoueursHumains = saisirNombreJoueurs(NB_JOUEURS_MAX, NB_JOUEURS_MIN);
    int numeroJoueurHumain   = 1;
    jeu.nbJoueurs            = nombreJoueursHumains + 1;
    jeu.plateau.numeroJoueur = 0;

    for(int i = 0; i < jeu.nbJoueurs; ++i)
    {
        if(i < numeroJoueurHumain)
        {
            saisirNomJoueur(jeu.joueurs[i].nom);
        }
        else
        {
            jeu.joueurs[i].nom = "IA " + std::to_string(i + 1);
        }
        initialiserJoueur(jeu.joueurs, jeu.nbJoueurs);
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
            valeurDeChoisi = choisirFaceAleatoire(jeu.plateau);
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