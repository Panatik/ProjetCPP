#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <algorithm>

using namespace std;

Game::Game(){
    int index = 1;
    vector<string> ColorList = {"Red", "Blue", "Green", "Yellow", "Cyan", "White", "Violet"};
    vector<string> vectorColors = {"\033[31m", "\033[34m", "\033[32m", "\033[33m", "\033[36m", "\033[37m", "\033[35m"};
    for (const auto& colorlist : ColorList) {
        cout << vectorColors[index-1] << index << ". " << ColorList[index-1] << "\033[0m" << endl;
        index += 1;
    }

    for (int i = 0; i < 2; i++) {
            nbPlayers.emplace_back(vectorColors);
    }
    board = Board(2);
    board.displayGrid(2);
}

Game::Game(int number){
    //affichage des couleurs et index
    int index = 1;
    vector<string> ColorList = {"Red", "Blue", "Green", "Yellow", "Cyan", "White", "Purple"}; //création d'un vecteur de string qui contient les couleurs disponibles pour les montrer à l'utilisateur
    vector<string> vectorColors = {"\033[31m", "\033[34m", "\033[32m", "\033[33m", "\033[36m", "\033[37m", "\033[35m"}; //création d'un 2e vecteur où là y les codes couleurs ANSI et donc ça sera ces codes là que l'utilisateur va choisir en rentrant l'index de la couleur
    for (const auto& colorlist : ColorList) { //permet de parcourir le vecteur
        cout << vectorColors[index-1] << index << ". " << ColorList[index-1] << "\033[0m" << endl; //affiche les couleurs et leurs index à l'aide des 2 vecteurs
        index += 1;
    }

    //construction des joueurs dans le vecteur nbPlayers
    for (int i = 0; i < number; i++) { //pour le nombre de joueurs choisi on va appeler le constructeur de Player.cpp pour initialiser les variables à mettre dans le vecteur nbPlayers
            cout << endl << " - Player " << i+1 << " :" << endl;
            nbPlayers.emplace_back(vectorColors); //emplace_back rajoute à la fin de la liste du vecteur les informations que l'utilisateur est en train de rentrer
    }

    //mélanger aléatoirement le vecteur de joueur
    std::random_shuffle(nbPlayers.begin(), nbPlayers.end());

    //initialisation des tuiles
    alltiles = tile(1, 'a', 'a', "message.txt",
                        {},
                        {{'1', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0'}});
    alltiles.recupTiles(); //recup les tuiles pour les mettres dans alltiles
    alltiles.setGameVectorTile(96); //initialise le vecteur des tuiles à 0 dans alltiles

    //construction de la grille
    board = Board(number); //appel du constructe    ur de Board.cpp
    board.displayGrid(number); //affiche la grille
}

void Game::FirstRound(){

    //boucle selon le nombre de joueurs
    for(int i = 0; i < nbPlayers.size(); i++){
        cout << nbPlayers[i].getColor() << "Player " << i+1 << " (" << nbPlayers[i].getName() << ") - Round 1:" << "\033[0m" << endl;

        //boucle qui demande de placer une tuile jusqu'à que ce soit possible et la pose si c'est bon
        while(true){
            alltiles.choosePlaceTile(nbPlayers[i].getName());

            bool placeable = alltiles.placeableTile(board.getBoard(), alltiles.getfirstTile(), alltiles.getX(), alltiles.getY(), board.getSize(), true, i);

            if(placeable){
                alltiles.placeTile(board.getBoard(), alltiles.getfirstTile(), alltiles.getX(), alltiles.getY(), i);
                break;
            }
        }
        board.displayGrid(nbPlayers.size()); //affiche la grille
    }
}
Game::game(int player, int actualTurn){
    turn = actualTurn;
    nbplayer = player;
}

vector<vector<char>> Game::createBoard(int& sizeBoard) {
    vector<vector<char>> board(sizeBoard, vector<char>(sizeBoard, '.'));
    return board;
}
void Game::setTurn(){
    turn+=1;
}
int Game::getTurn(){
    return turn;
}
void Game::displayPlayers(){ //affiche les joueurs
    int a = 0;
    for(int i = 0; i < nbPlayers.size(); i++){ //parcours du vecteur nbPlayers selon sa taille pour afficher son nom selon sa couleur
        cout << nbPlayers[i].getColor() << "- Player " << i+1 << " (" << nbPlayers[i].getName() << ")" << "\033[0m" << endl;
    }
    cout << "Everybody have " << nbPlayers[a].getCoupon() << " Tile exchange coupon." << endl;
}
char Game::determineWinner(vector<vector<char>> &boardGame, int sizeboard) {
    char winner = '.'; // Par défaut, le gagnant est '.' (aucun gagnant).
    int maxSquareSize = 0; // Taille maximale d'un carré trouvé.

    // Parcourt chaque cellule du plateau.
    for (int i = 0; i < sizeboard; ++i) {
        for (int j = 0; j < sizeboard; ++j) {
            char currentPlayer = boardGame[i][j]; // Récupère le joueur actuel (cellule).

            if (currentPlayer != '.') { // Ignore les cellules vides.
                int squareSize = 1; // Taille initiale du carré.

                // Vérifie si un carré plus grand peut être formé.
                while (i + squareSize < sizeboard && // Assure que le carré reste dans les limites du plateau (en hauteur).
                       j + squareSize < sizeboard && // Assure que le carré reste dans les limites du plateau (en largeur).
                       boardGame[i + squareSize][j] == currentPlayer && // Vérifie si la colonne droite appartient au même joueur.
                       boardGame[i][j + squareSize] == currentPlayer && // Vérifie si la ligne inférieure appartient au même joueur.
                       boardGame[i + squareSize][j + squareSize] == currentPlayer) { // Vérifie si le coin en bas à droite appartient au même joueur.
                    ++squareSize; // Augmente la taille du carré.
                }

                // Met à jour le gagnant si un carré plus grand est trouvé.
                if (squareSize > maxSquareSize) {
                    maxSquareSize = squareSize; // Met à jour la taille maximale du carré.
                    winner = currentPlayer; // Définit le gagnant comme le joueur actuel.
                }
            }
        }
    }

    return winner; // Retourne le gagnant ('1', '2', etc., ou '.' s'il n'y en a pas).
}
