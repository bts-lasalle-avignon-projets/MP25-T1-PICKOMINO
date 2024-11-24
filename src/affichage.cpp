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
        std::cout << "Pile pickomino de : " << joueur.nom << std::endl;
        for(int i = joueur.sommetPile; i > 0; --i)
        {
            std::cout << joueur.pilePickomino[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Pickomino tout en haut de la pile : "
                  << joueur.pilePickomino[joueur.sommetPile] << std::endl;
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
            std::cout << "  X";
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
            std::cout << "   ";
        }
        else
        {
        }
    }
    std::cout << "  |" << std::endl;
    std::cout << std::endl;
}

void afficherJoueurTour(const Joueur& joueur)
{
    std::cout << "Au tour du joueur : " << joueur.nom << std::endl;
}

void afficherDes(int nbDes, const int des[NB_DES])
{
    std::cout << "Dés lancés : ";
    for(int i = 0; i < nbDes; ++i)
    {
        if(des[i] == FACE_VER)
        {
            std::cout << "[ V ] ";
        }
        else
        {
            std::cout << "[ " << des[i] << " ] ";
        }
    }
    std::cout << std::endl;
}

void afficherChoixImpossible()
{
    std::cout << "Les faces possibles ont déjà été retenues ou plus aucun dé n'est disponible."
              << std::endl;
}

int choisirDesRetenus()
{
    std::string valeurDeChoisi;
    int         valeur = 0;

    do
    {
        std::cout << "Choisir la valeur à retenir : ";
        std::cin >> valeurDeChoisi;
        std::cout << std::endl;

        if(valeurDeChoisi == "V" || valeurDeChoisi == "v")
        {
            valeur = FACE_VER;
        }
        else if(valeurDeChoisi >= "1" && valeurDeChoisi <= "5")
        {
            valeur = std::stoi(valeurDeChoisi);
        }
        else
        {
            std::cout << "Valeur invalide ! choisir une valeur de 1 à 5 ou 'V'" << std::endl;
        }
    } while(valeur < 1 || valeur > FACE_VER);

    return valeur;
}

void afficherVerifierDeDejaPris()
{
    std::cout << "Ce dé est déjà retenu ou il n'est pas existant parmis les dés lancés."
              << std::endl
              << "Veuillez choisir une autre valeur." << std::endl;
}

void afficherDesRetenus(const int desRetenus[NB_FACES])
{
    std::cout << "Dés retenus :" << std::endl;
    std::cout << "|";
    for(int i = 0; i < NB_FACES; ++i)
    {
        if(i == FACE_VER - 1)
        {
            std::cout << std::setfill(' ') << std::setw(4) << "V";
        }
        else
        {
            std::cout << std::setfill(' ') << std::setw(4) << i + 1;
        }
    }
    std::cout << "  |" << std::endl;
    std::cout << "|";
    for(int i = 0; i < NB_FACES; ++i)
    {
        std::cout << std::setfill(' ') << std::setw(4) << desRetenus[i];
    }
    std::cout << "  |" << std::endl;
    std::cout << std::endl;
}

void afficherCalculTotalDesRetenus(int totalDes)
{
    std::cout << "Total : " << totalDes << std::endl << std::endl;
}

bool choisirFinTour()
{
    char choix;
    bool valide  = false;
    bool finTour = false;

    do
    {
        std::cout << "Voulez-vous terminer votre tour ? (oO/nN) ";
        std::cin >> choix;
        std::cout << std::endl;
        if(choix == 'o' || choix == 'O')
        {
            finTour = true;
            valide  = true;
        }
        else if(choix == 'n' || choix == 'N')
        {
            finTour = false;
            valide  = true;
        }
        else
        {
            std::cout << "Choix invalide !" << std::endl;
            valide = false;
        }
    } while(!valide);

    return finTour;
}

int  choisirPickomino()
{
    int valeurPickominoChoisi;

    std::cout << "Choisir une tuile pickomino : ";
    std::cin >> valeurPickominoChoisi;
    std::cout << std::endl;
    return valeurPickominoChoisi;
}