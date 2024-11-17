#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <vector>

#include "Tile.h"
#include "Board.h"
#include "Player.h"

using namespace std;

class Game
{
public:
    Board board;
    vector<Player> nbPlayers; // Vecteur d'entier pour le nombre de joueur
    tile alltiles;

    Game(); //constructeur par défaut (2 joueurs)
    Game(int number); //constructeur
    void FirstRound();
    void displayPlayers(); //méthode qui affiche les joueurs
    //void placeTiles(Ship* ship); //placer les tuiles sur la grille
    void victory(std::vector<std::vector<char>>& board);
    char determineWinner(std::vector<std::vector<char>> &boardGame, int sizeboard);
};

#endif // GAME_H_INCLUDED
