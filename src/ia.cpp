#include "ia.h"
#include <cstdlib>
#include <ctime>


void jouerPartieIAFacile(Jeu& jeu) 
{
    afficherAccueil();
    initialiserPartieIA(jeu, DIFFICULTE_FACILE);
    //int numeroJoueurHumain = 1;

    /*do 
    {
        if (jeu.plateau.numeroJoueur < numeroJoueurHumain) 
        {
            jouerTour(jeu);

        } 
        else 
        {
            jouerTourIA(jeu);
        }

        jeu.plateau.numeroJoueur = (jeu.plateau.numeroJoueur + 1) % jeu.nbJoueurs;

    } while (verifierBrochetteVide(jeu.plateau.brochettePickominos));


    int joueurGagnant = determinerJoueurGagnant(jeu);
    ajouterPartieHistorique(jeu.joueurs[joueurGagnant].nom, jeu.joueurs[joueurGagnant].versTotal);
    afficherJoueurGagnant(jeu.joueurs[joueurGagnant].nom, jeu.joueurs[joueurGagnant].versTotal);
    */
}

void initialiserPartieIA(Jeu& jeu, int difficulteChoisie) {

    srand(time(NULL));

    int nombreJoueursHumains = saisirNombreJoueurs(NB_JOUEURS_MAX, NB_JOUEURS_MIN);
    int numeroJoueurHumain = 1;
    jeu.nbJoueurs = nombreJoueursHumains + 1;
    jeu.plateau.numeroJoueur = 0;

    for (int i = 0; i < jeu.nbJoueurs; ++i) {

        if (i < numeroJoueurHumain) {

            saisirNomJoueur(jeu.joueurs[i].nom);

        } else {

            jeu.joueurs[i].nom = "IA " + std::to_string(i + 1);

        }
        initialiserJoueur(jeu.joueurs, jeu.nbJoueurs);

    }
    initialiserBrochette(jeu.plateau.brochettePickominos);

}