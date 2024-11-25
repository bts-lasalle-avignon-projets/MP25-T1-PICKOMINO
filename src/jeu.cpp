#include "jeu.h"
#include "affichage.h"

#include <cstdlib>
#include <ctime>

void jouerPickomino()
{
    Jeu jeu;

    initialiserPartie(jeu);

    do
    {
        jouerTour(jeu);
        jeu.plateau.numeroJoueur = (jeu.plateau.numeroJoueur + 1) % jeu.nbJoueurs;

    } while(verifierBrochetteVide(jeu.plateau.brochettePickominos));

    int joueurGagnant = determinerJoueurGagnant(jeu);
    afficherJoueurGagnant(jeu.joueurs[joueurGagnant].nom, jeu.joueurs[joueurGagnant].versTotal);
}

void initialiserPartie(Jeu& jeu)
{
    srand(time(NULL));

    jeu.nbJoueurs            = saisirNombreJoueurs(NB_JOUEURS_MAX, NB_JOUEURS_MIN);
    jeu.plateau.numeroJoueur = 0;

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
    bool finTour = false;
    int  valeurDeChoisi;
    bool tourPerdu = false;

    afficherJoueurTour(jeu.joueurs[jeu.plateau.numeroJoueur]);

    reinitialiserPlateau(jeu.plateau);

    do
    {
        lancerDes(jeu.plateau.nbDes, jeu.plateau.des);
        afficherDes(jeu.plateau.nbDes, jeu.plateau.des);

        if(verifierChoixImpossible(jeu.plateau))
        {
            afficherChoixImpossible();
            finTour   = true;
            tourPerdu = true;
        }
        else
        {
            verifierDisponibiliteDe(jeu, valeurDeChoisi);
            gererDesRetenus(jeu, valeurDeChoisi);

            finTour = choisirFinTour();
<<<<<<< HEAD
        }

        if(finTour)
        {
            gererFinTour(jeu, tourPerdu);
=======

            if (finTour)
            {
                gererFinTour(jeu);
                break;
            }
>>>>>>> 7f6c6ce4ed9c278a9637db6e0629d9a415a1d3e1
        }
    } while(!finTour);

    return true;
}

<<<<<<< HEAD
void gererFinTour(Jeu& jeu, bool tourPerdu)
{
    if(verifierPresenceVer(jeu.plateau.desRetenus) &&
       verifierValeurTotalDesTropPetit(jeu.plateau) && !tourPerdu)
    {
        bool verifierVolPossible = volerPickominoJoueur(jeu.joueurs, jeu.plateau, jeu.nbJoueurs);
        if(!verifierVolPossible)
        {
            PrendrePickominoBrochette(jeu.joueurs, jeu.plateau, jeu.plateau.brochettePickominos);
        }
    }
    else
    {
        remettreTuileDansBrochette(jeu.joueurs, jeu.plateau, jeu.plateau.brochettePickominos);
=======
void gererFinTour(Jeu& jeu)
{
    if (verifierPresenceVer(jeu.plateau.desRetenus) && verifierValeurTotalDesTropPetit(jeu.plateau))
    {
        volerPickominoJoueur(jeu, jeu.plateau);
        PrendrePickominoBrochette(jeu, jeu.plateau, jeu.plateau.brochettePickominos);
    }
    else
    {
        remettreTuileDansBrochette(jeu, jeu.plateau, jeu.plateau.brochettePickominos);
>>>>>>> 7f6c6ce4ed9c278a9637db6e0629d9a415a1d3e1
    }

    afficherBrochettePickominos(jeu.plateau.brochettePickominos);

<<<<<<< HEAD
    for(int i = 0; i < jeu.nbJoueurs; ++i)
    {
        afficherJoueur(jeu.joueurs[i]);
    }
=======
    for (int i = 0; i < jeu.nbJoueurs; ++i)
    {
        afficherJoueur(jeu.joueurs[i]);
    }

>>>>>>> 7f6c6ce4ed9c278a9637db6e0629d9a415a1d3e1
}

void verifierDisponibiliteDe(Jeu& jeu, int& valeurDeChoisi)
{
    do
    {
        valeurDeChoisi = choisirDesRetenus();
        if(verifierDeDejaPris(valeurDeChoisi, jeu.plateau))
        {
            afficherVerifierDeDejaPris();
        }
    } while(verifierDeDejaPris(valeurDeChoisi, jeu.plateau));
}

void gererDesRetenus(Jeu& jeu, int& valeurDeChoisi)
{
    stockerDesRetenus(valeurDeChoisi, jeu.plateau);
    afficherDesRetenus(jeu.plateau.desRetenus);
    afficherCalculTotalDesRetenus(
    calculerTotalDesRetenus(jeu.plateau.totalDes, jeu.plateau.desRetenus));
}

int determinerJoueurGagnant(const Jeu& jeu)
{
    int joueurGagnant = 0;

    for(int i = 1; i < jeu.nbJoueurs; ++i)
    {
        if(jeu.joueurs[i].versTotal > jeu.joueurs[joueurGagnant].versTotal)
        {
            joueurGagnant = i;
        }
    }

    return joueurGagnant;
}
