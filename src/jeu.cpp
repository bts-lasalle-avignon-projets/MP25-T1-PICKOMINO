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
    int valeurDeChoisi;

    afficherJoueurTour(jeu.joueurs[jeu.plateau.numeroJoueur]);

    reinitialiserPlateau(jeu.plateau);

    while (jeu.plateau.nbDes > 0) 
    {
        lancerDes(jeu.plateau.nbDes, jeu.plateau.des);
        afficherDes(jeu.plateau.nbDes, jeu.plateau.des);

        if(verifierChoixImpossible(jeu.plateau.desRetenus, jeu.plateau.des, jeu.plateau.nbDes)) 
        {
            afficherChoixImpossible();
            return true;
        }

        verifierDisponibiliteDe(jeu, valeurDeChoisi);
        gererDesRetenus(jeu, valeurDeChoisi);
        
        bool finTour = choixFinTour();
        if(finTour && verifierPresenceVer(jeu.plateau.desRetenus))
        {
            //Choisir une tuile dans la brochette ou le joueur
            break;
        }
        else if(finTour && !verifierPresenceVer(jeu.plateau.desRetenus))
        {
            //Remettre la dernière tuile de la pile dans la brochette 
            //et retourner la tuile la plus haute de la brochette de pichominos
            break;
        }
        else
        {  
        }
    }

    return true;
}

void verifierDisponibiliteDe(Jeu& jeu, int& valeurDeChoisi)
{
    do 
    {
        valeurDeChoisi = choisirDesRetenus();
        if(verifierDeDejaPris(valeurDeChoisi, jeu.plateau.desRetenus, jeu.plateau.nbDes, jeu.plateau.des)) 
        {
            afficherVerifierDeDejaPris();
        }
    } while(verifierDeDejaPris(valeurDeChoisi, jeu.plateau.desRetenus, jeu.plateau.nbDes, jeu.plateau.des));
}

void gererDesRetenus(Jeu& jeu, int& valeurDeChoisi)
{
    stockerDesRetenus(valeurDeChoisi, jeu.plateau.desRetenus, jeu.plateau.des, jeu.plateau.nbDes);
    afficherDesRetenus(jeu.plateau.desRetenus);
    afficherCalculTotalDesRetenus(calculerTotalDesRetenus(jeu.plateau.totalDes, jeu.plateau.desRetenus));
}

