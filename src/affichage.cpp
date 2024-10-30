#include "affichage.h"
#include <iostream>
#include <iomanip>

int saisirNombreJoueurs(int nbJoueursMax, int nbJoueursMin)
{
    int nombreJoueurs = 0;
    do
    {
        std::cout << "Entrez le nombre de joueurs (minimum : " << nbJoueursMin
                  << " - maximum : " << nbJoueursMax << ") ? ";
        std::cin >> nombreJoueurs;
        if(nombreJoueurs < nbJoueursMin || nombreJoueurs > nbJoueursMax)
        {
            std::cout << "Saisie invalide !" << std::endl;
        }
    } while(nombreJoueurs < nbJoueursMin || nombreJoueurs > nbJoueursMax);

    return nombreJoueurs;
}

void saisirNomJoueur(std::string& nom)
{
    std::cout << "Entrez le nom du joueur : ";
    std::cin >> nom;
}

void afficherJoueur(const Joueur& joueur)
{
    std::cout << std::endl;
    std::cout << "Nom du joueur : " << joueur.nom << std::endl;
    std::cout << "Total vers : " << joueur.versTotal << std::endl;
    std::cout << "Nombre de pickominos : ";
    if(joueur.sommetPile == 0)
    {
        std::cout << "aucun" << std::endl;
    }
    else
    {
        std::cout << joueur.sommetPile << std::endl;
        std::cout << "Pickomino tout en haut de la pile : "
                  << joueur.pilePickomino[joueur.sommetPile - 1] << std::endl;
    }
    std::cout << std::endl;
}

void afficherBrochettePickominos(const Pickomino (&brochette)[NB_PICKOMINOS])
{
    std::cout << "Brochette Pickominos : " << std::endl;
    std::cout << "|";
    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        if(brochette[i].etat == Etat::VISIBLE)
        {
            std::cout << std::setfill(' ') << std::setw(4) << brochette[i].valeur;
        }
        else if(brochette[i].etat == Etat::RETOURNE)
        {
            std::cout << "X  ";
        }
        else
        {
        }
    }
    std::cout << "  |" << std::endl;
    std::cout << "|";
    for(int i = 0; i < NB_PICKOMINOS; ++i)
    {
        if(brochette[i].etat == Etat::VISIBLE)
        {
            std::cout << std::setfill(' ') << std::setw(4) << brochette[i].nombreVers;
        }
        else if(brochette[i].etat == Etat::RETOURNE)
        {
            std::cout << "    ";
        }
        else
        {
        }
    }
    std::cout << "  |" << std::endl;
    std::cout << std::endl;
}