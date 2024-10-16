#ifndef PICKOMINO_H
#define PICKOMINO_H

#include <string>

#define NB_JOUEURS_MIN 2
#define NB_JOUEURS_MAX 7

#define NB_DES   8
#define NB_FACES 6

#define NB_PICKOMINOS         16
#define VALEUR_PICKOMINOS_MIN 21
#define VALEUR_PICKOMINOS_MAX 36

struct Joueur
{
    std::string nom;
    int         versTotal;
    int         pilePickomino[NB_PICKOMINOS];
    int         sommetPile;
};

enum Etat
{
    VISIBLE,
    RETOURNE,
    PRISE
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

#endif