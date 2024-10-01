# Mini-projet : Pickomino

- [Mini-projet : Pickomino](#mini-projet--pickomino)
  - [Présentation](#présentation)
  - [Utilisation](#utilisation)
  - [Changelog](#changelog)
  - [TODO](#todo)
  - [Défauts constatés non corrigés](#défauts-constatés-non-corrigés)
  - [Équipe de développement](#équipe-de-développement)

---

## Présentation

Pickomino est un jeux de société créer par Gigamic, qui se joue avec 2 ou 7 joueurs maximum. Le but du jeu est d'avoir plus de vers que ces adversaires pour remporter la partie.
Le jeux est composer de 2 zones de jeux distinctes:

- L'inventaire de chaque joueurs.
- Le plateau de jeu.

#### L'inventaire du joueur

- Chaque joueur récupère le pickomino qui viens de remporter et l'empiles au dessus des autres.
- Un joueur peut récupérer le pickomino d'un joueur adverse, si la valeur de ces dès est égale au pickomino du sommet de la pile du joueur adverse.

#### Le plateau de jeu

- Les pickominos sont aligner en ligne de façon croissante (*de 21 à 36*).
- Chaque joueur ayant la valeur d'un pickomino sur la plateau de jeu peut le récupérer.
- Si un joueur fait un tours nul (n'obient pas de pickomino), le dernier pickomino le plus fort sur le plateau est retourner.

### Déroulement d'une partie

### Utilisation

```bash
$ make

$ ./pickomino.out
```

![](./images/pickomino.gif)

## Changelog

## TODO

## Défauts constatés non corrigés

## Équipe de développement

MILLOT Pierre : [**[pierre(dot)millot(dot)pro(at)gmail(dot)com](mailto:pierre.millot.pro@gmail.com)**]
NAVARRO Mattéo : [**[matteo(dot)navarro(dot)pro(at)gmail(dot)com](mailto:matteo.navarro.pro@gmail.com)**]

---
&copy; 2024-2025 LaSalle Avignon
