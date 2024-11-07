#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Board.h"

class Player {
public:
    Board board; // Le joueur peut se placer sur le plateau
    Tile* tiles[1]; // Pièces du joueur
    string Couleur; // Couleur du joueur
    string Nom; // Nom du joueur
    int coupons;
    int rocher;
    int vol;

    Player();
    //void placeShips(); //le joueur place les navires sur la grille
    //bool attack(Player &opponent, int row, int col); //le joueur attaque l'adversaire
};

#endif // PLAYER_H_INCLUDED
