#include <iostream>
#include "Player.h"
using namespace std;

int main()
{
    Player player1, player2;
    int row, col;

    std::cout << "Grille du joueur 1 :\n";
    player1.grid.displayGrid();

    std::cout << "\nGrille du joueur 2 :\n";
    player2.grid.displayGrid();

    while (true) {
        std::cout << "\nJoueur 1, entrez la ligne et la colonne à attaquer (0-9) : ";
        std::cin >> row >> col;
        player1.attack(player2, row, col);
        player2.grid.displayGrid();

        std::cout << "\nJoueur 2, entrez la ligne et la colonne à attaquer (0-9) : ";
        std::cin >> row >> col;
        player2.attack(player1, row, col);
        player1.grid.displayGrid();
    }
    return 0;
}
