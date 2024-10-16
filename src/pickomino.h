#ifndef PICKOMINO_H
#define PICKOMINO_H

#include <string>

#define NB_JOUEURS_MIN 2
#define NB_JOUEURS_MAX 7
#define NB_DES 8
#define NB_FACES 6
#define NB_PICKOMINOS 16
#define VALEUR_PICKOMINOS_MIN 21
#define VALEUR_PICKOMINOS_MAX 36

struct Joueur
{
    char nomJoueur[NB_JOUEURS_MAX];
    int sommeTotalDes;        
    int versTotal;
    int pilePickomino[NB_PICKOMINOS];
    int sommetPile;  
};

struct Plateau
{
    const int brochettePickominos[NB_PICKOMINOS];
};

enum Etat
{
    VISIBLE,
    RETOURNE,
    PRISE
};

struct Pickomino
{
    int valeur;
    int nombreVers;
    enum Etat etat;
};

#endif