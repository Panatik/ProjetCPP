<<<<<<< HEAD
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
    void displayGrid(int NumberPlayer); //affiche la grille
    void display(const std::vector<std::vector<char>>& board, int& sizeboard, std::vector<Player>& players);
};


#endif // BOARD_H_INCLUDED
=======
#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

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
    void displayGrid(int NumberPlayer); //affiche la grille
    void display(const std::vector<std::vector<char>>& board, int& sizeboard, std::vector<Player>& players);
};


#endif // BOARD_H_INCLUDED
>>>>>>> 95e2ab9f1ddcb97ecb5339147ed3182db26de07e
