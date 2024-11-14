#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>

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
    board.displayGrid();
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
            cout << "Player " << i+1 << " :" << endl;
            nbPlayers.emplace_back(vectorColors); //emplace_back rajoute à la fin de la liste du vecteur les informations que l'utilisateur est en train de rentrer
    }

    //construction de la grille
    board = Board(number); //appel du constructeur de Board.cpp
    board.displayGrid(); //affiche la grille
}

void Game::displayPlayers(){ //affiche les joueurs
    int a = 0;
    for(int i = 0; i < nbPlayers.size(); i++){ //parcours du vecteur nbPlayers selon sa taille pour afficher son nom selon sa couleur
        cout << nbPlayers[i].getColor() << "- Player " << i+1 << " (" << nbPlayers[i].getName() << ")" << "\033[0m" << endl;
    }
    cout << "Everybody have " << nbPlayers[a].getCoupon() << " Tile exchange coupon." << endl;
}

