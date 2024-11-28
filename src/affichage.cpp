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
    std::cout << "\n";
}

void afficherJoueurs(const Jeu& jeu)
{
    afficherSeparation();

    for(int i = 0; i < jeu.nbJoueurs; ++i)
    {
        afficherJoueur(jeu.joueurs[i]);
    }
}

void afficherJoueur(const Joueur& joueur)
{
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
        std::cout << "Pile de pickominos : ";
        for(int i = joueur.sommetPile; i > 0; --i)
        {
            std::cout << joueur.pilePickomino[i] << " ";
        }
        std::cout << std::endl;
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
    afficherSeparation();

    std::cout << "Au tour du joueur : " << joueur.nom << std::endl << std::endl;
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
    std::cout << "Les faces possibles ont déjà été retenues ou plus aucun dé n'est disponible.\n"
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
            std::cout << "Valeur invalide ! choisir une valeur de 1 à 5 ou 'V'\n" << std::endl;
        }
    } while(valeur < 1 || valeur > FACE_VER);

    return valeur;
}

void afficherVerifierDeDejaPris()
{
    std::cout << "Ce dé est déjà retenu ou il n'est pas existant parmis les dés lancés."
              << std::endl
              << "Veuillez choisir une autre valeur.\n"
              << std::endl;
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
            std::cout << "Choix invalide !\n" << std::endl;
            valide = false;
        }
    } while(!valide);

    afficherSeparation();

    return finTour;
}

void afficherJoueurGagnant(const std::string& nom, int versTotal)
{
    std::cout << "Le gagnant de cette partie est : ";
    std::cout << nom;
    std::cout << " avec ";
    std::cout << versTotal;
    std::cout << " vers";
    std::cout << std::endl;
    afficherSeparation();
}

void afficherAccueil()
{
    afficherSeparation();
    std::cout << "  ____  _      _                   _                 " << std::endl;
    std::cout << " |  _ \\(_) ___| | _____  _ __ ___ (_)_ __   ___     " << std::endl;
    std::cout << " | |_) | |/ __| |/ / _ \\| '_ ` _ \\| | '_ \\ / _ \\ " << std::endl;
    std::cout << " |  __/| | (__|   < (_) | | | | | | | | | | (_) |    " << std::endl;
    std::cout << " |_|   |_|\\___|_|\\_\\___/|_| |_| |_|_|_| |_|\\___/ " << std::endl;
    std::cout << std::endl;
    std::cout << "  MILLOT Pierre                            v" << VERSION << std::endl;
    std::cout << "  NAVARRO Mattéo" << std::endl;
    afficherSeparation();
    std::cout << std::endl << std::endl;
}

int afficherMenu()
{
    int optionChoisie = 0;

    std::cout << "<----------------------> MENU <---------------------->" << std::endl;
    std::cout << std::endl;
    std::cout << "                    1 - Afficher les règles           " << std::endl;
    std::cout << "                    2 - Jouer une partie              " << std::endl;
    std::cout << "                    3 - Quitter le jeu                " << std::endl;
    std::cout << std::endl;
    std::cout << "<---------------------------------------------------->\n" << std::endl;
    std::cout << "Choisir une option : ";
    std::cin >> optionChoisie;
    std::cout << std::endl;

    return optionChoisie;
}

void afficherRegles()
{
    std::cout << "But du jeu : Le vainqueur sera le joueur qui aura récupéré le plus de vers à la "
                 "fin de la partie."
              << std::endl
              << std::endl;
    std::cout << "Déroulement du jeu : Le premier joueur lance les 8 dés. Il doit choisir parmi "
                 "les dés le symbole qui "
                 "lui convient et mettre de côté tous les dés ayant le même symbole."
              << std::endl
              << std::endl;
    std::cout
      << "À chaque lancer, l'action est répétée, sauf qu'il doit choisir un symbole qu'il "
         "n'a pas choisi auparavant. ⚠️ Le joueur doit impérativement mettre de côté au "
         "moins un dé avec le symbole « ver » pour valider son tour et récupérer une tuile "
         "correspondant à la valeur totale de tous ses dés."
      << std::endl
      << std::endl;
    std::cout << "Face 1 = 1 point" << std::endl;
    std::cout << "Face 2 = 2 points" << std::endl;
    std::cout << "Face 3 = 3 points" << std::endl;
    std::cout << "Face 4 = 4 points" << std::endl;
    std::cout << "Face 5 = 5 points" << std::endl;
    std::cout << "Face v = 5 points\n" << std::endl;
    std::cout << std::endl;
    std::cout
      << "Si, à l'issue des lancers, le joueur ne peut pas prendre de tuile ou n'a pas obtenu de « "
         "ver », il doit remettre sa dernière tuile obtenue dans la brochette sur le plateau de "
         "jeu, et la tuile de plus haute valeur est retournée (retirée du jeu)."
      << std::endl
      << std::endl;
    std::cout << "La partie se termine quand toutes les tuiles ont été prises. Chaque joueur "
                 "compte le nombre de vers présents sur l'ensemble de ses tuiles. Le joueur ayant "
                 "le plus de vers remporte la partie."
              << std::endl
              << std::endl;
    std::cout << "Tuiles 21 à 24 = 1 ver" << std::endl;
    std::cout << "Tuiles 25 à 28 = 2 vers" << std::endl;
    std::cout << "Tuiles 29 à 32 = 3 vers" << std::endl;
    std::cout << "Tuiles 33 à 36 = 4 vers" << std::endl;
    std::cout << std::endl;
}

void afficherSaisieInvalide()
{
    std::cout << "Saisie invalide ! Réessayez." << std::endl << std::endl;
}

void afficherSeparation()
{
    std::cout << "=============================================================" << std::endl;
}