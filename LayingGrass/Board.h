#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "Tile.h"

class Board
{
    public:
    char cellules[20][20];  // Grille de 10x10
    Tile* tile[96];  // Tableau pour stocker les pi�ces

    Board();
    //void placeShip(Ship* ship); //placer les navires sur la grille
    //bool checkHit(int row, int col); //v�rifie si le navire est touch�
    void displayGrid(); //affiche la grille
};


#endif // BOARD_H_INCLUDED
