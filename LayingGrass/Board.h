#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#define RESET   "\033[0m"

#include "Tile.h"
#include "Player.h"

class Board
{
    public:
    std::vector<std::vector<char>> cellules;  // Grille de 10x10
    int sizeBoard;

    Board();
    Board(int NumberPlayer);
    std::vector<std::vector<char>>& getBoard(); //retourne le plateau
    int getSize(); //retourne la taille
    void displayGrid(); //affiche la grille

};


#endif // BOARD_H_INCLUDED

