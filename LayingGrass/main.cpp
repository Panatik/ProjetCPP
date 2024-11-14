#include <iostream>
#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "Tile.h"
#include <windows.h>

using namespace std;

int main()
{
    // Active le support des codes ANSI
    SetConsoleOutputCP(CP_UTF8);  // Active la sortie en UTF-8 (pour les Windows il peut y en avoir besoin)
    system("color"); // Activer le support des couleurs ANSI

    int nb; //int pour le nombre de joueurs
    cout << "How many players ? (9 max)" << endl;
    cin >> nb;
    while(nb < 2 || nb > 9){ //message d'erreur pour obliger à mettre entre 2 et 9 joueurs
        cout << "/!\\ Only between 2 and 9 players !" << endl;
        cin >> nb;
    }
    Game test(nb); //création d'une variable type Game avec le nombre de joueurs en paramètres
    test.displayPlayers(); //test pour afficher les utilisateurs
    return 0;
}
