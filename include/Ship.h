#ifndef SHIP_H
#define SHIP_H


class Ship
{   public:
    int size;
    int row, col;  // Position du bateau sur la grille
    bool isHorizontal;
    bool isSunk; //indique si le navire est coul�

    Ship(int size, int row, int col, bool isHorizontal);

    bool checkHit(int hitRow, int hitCol); //v�rifie si le navire a �t� touch�
    void markAsSunk(); //marque le navire "coul�"
};

#endif // SHIP_H
