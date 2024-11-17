#include "Board.h"
#include <iostream>
#include <ctime>
#include <cmath>

Board::Board() {
    int stone = round(0.5*2); // Calcul du nombre de cases roches par rapport � 2 joueurs
    int exchange = round(1.5*2); // Calcul du nombre de cases coupons par rapport � 2 joueurs
    int robbery = 2; // Calcul du nombre de cases vol par rapport � 2 joueurs
    int x;

    std::srand(std::time(nullptr)); // Initialisation de la g�n�ration

    cellules = std::vector<std::vector<char>>(20, std::vector<char>(20, '.'));

    for (int i = 0; i < 20; ++i) { // Parcours du tableau
        for (int j = 0; j < 20; ++j) {
            if (i != 0 && i != 19 && j != 0 && j != 19){ // Choisi al�atoirement un nombre entre 1 et 4 et si c'est 4 une case "roche" est plac�e (ne peut pas �tre plac� sur les bords)
                x = std::rand() % 4 + 1;
                if (x == 4 && stone > 0){
                    cellules[i][j] = 'S';
                    stone--;
                }else if (x == 3 && exchange > 0){
                    cellules[i][j] = 'E';
                    exchange--;
                }else if (x == 2 && robbery > 0){
                    cellules[i][j] = 'R';
                    robbery--;
                }
            }
        }
    }
}

Board::Board(int NumberPlayer) {
    int stone = round(0.5*NumberPlayer); // Calcul du nombre de cases roches par rapport au nombre de joueurs
    int exchange = round(1.5*NumberPlayer); // Calcul du nombre de cases coupons par rapport au nombre de joueurs
    int robbery = NumberPlayer; // Calcul du nombre de cases vol par rapport au nombre de joueurs
    int x;

    std::srand(std::time(nullptr)); // Initialisation de la g�n�ration

    cellules = std::vector<std::vector<char>>(20, std::vector<char>(20, '.'));

    for (int i = 0; i < 20; ++i) { // Parcours du tableau
        for (int j = 0; j < 20; ++j) {
            if (i != 0 && i != 19 && j != 0 && j != 19){ // Choisi al�atoirement un nombre entre 1 et 4 et si c'est 4 une case "roche" est plac�e (ne peut pas �tre plac� sur les bords)
                x = std::rand() % 4 + 1;
                if (x == 4 && stone > 0){
                    cellules[i][j] = 'S';
                    stone--;
                }else if (x == 3 && exchange > 0){
                    cellules[i][j] = 'E';
                    exchange--;
                }else if (x == 2 && robbery > 0){
                    cellules[i][j] = 'R';
                    robbery--;
                }
            }
        }
    }
}

//retourne le double vecteur de cellules (en gros le tableau)
std::vector<std::vector<char>>& Board::getBoard(){
    return cellules;
}

void Board::displayGrid() {
    std::cout << "  ";
    for (char letter_line = 'A'; letter_line <= 'T'; ++letter_line) {
        std::cout << letter_line << " ";
    }
    std::cout << std::endl;
    char letter_col = 'A';
    for (int i = 0; i < 20; ++i) {
        std::cout << letter_col << " ";
        letter_col++;
        for (int j = 0; j < 20; ++j) {
            std::cout << cellules[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
