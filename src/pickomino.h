#ifndef PICKOMINO_H
#define PICKOMINO_H

#include <string>

#define VERSION "1.2"

#define NB_JOUEURS_MIN 2
#define NB_JOUEURS_MAX 7

#define NB_DES   8
#define NB_FACES 6
#define FACE_VER 6

#define NB_PICKOMINOS         16
#define VALEUR_PICKOMINOS_MIN 21
#define VALEUR_PICKOMINOS_MAX 36
#define NB_VERS_MAX           4

struct Joueur
{
    std::string nom;
    int         numero;
    int         versTotal;
    int         pilePickomino[NB_PICKOMINOS];
    int         sommetPile;
    int         valeurMaxPile;
};

enum Etat
{
    RETOURNE = -1,
    VISIBLE
};

struct Pickomino
{
    int  valeur;
    int  nombreVers;
    Etat etat;
};

struct Plateau
{
    int       numeroJoueur;
    int       totalDes;
    int       nbDes;
    int       des[NB_DES];
    int       desRetenus[NB_FACES];
    Pickomino brochettePickominos[NB_PICKOMINOS];
};

struct Jeu
{
    int     nbJoueurs;
    Joueur  joueurs[NB_JOUEURS_MAX];
    Plateau plateau;
};

void initialiserJoueur(Joueur (&joueurs)[NB_JOUEURS_MAX], int nbJoueurs);
void initialiserBrochette(Pickomino (&brochette)[NB_PICKOMINOS]);
void reinitialiserPlateau(Plateau& plateau);
void lancerDes(int nbDes, int des[NB_DES]);
bool verifierChoixImpossible(const Plateau& plateau);
void stockerDesRetenus(int valeurDeChoisi, Plateau& plateau);
bool verifierDeDejaPris(int valeurDeChoisi, const Plateau& plateau);
int  calculerTotalDesRetenus(int desRetenus[NB_FACES]);
bool verifierPresenceVer(int desRetenus[NB_FACES]);
bool prendrePickominoBrochette(Jeu& jeu);
bool volerPickominoJoueur(Jeu& jeu);
void remettreTuileDansBrochette(Jeu& jeu);
bool verifierValeurTotalDesTropPetit(Plateau& plateau);
bool verifierBrochetteVide(Pickomino (&brochette)[NB_PICKOMINOS]);
void ajouterPartieHistorique(const std::string& nom, int versTotal);
int  choisirFaceAleatoire(Plateau& plateau);

#endif