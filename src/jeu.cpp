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
    } while(!estPartieFinie(jeu.plateau.brochettePickominos));
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

    initialiserBrochette(jeu.plateau.brochettePickominos);
}

bool jouerTour(Jeu& jeu)
{
    bool finTour = false;
    int  valeurDeChoisi;

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
            verifierDisponibiliteDe(jeu, valeurDeChoisi);
            gererDesRetenus(jeu, valeurDeChoisi);

            finTour = choisirFinTour();
            if(finTour)
            {
                gererFinTour(jeu);
            }
        }
    } while(!finTour);

    afficherJoueurs(jeu);

    // au joueur suivant
    jeu.plateau.numeroJoueur = (jeu.plateau.numeroJoueur + 1) % jeu.nbJoueurs;

    return true;
}

void gererFinTour(Jeu& jeu)
{
    if(verifierPresenceVer(jeu.plateau.desRetenus) && verifierValeurTotalDesTropPetit(jeu.plateau))
    {
        volerPickominoJoueur(jeu);
        prendrePickominoBrochette(jeu);
    }
    else
    {
        remettreTuileDansBrochette(jeu);
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

void gererDesRetenus(Jeu& jeu, const int& valeurDeChoisi)
{
    stockerDesRetenus(valeurDeChoisi, jeu.plateau);
    afficherDesRetenus(jeu.plateau.desRetenus);
    afficherCalculTotalDesRetenus(calculerTotalDesRetenus(jeu.plateau.desRetenus));
}

bool estPartieFinie(const Pickomino (&brochette)[NB_PICKOMINOS])
{
    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        if(brochette[i].etat == Etat::VISIBLE)
        {
            return false;
        }
    }
    return true;
}
