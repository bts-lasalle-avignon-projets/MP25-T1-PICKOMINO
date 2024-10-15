#ifndef PICKOMINO_H
#define PICKOMINO_H

#define NB_JOUEURS_MIN 2
#define NB_JOUEURS_MAX 7
#define NB_DES 8
#define NB_PICKOMINOS 16
#define VALEUR_PICKOMINOS_MIN 21
#define VALEUR_PICKOMINOS_MAX 36

struct Joueur
{
    int nombreDeJoueurs;
    char nomJoueur[NB_JOUEURS_MAX][7];
    int sommeTotalDes;        
    int versTotal;
    int pilePickomino[NB_PICKOMINOS];
    int sommetPile;  
};

extern Joueur joueur;

struct Pickomino {
    int valeur;
    int nombreVers;    
};

const Pickomino brochettePickominos[NB_PICKOMINOS] = {
    {21, 1}, {22, 1}, {23, 1}, {24, 1},
    {25, 2}, {26, 2}, {27, 2}, {28, 2},
    {29, 3}, {30, 3}, {31, 3}, {32, 3},
    {33, 4}, {34, 4}, {35, 4}, {36, 4}
};

#endif