#include "affichage.h"
#include "couleurs.h"
#include "ia.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <string>

int saisirNombreJoueurs(int nbJoueursMax, int nbJoueursMin)
{
    int nombreJoueurs = 0;
    do
    {
        std::cout << "Entrez le nombre de joueurs (minimum : " << nbJoueursMin
                  << " - maximum : " << nbJoueursMax << ") ? ";
        std::cin >> nombreJoueurs;
        if(std::cin.good())
        {
            if(nombreJoueurs < nbJoueursMin || nombreJoueurs > nbJoueursMax)
            {
                std::cout << ROUGE << "Saisie invalide !" << COULEUR_DEFAUT << std::endl;
            }
        }
        else
        {
            std::cout << ROUGE << "Saisie invalide !" << COULEUR_DEFAUT << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while(nombreJoueurs < nbJoueursMin || nombreJoueurs > nbJoueursMax);

    return nombreJoueurs;
}

int saisirNombreJoueursIA(int nbJoueursIAMax, int nbJoueursIAMin)
{
    int nombreJoueursIA = 0;
    do
    {
        std::cout << "Entrez le nombre de joueurs (minimum : " << nbJoueursIAMin
                  << " - maximum : " << nbJoueursIAMax << ") ? ";
        std::cin >> nombreJoueursIA;
        if(std::cin.good())
        {
            if(nombreJoueursIA < nbJoueursIAMin || nombreJoueursIA > nbJoueursIAMax)
            {
                std::cout << ROUGE << "Saisie invalide !" << COULEUR_DEFAUT << std::endl;
            }
        }
        else
        {
            std::cout << ROUGE << "Saisie invalide !" << COULEUR_DEFAUT << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while(nombreJoueursIA < nbJoueursIAMin || nombreJoueursIA > nbJoueursIAMax);

    return nombreJoueursIA;
}

int saisirNombreOrdinateursIA(int nbOrdinateursIAMax, int nbOrdinateursIAMin)
{
    int nombreOrdinateursIA = 0;

    do
    {
        std::cout << "Entrez le nombre d'ordinateurs (minimum : " << nbOrdinateursIAMin
                  << " - maximum : " << nbOrdinateursIAMax << ") ? ";
        std::cin >> nombreOrdinateursIA;
        if(std::cin.good())
        {
            if(nombreOrdinateursIA < nbOrdinateursIAMin || nombreOrdinateursIA > nbOrdinateursIAMax)
            {
                std::cout << ROUGE << "Saisie invalide !" << COULEUR_DEFAUT << std::endl;
            }
        }
        else
        {
            std::cout << ROUGE << "Saisie invalide !" << COULEUR_DEFAUT << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while(nombreOrdinateursIA < nbOrdinateursIAMin || nombreOrdinateursIA > nbOrdinateursIAMax);

    return nombreOrdinateursIA;
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
    std::cout << "Nom du joueur : " << BLEU_GRAS << joueur.nom << COULEUR_DEFAUT << std::endl;
    std::cout << "Total vers : " << VERT << joueur.versTotal << COULEUR_DEFAUT << std::endl;
    std::cout << "Nombre de pickominos : ";
    if(joueur.sommetPile == 0)
    {
        std::cout << ROUGE << "aucun" << COULEUR_DEFAUT << std::endl;
    }
    else
    {
        std::cout << VERT << joueur.sommetPile << COULEUR_DEFAUT << std::endl;
        std::cout << "Pile de pickominos : ";
        for(int i = joueur.sommetPile; i > 0; --i)
        {
            std::cout << VERT << joueur.pilePickomino[i] << COULEUR_DEFAUT << " ";
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
            std::cout << ROUGE << "  X" << COULEUR_DEFAUT;
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

    std::cout << "Au tour du joueur : " << BLEU_GRAS << joueur.nom << COULEUR_DEFAUT << std::endl
              << std::endl;
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
    std::cout << ROUGE
              << "Les faces possibles ont déjà été retenues ou plus aucun dé n'est disponible.\n"
              << COULEUR_DEFAUT << std::endl;
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
            std::cout << ROUGE << "Valeur invalide ! choisir une valeur de 1 à 5 ou 'V'\n"
                      << COULEUR_DEFAUT << std::endl;
        }
    } while(valeur < 1 || valeur > FACE_VER);

    return valeur;
}

void afficherVerifierDeDejaPris()
{
    std::cout << ROUGE << "Ce dé est déjà retenu ou il n'est pas existant parmis les dés lancés."
              << std::endl
              << "Veuillez choisir une autre valeur.\n"
              << COULEUR_DEFAUT << std::endl;
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
            std::cout << ROUGE << "Choix invalide !\n" << COULEUR_DEFAUT << std::endl;
            valide = false;
        }
    } while(!valide);

    afficherSeparation();

    return finTour;
}

void afficherJoueurGagnant(const std::string& nom, int versTotal)
{
    std::cout << "Le gagnant de cette partie est : ";
    std::cout << JAUNE_GRAS << nom << COULEUR_DEFAUT;
    std::cout << " avec ";
    std::cout << JAUNE_GRAS << versTotal << COULEUR_DEFAUT;
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
    std::cout << "  MILLOT Pierre                            " << BLEU << "v" << VERSION
              << COULEUR_DEFAUT << std::endl;
    std::cout << "  NAVARRO Mattéo" << std::endl;
    afficherSeparation();
    std::cout << std::endl << std::endl;
}

int afficherMenu()
{
    int optionChoisie = 0;

    std::cout << "<----------------------> MENU <---------------------->" << std::endl;
    std::cout << std::endl;
    std::cout << VERT << "                    1 - Afficher les règles           " << COULEUR_DEFAUT
              << std::endl;
    std::cout << BLEU << "                    2 - Jouer une partie              " << COULEUR_DEFAUT
              << std::endl;
    std::cout << CYAN
              << "                    3 - Jouer une partie contre l'ordinateur              "
              << COULEUR_DEFAUT << std::endl;
    std::cout << MAGENTA << "                    4 - Historique des parties        "
              << COULEUR_DEFAUT << std::endl;
    std::cout << ROUGE << "                    5 - Quitter le jeu                " << COULEUR_DEFAUT
              << std::endl;
    std::cout << std::endl;
    std::cout << "<---------------------------------------------------->\n" << std::endl;
    std::cout << "Choisir une option : ";
    std::cin >> optionChoisie;
    std::cout << std::endl;

    return optionChoisie;
}

int afficherDifficultes(const std::string& nomIA)
{
    int  optionDifficulteChoisie = 0;
    bool saisieValide            = false;

    do
    {
        system("clear");
        std::cout << "<----------------------> DIFFICULTES <---------------------->" << std::endl;
        std::cout << std::endl;
        std::cout << VERT << "                         1 - Facile               " << COULEUR_DEFAUT
                  << std::endl;
        std::cout << BLEU << "                         2 - Moyen            " << COULEUR_DEFAUT
                  << std::endl;
        std::cout << ROUGE << "                         3 - Difficile           " << COULEUR_DEFAUT
                  << std::endl;
        std::cout << "<---------------------------------------------------->\n" << std::endl;
        std::cout << "Choisir une option pour " << nomIA << " : ";
        std::cin >> optionDifficulteChoisie;
        switch(optionDifficulteChoisie)
        {
            case NIVEAU_IA_FACILE:
            case NIVEAU_IA_MOYEN:
            case NIVEAU_IA_DIFFICILE:
                saisieValide = true;
                break;
            default:
                afficherSaisieInvalide();
                break;
        }
        std::cout << std::endl;
    } while(!saisieValide);

    return optionDifficulteChoisie;
}

void afficherRegles()
{
    system("clear");
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
    std::cout << ROUGE << "Saisie invalide ! Réessayez." << COULEUR_DEFAUT << std::endl
              << std::endl;
    std::cin.clear();
    std::cin.ignore();
}

void afficherSeparation()
{
    std::cout << "=============================================================" << std::endl;
}

std::string lireFichier(const std::string& chemin)
{
    std::ifstream fichier(chemin);
    if(!fichier.is_open())
    {
        std::cerr << "Erreur : impossible d'accéder à l'historique " << std::endl;
        return "";
    }
    std::string contenu;
    std::getline(fichier, contenu);
    fichier.close();
    return contenu;
}

void traiterTrame(const std::string& trame)
{
    size_t debut = 0;
    while((debut = trame.find('[', debut)) != std::string::npos)
    {
        size_t fin = trame.find(']', debut);
        if(fin == std::string::npos)
        {
            std::cerr << "Erreur : Trame mal formatée (']' manquant)." << std::endl;
        }

        std::string contenu = trame.substr(debut + 1, fin - debut - 1);

        size_t virgule = contenu.find(',');
        if(virgule == std::string::npos)
        {
            std::cerr << "Erreur : Format incorrect (',' manquant)." << std::endl;
        }

        std::string nom   = contenu.substr(0, virgule);
        int         score = std::stoi(contenu.substr(virgule + 1));

        std::cout << VERT << "Nom du Gagnant: " << JAUNE << nom << COULEUR_DEFAUT;
        std::cout << VERT << " avec vers: " << JAUNE << score << COULEUR_DEFAUT << "\n"
                  << std::endl;

        debut = fin + 1;
    }
}

bool choisirEffacerHistorique()
{
    char saisieReponse;
    bool saisieValide      = false;
    bool effacerHistorique = false;
    do
    {
        std::cout << "Voulez vous effacer l'historique ? (o / n) : " << std::endl;
        std::cin >> saisieReponse;
        std::cout << std::endl;
        if(saisieReponse == 'o' || saisieReponse == 'O')
        {
            saisieValide      = true;
            effacerHistorique = true;
        }
        else if(saisieReponse == 'n' || saisieReponse == 'N')
        {
            saisieValide      = true;
            effacerHistorique = false;
        }
        else
        {
            std::cout << ROUGE << "Choix invalide !\n" << COULEUR_DEFAUT << std::endl;
            saisieValide = false;
        }
    } while(!saisieValide);
    return effacerHistorique;
}

void effacerHistorique()
{
    std::ofstream fichier("src/historique.txt", std::ios::out);
    if(!fichier)
    {
        std::cerr << "Erreur : impossible d'accéder à l'historique " << std::endl;
    }
    fichier.close();
}

void afficherHistorique()
{
    system("clear");
    std::string trame = lireFichier("src/historique.txt");

    if(!trame.empty())
    {
        traiterTrame(trame);
        if(choisirEffacerHistorique())
        {
            effacerHistorique();
            std::cout << VERT_GRAS << "L'historique des parties effacer !" << COULEUR_DEFAUT
                      << std::endl;
        }
        else
        {
            std::cout << VERT_GRAS << "L'historique des parties n'a pas été effacé !\n"
                      << COULEUR_DEFAUT << std::endl;
        }
    }
    else
    {
        std::cout << ROUGE_GRAS << "L'historique des parties est vide" << COULEUR_DEFAUT
                  << std::endl;
    }
}