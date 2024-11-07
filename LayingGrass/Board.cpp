#include "Board.h"
#include <iostream>
#include <ctime>
#include <cmath>

Board::Board() {
    int roche = round(0.5*3); // Calcul du nombre de cases roches par rapport à 3 joueurs
    int coupons = round(1.5*3); // Calcul du nombre de cases coupons par rapport à 3 joueurs
    int vol = 3; // Calcul du nombre de cases vol par rapport à 3 joueurs
    int x;
    std::srand(std::time(nullptr)); // Initialisation de la génération
    for (int i = 0; i < 20; ++i) { // Parcours du tableau
        for (int j = 0; j < 20; ++j) {
            if (i != 0 && i != 19 && j != 0 && j != 19){ // Choisi aléatoirement un nombre entre 1 et 4 et si c'est 4 une case "roche" est placée (ne peut pas être placé sur les bords)
                x = std::rand() % 4 + 1;
                if (x == 4 && roche > 0){
                    cellules[i][j] = 'R';
                    roche--;
                }else if (x == 3 && coupons > 0){
                    cellules[i][j] = 'C';
                    coupons--;
                }else if (x == 2 && vol > 0){
                    cellules[i][j] = 'V';
                    vol--;
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
