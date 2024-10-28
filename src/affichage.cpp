#include "affichage.h"
#include <iostream>

int saisirNombreJoueurs(int nbJoueursMax, int nbJoueursMin) 
{
    int nombreJoueurs = 0;
    do {
        std::cout << "Combien de joueurs ? (maximum : " << nbJoueursMax << " ,minimum : " << nbJoueursMin << ")" << std::endl;
        std::cin >> nombreJoueurs;
        if (nombreJoueurs < nbJoueursMin || nombreJoueurs > nbJoueursMax) {
            std::cout << "Nombre invalide, saisir un nombre de joueurs entre " << nbJoueursMin << " et " << nbJoueursMax << std::endl;
        }
    } while (nombreJoueurs < nbJoueursMin || nombreJoueurs > nbJoueursMax);
    
    return nombreJoueurs;
}

void saisirNomJoueur(std::string& nom) {
    std::cout << "Entrez le nom du joueur : ";
    std::cin >> nom;
}

void afficherJoueur(const std::string& nom, int versTotal, int sommetPile) 
{
    std::cout << "\n" << std::endl;
    std::cout << "Nom du joueur : " << nom << std::endl;
    std::cout << "Vers total : " << versTotal << std::endl;
    std::cout << "Pickominos tout en haut de la pile : " << sommetPile << std::endl;
}

void afficherBrochettePickominos(const Pickomino (&brochette)[NB_PICKOMINOS])
{
    std::cout << "\n" << std::endl;
    for (int i = 0; i < NB_PICKOMINOS; ++i)
        {
            std::cout << brochette[i].valeur << " | " << brochette[i].nombreVers << " | ";
            if (brochette[i].etat == 0)
            {
                std::cout << "Visible" << std::endl;
            }
            else if (brochette[i].etat == 1)
            {
                std::cout << "Retourne" << std::endl;
            }
            else
            {
                std::cout << "Prise" << std::endl;
            }
        
        }
}