#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "Tile.h"

class Board
{
    public:
    char cellules[20][20];  // Grille de 10x10
    Tile* tile[96];  // Tableau pour stocker les pièces

    Board();
    Board(int NumberPlayer);
    void displayGrid(); //affiche la grille
};


#endif // BOARD_H_INCLUDED
