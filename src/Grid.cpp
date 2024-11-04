#include "Grid.h"
#include <iostream>

Grid::Grid() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cells[i][j] = '.';  // '.' repr�sente de l'eau
        }
    }
}

void Grid::placeShip(Ship* ship) {
    if (ship->isHorizontal) {
        for (int i = 0; i < ship->size; ++i) {
            cells[ship->row][ship->col + i] = 'S';  // 'S' repr�sente un bateau
        }
    } else {
        for (int i = 0; i < ship->size; ++i) {
            cells[ship->row + i][ship->col] = 'S';
        }
    }
}

bool Grid::checkHit(int row, int col) {
    if (cells[row][col] == 'S') {
        cells[row][col] = 'X';  // 'X' repr�sente une touche
        std::cout << "Touch� !\n";
        return true;
    } else {
        cells[row][col] = 'O';  // 'O' repr�sente une attaque rat�e
        std::cout << "� l'eau !\n";
        return false;
    }
}

void Grid::displayGrid() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << cells[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
