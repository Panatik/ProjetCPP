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

    Game(); //constructeur par défaut (2 joueurs)
    Game(int number); //constructeur
    void displayPlayers(); //méthode qui affiche les joueurs
    //void placeTiles(Ship* ship); //placer les tuiles sur la grille
};

#endif // GAME_H_INCLUDED
