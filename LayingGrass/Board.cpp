#include "Board.h"
#include <iostream>
#include <ctime>
#include <cmath>

Board::Board() {
    int stone = round(0.5*2); // Calcul du nombre de cases roches par rapport à 2 joueurs
    int exchange = round(1.5*2); // Calcul du nombre de cases coupons par rapport à 2 joueurs
    int robbery = 2; // Calcul du nombre de cases vol par rapport à 2 joueurs
    int x;
    std::srand(std::time(nullptr)); // Initialisation de la génération
    for (int i = 0; i < 20; ++i) { // Parcours du tableau
        for (int j = 0; j < 20; ++j) {
            if (i != 0 && i != 19 && j != 0 && j != 19){ // Choisi aléatoirement un nombre entre 1 et 4 et si c'est 4 une case "roche" est placée (ne peut pas être placé sur les bords)
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
                }else{
                    cellules[i][j] = '.';
                }
            }else{
                cellules[i][j] = '.';
            }
        }
    }
}

Board::Board(int NumberPlayer) {
    int stone = round(0.5*NumberPlayer); // Calcul du nombre de cases roches par rapport au nombre de joueurs
    int exchange = round(1.5*NumberPlayer); // Calcul du nombre de cases coupons par rapport au nombre de joueurs
    int robbery = NumberPlayer; // Calcul du nombre de cases vol par rapport au nombre de joueurs
    int x;
    std::srand(std::time(nullptr)); // Initialisation de la génération
    for (int i = 0; i < 20; ++i) { // Parcours du tableau
        for (int j = 0; j < 20; ++j) {
            if (i != 0 && i != 19 && j != 0 && j != 19){ // Choisi aléatoirement un nombre entre 1 et 4 et si c'est 4 une case "roche" est placée (ne peut pas être placé sur les bords)
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
                }else{
                    cellules[i][j] = '.';
                }
            }else{
                cellules[i][j] = '.';
            }
        }
    }
}

void Board::displayGrid() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            std::cout << cellules[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
