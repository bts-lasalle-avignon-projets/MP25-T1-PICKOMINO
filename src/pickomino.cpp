#include "pickomino.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>

void initialiserJoueur(Joueur (&joueurs)[NB_JOUEURS_MAX], int nbJoueurs)
{
    for(int i = 0; i < nbJoueurs; ++i)
    {
        joueurs[i].versTotal     = 0;
        joueurs[i].sommetPile    = 0;
        joueurs[i].numero        = i;
        joueurs[i].valeurMaxPile = 0;
        for(int j = 0; j < NB_PICKOMINOS; ++j)
        {
            joueurs[i].pilePickomino[j] = 0;
        }
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

int calculerTotalDesRetenus(int desRetenus[NB_FACES])
{
    int totalDes = 0;

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
    if(desRetenus[FACE_VER - 1] > 0)
    {
        return true;
    }

    return false;
}

bool prendrePickominoBrochette(Jeu& jeu)
{
    int totalDesRetenus = calculerTotalDesRetenus(jeu.plateau.desRetenus);

    if(totalDesRetenus > VALEUR_PICKOMINOS_MAX)
    {
        totalDesRetenus = VALEUR_PICKOMINOS_MAX;
    }

    // disponible dans la brochette ?
    if(jeu.plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].valeur ==
         totalDesRetenus &&
       jeu.plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].etat == VISIBLE)
    {
        jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile++;
        jeu.joueurs[jeu.plateau.numeroJoueur]
          .pilePickomino[jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile] = totalDesRetenus;
        jeu.joueurs[jeu.plateau.numeroJoueur].versTotal =
          jeu.joueurs[jeu.plateau.numeroJoueur].versTotal +
          jeu.plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].nombreVers;

        jeu.plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].etat = RETOURNE;
    }
    // le prochain disponible dans la brochette ?
    else if(jeu.plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].valeur ==
              totalDesRetenus &&
            jeu.plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].etat ==
              RETOURNE)
    {
        bool prise = false;
        for(int i = totalDesRetenus - VALEUR_PICKOMINOS_MIN; i > 0; --i)
        {
            if(jeu.plateau.brochettePickominos[i - 1].etat == VISIBLE)
            {
                jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile++;
                jeu.joueurs[jeu.plateau.numeroJoueur]
                  .pilePickomino[jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile] =
                  jeu.plateau.brochettePickominos[i - 1].valeur;
                jeu.joueurs[jeu.plateau.numeroJoueur].versTotal =
                  jeu.joueurs[jeu.plateau.numeroJoueur].versTotal +
                  jeu.plateau.brochettePickominos[i - 1].nombreVers;

                jeu.plateau.brochettePickominos[i - 1].etat = RETOURNE;
                prise                                       = true;
                break;
            }
        }
        // S’il ne reste aucun Pickomino qui convienne,
        // le lancer du joueur est considéré comme nul.
        if(!prise)
        {
            return false;
        }
    }
    else
    {
    }

    return true;
}

bool volerPickominoJoueur(Jeu& jeu)
{
    int totalDesRetenus = calculerTotalDesRetenus(jeu.plateau.desRetenus);
    for(int i = 0; i < jeu.nbJoueurs; ++i)
    {
        if(totalDesRetenus == jeu.joueurs[i].pilePickomino[jeu.joueurs[i].sommetPile] &&
           jeu.joueurs[jeu.plateau.numeroJoueur].numero != jeu.joueurs[i].numero)
        {
            jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile++;
            jeu.joueurs[jeu.plateau.numeroJoueur]
              .pilePickomino[jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile] = totalDesRetenus;
            jeu.joueurs[jeu.plateau.numeroJoueur].versTotal =
              jeu.joueurs[jeu.plateau.numeroJoueur].versTotal +
              jeu.plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].nombreVers;

            totalDesRetenus = jeu.joueurs[i].pilePickomino[jeu.joueurs[i].sommetPile];
            jeu.joueurs[i].versTotal =
              jeu.joueurs[i].versTotal -
              jeu.plateau.brochettePickominos[totalDesRetenus - VALEUR_PICKOMINOS_MIN].nombreVers;
            jeu.joueurs[i].sommetPile--;

            return true;
        }
    }
    return false;
}

void remettreTuileDansBrochette(Jeu& jeu)
{
    if(jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile > 0)
    {
        jeu.joueurs[jeu.plateau.numeroJoueur].versTotal =
          jeu.joueurs[jeu.plateau.numeroJoueur].versTotal -
          jeu.plateau
            .brochettePickominos[jeu.joueurs[jeu.plateau.numeroJoueur].pilePickomino
                                   [jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile] -
                                 VALEUR_PICKOMINOS_MIN]
            .nombreVers;
        jeu.plateau
          .brochettePickominos[jeu.joueurs[jeu.plateau.numeroJoueur]
                                 .pilePickomino[jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile] -
                               VALEUR_PICKOMINOS_MIN]
          .etat = VISIBLE;
        jeu.joueurs[jeu.plateau.numeroJoueur]
          .pilePickomino[jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile] = 0;
        jeu.joueurs[jeu.plateau.numeroJoueur].sommetPile--;
    }
    else
    {
        // Si le joueur n’a pas de Pickomino à remettre, aucun Pickomino n’est retourné sur la
        // brochette.
        return;
    }

    for(int i = NB_PICKOMINOS - 1; i >= 0; --i)
    {
        if(jeu.plateau.brochettePickominos[i].etat == VISIBLE)
        {
            jeu.plateau.brochettePickominos[i].etat = RETOURNE;
            break;
        }
    }
}

bool verifierValeurTotalDesTropPetit(Plateau& plateau)
{
    int totalDesRetenus = calculerTotalDesRetenus(plateau.desRetenus);
    if(totalDesRetenus >= VALEUR_PICKOMINOS_MIN)
    {
        return true;
    }
    else
    {
        return false;
    }
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
void ajouterPartieHistorique(const std::string& nom, int versTotal)
{
    std::ofstream fichier("src/historique.txt", std::ios::app);
    if(!fichier)
    {
        std::cerr << "Erreur : impossible d'accéder à l'historique " << std::endl;
    }
    fichier << "[" << nom << ";" << versTotal << "]";
    fichier.close();
    std::cout << "Ajouter dans l'historique" << std::endl;
}