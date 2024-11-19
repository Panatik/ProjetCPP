#include <iostream>
#include "Board.h"
#include "Game.h"
#include "Player.h"
#include "Tile.h"
#include <windows.h>
#include <string>

using namespace std;

int PlayersNumber(){ //fonction qui v�rifie l'entr�e de l'utilisateur dans un string jusqu'� que ce soit un int entre 2 et 9
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



// Fonction pour d�terminer et afficher le gagnant de la partie.
void victory(vector<vector<char>>& boardGame, vector<Player> players, Game& ourgame, int& sizeboard) {
    // Appelle une m�thode pour d�terminer le gagnant.
    char winner = ourgame.determineWinner(boardGame, sizeboard);

    // Convertit le caract�re gagnant en un indice de joueur (ex: '1' -> index 0).
    int joueur = winner - '1';

    if (winner != '.') { // V�rifie s'il y a un gagnant ('.' signifie �galit� ou aucune victoire).
        cout << "the player " << players[joueur].getName() << " won the game" << endl;
    } else { // S'il n'y a pas de gagnant, la partie est une �galit�.
        cout << "La partie se termine par une �galit�.\n";
    }
}

// Fonction qui g�re la fin de partie, y compris l'utilisation d'un "coupon" pour placer une tuile bonus.
void end_game(tile& Newtiles, map<int, vector<vector<char>>>& dicoTiles, vector<vector<char>>& boardGame, int& sizeboard, int& nbplayer, vector<Player>& players, Game& ourgame, Board& gameboard) {
    cout << "--- END GAME ---" << endl;
    cout << endl;

    // Affiche le plateau de jeu final avec les informations des joueurs.
    gameboard.display(boardGame, sizeboard, players);

    // Parcours les joueurs pour v�rifier s'ils poss�dent un "coupon".
    for (int loop = 0; loop < nbplayer; loop++) {
        if (players[loop].getCoupon() == 1) { // Si le joueur poss�de un coupon.
            char lettre = 'A'; // Variable pour stocker la r�ponse du joueur.
            cout << players[loop].getName() << ": You still have your coupon" << endl;
            cout << "Enter U to use it, and place a 1*1 tile" << endl;
            cout << "Enter N if you don't want to use it" << endl;

            // Boucle jusqu'� ce que le joueur saisisse une r�ponse valide ('U' ou 'N').
            while (lettre != 'U' && lettre != 'N') {
                cin >> lettre;
            }

            if (lettre == 'U') { // Si le joueur d�cide d'utiliser son coupon.
                system("cls"); // Efface la console (peut �tre d�pendant du syst�me d'exploitation).
                gameboard.display(boardGame, sizeboard, players); // Affiche � nouveau le plateau de jeu.

                bool placeable = false; // Variable pour v�rifier si le placement est valide.
                vector<vector<char>> lastTile = Newtiles.getfirstTile(); // Obtient la derni�re tuile du joueur.

                // Boucle jusqu'� ce qu'un placement valide soit trouv�.
                while (!placeable) {
                    // Demande au joueur de choisir o� placer la tuile.
                    Newtiles.choosePlaceTile(players[ourgame.getTurn() % nbplayer].getName());

                    // V�rifie si la tuile peut �tre plac�e � l'endroit choisi.
                    placeable = Newtiles.placeableTile(boardGame, dicoTiles[Newtiles.getGameVectorTile()[Newtiles.getIndex()]], Newtiles.getX(), Newtiles.getY(), sizeboard, false, ourgame.getTurn() % nbplayer);
                }

                // Place la tuile sur le plateau de jeu.
                boardGame = Newtiles.placeTile(boardGame, lastTile, Newtiles.getX(), Newtiles.getY(), ourgame.getTurn() % nbplayer);
            }

            // Passe au tour suivant apr�s que le joueur a utilis� (ou non) son coupon.
            ourgame.setTurn();
        }
    }

    // V�rifie et affiche le gagnant apr�s la fin de la partie.
    victory(boardGame, players, ourgame, sizeboard);
}



int main()
{
    // Active le support des codes ANSI
    SetConsoleOutputCP(CP_UTF8);  // Active la sortie en UTF-8 (pour les Windows il peut y en avoir besoin)
    system("color"); // Activer le support des couleurs ANSI

    //demande le nombre de joueurs

    int number = PlayersNumber();

    Game test(number); //cr�ation d'une variable type Game avec le nombre de joueurs en param�tres
    //test.displayPlayers(); //test pour afficher les utilisateurs
    test.FirstRound(); //lance le premier tour pour placer la tuile 1x1

    return 0;
}

