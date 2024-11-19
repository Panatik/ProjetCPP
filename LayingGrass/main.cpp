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



// Fonction pour déterminer et afficher le gagnant de la partie.
void victory(vector<vector<char>>& boardGame, vector<Player> players, Game& ourgame, int& sizeboard) {
    // Appelle une méthode pour déterminer le gagnant.
    char winner = ourgame.determineWinner(boardGame, sizeboard);

    // Convertit le caractère gagnant en un indice de joueur (ex: '1' -> index 0).
    int joueur = winner - '1';

    if (winner != '.') { // Vérifie s'il y a un gagnant ('.' signifie égalité ou aucune victoire).
        cout << "the player " << players[joueur].getName() << " won the game" << endl;
    } else { // S'il n'y a pas de gagnant, la partie est une égalité.
        cout << "La partie se termine par une égalité.\n";
    }
}

// Fonction qui gère la fin de partie, y compris l'utilisation d'un "coupon" pour placer une tuile bonus.
void end_game(tile& Newtiles, map<int, vector<vector<char>>>& dicoTiles, vector<vector<char>>& boardGame, int& sizeboard, int& nbplayer, vector<Player>& players, Game& ourgame, Board& gameboard) {
    cout << "--- END GAME ---" << endl;
    cout << endl;

    // Affiche le plateau de jeu final avec les informations des joueurs.
    gameboard.display(boardGame, sizeboard, players);

    // Parcours les joueurs pour vérifier s'ils possèdent un "coupon".
    for (int loop = 0; loop < nbplayer; loop++) {
        if (players[loop].getCoupon() == 1) { // Si le joueur possède un coupon.
            char lettre = 'A'; // Variable pour stocker la réponse du joueur.
            cout << players[loop].getName() << ": You still have your coupon" << endl;
            cout << "Enter U to use it, and place a 1*1 tile" << endl;
            cout << "Enter N if you don't want to use it" << endl;

            // Boucle jusqu'à ce que le joueur saisisse une réponse valide ('U' ou 'N').
            while (lettre != 'U' && lettre != 'N') {
                cin >> lettre;
            }

            if (lettre == 'U') { // Si le joueur décide d'utiliser son coupon.
                system("cls"); // Efface la console (peut être dépendant du système d'exploitation).
                gameboard.display(boardGame, sizeboard, players); // Affiche à nouveau le plateau de jeu.

                bool placeable = false; // Variable pour vérifier si le placement est valide.
                vector<vector<char>> lastTile = Newtiles.getfirstTile(); // Obtient la dernière tuile du joueur.

                // Boucle jusqu'à ce qu'un placement valide soit trouvé.
                while (!placeable) {
                    // Demande au joueur de choisir où placer la tuile.
                    Newtiles.choosePlaceTile(players[ourgame.getTurn() % nbplayer].getName());

                    // Vérifie si la tuile peut être placée à l'endroit choisi.
                    placeable = Newtiles.placeableTile(boardGame, dicoTiles[Newtiles.getGameVectorTile()[Newtiles.getIndex()]], Newtiles.getX(), Newtiles.getY(), sizeboard, false, ourgame.getTurn() % nbplayer);
                }

                // Place la tuile sur le plateau de jeu.
                boardGame = Newtiles.placeTile(boardGame, lastTile, Newtiles.getX(), Newtiles.getY(), ourgame.getTurn() % nbplayer);
            }

            // Passe au tour suivant après que le joueur a utilisé (ou non) son coupon.
            ourgame.setTurn();
        }
    }

    // Vérifie et affiche le gagnant après la fin de la partie.
    victory(boardGame, players, ourgame, sizeboard);
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

