#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <vector>

#include "Tile.h"
#include "Board.h"
#include "Player.h"

using namespace std;

class Game
{
    private:
            int nbplayer;
            int turn;
    public:
        Board board;
        game(int player, int actualTurn = 0);
        vector<Player> nbPlayers; // Vecteur d'entier pour le nombre de joueur
        tile alltiles;
        std::vector<std::vector<char>> createBoard(int& boardSize);
        Game(); //constructeur par défaut (2 joueurs)
        Game(int number); //constructeur
        void FirstRound();
        void displayPlayers(); //méthode qui affiche les joueurs
        //void placeTiles(Ship* ship); //placer les tuiles sur la grille
        void nextTile();
        void setTurn();
        int getTurn();
        void victory(std::vector<std::vector<char>>& board,vector<Player> players, Game& ourgame, int& sizeboard);
        char determineWinner(std::vector<std::vector<char>> &boardGame, int sizeboard);

};

#endif // GAME_H_INCLUDED
