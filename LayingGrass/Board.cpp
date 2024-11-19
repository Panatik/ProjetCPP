#include "Board.h"
#include <iostream>
#include <ctime>
#include <cmath>

Board::Board() {
    int stone = round(0.5*2); // Calcul du nombre de cases roches par rapport à 2 joueurs
    int exchange = round(1.5*2); // Calcul du nombre de cases coupons par rapport à 2 joueurs
    int robbery = 2; // Calcul du nombre de cases vol par rapport à 2 joueurs
    int x;
    sizeBoard = 20;

    std::srand(std::time(nullptr)); // Initialisation de la génération

    cellules = std::vector<std::vector<char>>(20, std::vector<char>(20, '.'));

    for (int i = 0; i < sizeBoard; ++i) { // Parcours du tableau
        for (int j = 0; j < sizeBoard; ++j) {
            if (i != 0 && i != sizeBoard - 1 && j != 0 && j != sizeBoard - 1){ // Choisi aléatoirement un nombre entre 1 et 4 et si c'est 4 une case "roche" est placée (ne peut pas être placé sur les bords)
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

    std::srand(std::time(nullptr)); // Initialisation de la génération

    //créer le plateau en fonction du nombre de joueurs
    if(NumberPlayer <= 4){
        sizeBoard = 20;
    }else{
        sizeBoard = 30;
    }
    cellules = std::vector<std::vector<char>>(sizeBoard, std::vector<char>(sizeBoard, '.'));

    for (int i = 0; i < sizeBoard; ++i) { // Parcours du tableau
        for (int j = 0; j < sizeBoard; ++j) {
            if (i != 0 && i != sizeBoard - 1 && j != 0 && j != sizeBoard - 1){ // Choisi aléatoirement un nombre entre 1 et 4 et si c'est 4 une case "roche" est placée (ne peut pas être placé sur les bords)
                x = std::rand() % 20 + 1;
                if (x == 20 && stone > 0){
                    cellules[i][j] = 'S';
                    stone--;
                }else if (x == 19 && exchange > 0){
                    cellules[i][j] = 'E';
                    exchange--;
                }else if (x == 18 && robbery > 0){
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

int Board::getSize(){
    return sizeBoard;
}

void Board::displayGrid(int NumberPlayer) {
    std::cout << "  ";

    //affiche des lettres pour les lignes
    char letter_line = 'A';
    for (int h = 0; h < sizeBoard; ++h) {
        std::cout << letter_line << " ";
        letter_line++;
    }

    std::cout << std::endl;

    //affiche le plateau + des lettres pour les colonnes
    char letter_col = 'A';
    for (int i = 0; i < sizeBoard; ++i) {
        std::cout << letter_col << " ";
        letter_col++;
        for (int j = 0; j < sizeBoard; ++j) {
            std::cout << cellules[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
