#include "jeu.h"
#include "pickomino.h"
#include "affichage.h"

#include <cstdlib>
#include <ctime>

void jouerPickomino()
{
    Jeu  jeu;
    bool estFinie = false;

    afficherAccueil();

    do
    {
        int optionChoisie = afficherMenu();

        switch(optionChoisie)
        {
            case AFFICHER_REGLES:
                afficherRegles();
                break;
            case JOUER:
                jouerPartie(jeu);
                break;
            case QUITTER:
                estFinie = true;
                break;
            default:
                afficherSaisieInvalide();
                break;
        }
    } while(!estFinie);
}

void jouerPartie(Jeu& jeu)
{
    initialiserPartie(jeu);
    do
    {
        jouerTour(jeu);
        // au joueur suivant
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

    initialiserBrochette(jeu.plateau.brochettePickominos);
}

bool jouerTour(Jeu& jeu)
{
    bool finTour = false;
    int  valeurDeChoisi;
    bool tourPerdu = false;

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
                gererFinTour(jeu, tourPerdu);
            }
        }
    } while(!finTour);

    afficherJoueurs(jeu);

    return true;
}

void gererFinTour(Jeu& jeu, bool tourPerdu)
{
    bool lancerNul = false;

    if(verifierPresenceVer(jeu.plateau.desRetenus) &&
       verifierValeurTotalDesTropPetit(jeu.plateau) && !tourPerdu)
    {
        bool verifierVolPossible = volerPickominoJoueur(jeu);
        if(!verifierVolPossible)
        {
            lancerNul = !prendrePickominoBrochette(jeu);
        }
    }
    else
    {
        lancerNul = true;
    }

    if(lancerNul)
    {
        remettreTuileDansBrochette(jeu);
    }
}

void verifierDisponibiliteDe(const Jeu& jeu, int& valeurDeChoisi)
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