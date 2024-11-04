#ifndef PLAYER_H
#define PLAYER_H

#include "Grid.h"

class Player {
public:
    Grid grid;
    Ship* ships[5];

    Player();
    void placeShips(); //le joueur place les navires sur la grille
    bool attack(Player &opponent, int row, int col); //le joueur attaque l'adversaire
};
#endif // PLAYER_H
