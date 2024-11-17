#include <iostream>
#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "Tile.h"
#include <windows.h>
#include <string>

using namespace std;

int PlayersNumber(){ //fonction qui vérifie l'entrée de l'utilisateur dans un string jusqu'à que ce soit un int entre 2 et 9
    string nb;

    while(true){
        cout << "How many players ? (9 max) :" << endl << "> ";
        cin >> nb;

        try{
            int number = stoi(nb); //convertit le string nb en int dans number
            if(number >= 2 && number <= 9){
                return number;
            } else {
                cout << "/!\\ Only number between 2 and 9 !" << endl;
            }
        } catch (const std::invalid_argument&) {
            cout << "/!\\ Only number !" << endl;
        } catch (const std::out_of_range&) {
            cout << "/!\\ Only number between 2 and 9 !" << endl;
        }
    }
}

int main()
{
    // Active le support des codes ANSI
    SetConsoleOutputCP(CP_UTF8);  // Active la sortie en UTF-8 (pour les Windows il peut y en avoir besoin)
    system("color"); // Activer le support des couleurs ANSI

    //demande le nombre de joueurs

    int number = PlayersNumber();

    Game test(number); //création d'une variable type Game avec le nombre de joueurs en paramètres
    //test.displayPlayers(); //test pour afficher les utilisateurs
    test.FirstRound(); //lance le premier tour pour placer la tuile 1x1

    return 0;
}
