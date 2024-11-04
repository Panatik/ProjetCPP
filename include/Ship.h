#ifndef SHIP_H
#define SHIP_H


class Ship
{   public:
    int size;
    int row, col;  // Position du bateau sur la grille
    bool isHorizontal;
    bool isSunk; //indique si le navire est coulé

    Ship(int size, int row, int col, bool isHorizontal);

    bool checkHit(int hitRow, int hitCol); //vérifie si le navire a été touché
    void markAsSunk(); //marque le navire "coulé"
};

#endif // SHIP_H
