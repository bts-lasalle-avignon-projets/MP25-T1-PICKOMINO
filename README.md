# Mini-projet : Pickomino

- [Mini-projet : Pickomino](#mini-projet--pickomino)
  - [Présentation](#présentation)
  - [Utilisation](#utilisation)
  - [Itérations](#itérations)
    - [Itération 1](#itération-1)
    - [Itération 2](#itération-2)
    - [Itération 3](#itération-3)
  - [Changelog](#changelog)
  - [TODO](#todo)
  - [Défauts constatés non corrigés](#défauts-constatés-non-corrigés)
  - [Équipe de développement](#équipe-de-développement)

---

## Présentation

Pickomino est un jeu de société créé par Reiner Knizia et édité par Gigamic, qui se joue avec 2 ou 7 joueurs maximum.

Le but du jeu est d'avoir plus de vers que ces adversaires pour remporter la partie.

Le jeu est composé de 16 pickominos (tuiles), de 21 à 36 :

- Les tuiles de 21 à 24 valent 1 ver
- Les tuiles de 25 à 28 valent 2 vers
- Les tuiles de 29 à 32 valent 3 vers
- Les tuiles de 33 à 36 valent 4 vers

Le jeu est composé de 2 zones distinctes :

- L'inventaire de chaque joueur
- Le plateau de jeu

### L'inventaire du joueur

- Stockage des pickominos gagnés sous forme de pile
- Échange des pickominos perdus

### Le plateau de jeu

- Brochette de tous les pickominos
- 8 dés de 6 faces

### Déroulement d'une partie

Pour commencer une partie, c'est le joueur le plus jeune qui débute.

Le premier joueur lance les 8 dés. Il doit choisir parmi les dés le symbole qui lui convient et mettre de côté tous les dés ayant le même symbole.

À chaque lancer, l'action est répétée, sauf qu'il doit choisir un symbole qu'il n'a pas choisi auparavant. :warning: Le joueur doit impérativement mettre de côté au moins un dé avec le symbole « ver » pour valider son tour et récupérer une tuile correspondant à la valeur totale de tous ses dés.

- Face 1 = 1 point
- Face 2 = 2 points
- Face 3 = 3 points
- Face 4 = 4 points
- Face 5 = 5 points
- Face « ver » = 5 points

Si, à l'issue des lancers, le joueur ne peut pas prendre de tuile ou n'a pas obtenu de « ver », il doit remettre sa dernière tuile obtenue dans la brochette sur le plateau de jeu, et la tuile de plus haute valeur est retournée (retirée du jeu).

La partie se termine quand toutes les tuiles ont été prises. Chaque joueur compte le nombre de vers présents sur l'ensemble de ses tuiles. Le joueur ayant le plus de vers remporte la partie.

## Utilisation

```bash
$ make

$ ./pickomino.out
```

![](./images/pickomino.gif)

---

## Itérations

### Itération 1 :

- Créer le squelette des fichiers
- Lancer une partie :
  - Saisir le nombre de joueurs
  - Saisir le nom du joueur
- Jouer une partie :
  - Lancer les dés 
  - Récupérer les tuiles
  - Récupérer un pickomino dans l'inventaire d'un joueur adverse (becquetage)
- Terminer une partie :
  - Afficher le gagnant

### Itération 2 :

- Jouer une partie contre la machine
- Jouer une ou plusieurs parties
- Visualiser l'historique des parties

### Itération 3 :

- Visualiser l'historique des scores
- Jouer une partie en réseau

## Changelog

## TODO

## Défauts constatés non corrigés

## Équipe de développement

- MILLOT Pierre : [**[pierre(dot)millot(dot)pro(at)gmail(dot)com](mailto:pierre.millot.pro@gmail.com)**]

- NAVARRO Mattéo : [**[matteo(dot)navarro(dot)pro(at)gmail(dot)com](mailto:matteo.navarro.pro@gmail.com)**]

---
&copy; 2024-2025 LaSalle Avignon
