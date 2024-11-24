#include "jeu.h"
#include "affichage.h"

#include <cstdlib>
#include <ctime>

void jouerPickomino()
{
    Jeu jeu;

    initialiserPartie(jeu);

    jouerTour(jeu);
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

    afficherJoueurTour(jeu.joueurs[jeu.plateau.numeroJoueur]);

    reinitialiserPlateau(jeu.plateau);

    do
    {
        lancerDes(jeu.plateau.nbDes, jeu.plateau.des);
        afficherDes(jeu.plateau.nbDes, jeu.plateau.des);

        if(verifierChoixImpossible(jeu.plateau))
        {
            afficherChoixImpossible();
            finTour = true;
        }
        else
        {
            verifierDisponibiliteDe(jeu, valeurDeChoisi);
            gererDesRetenus(jeu, valeurDeChoisi);

            finTour = choisirFinTour();

            if (finTour)
            {
                gererFinTour(jeu);
                break;
            }
        }
    } while(!finTour);

    return true;
}

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
    }

    afficherBrochettePickominos(jeu.plateau.brochettePickominos);

    for (int i = 0; i < jeu.nbJoueurs; ++i)
    {
        afficherJoueur(jeu.joueurs[i]);
    }

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
