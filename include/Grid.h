#ifndef GRID_H
#define GRID_H

#include "Ship.h"
class Grid
{
    public:
    char cells[10][10];  // Grille de 10x10
    Ship* ships[5];  // Tableau pour stocker les bateaux

    Grid();
    void placeShip(Ship* ship); //placer les navires sur la grille
    bool checkHit(int row, int col); //v�rifie si le navire est touch�
    void displayGrid(); //affiche la grille
};

#endif // GRID_H
