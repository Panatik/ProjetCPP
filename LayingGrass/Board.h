#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "tile.h"

class Board
{
    public:
    std::vector<std::vector<char>> cellules;  // Grille de 10x10
    int sizeBoard;

    Board();
    Board(int NumberPlayer);
    std::vector<std::vector<char>>& getBoard(); //retourne le plateau
    int getSize(); //retourne la taille
    void displayGrid(int NumberPlayer); //affiche la grille
};


#endif // BOARD_H_INCLUDED
