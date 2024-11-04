#include "Ship.h"

//constructeur
Ship::Ship(int size, int row, int col, bool isHorizontal)
    : size(size), row(row), col(col), isHorizontal(isHorizontal), isSunk(false) {}

//checkHit v�rifie si l'attaque a touch� le navire
bool Ship::checkHit(int hitRow, int hitCol) {
    if (isHorizontal) {
        return (hitRow == row && hitCol >= col && hitCol < col + size);
    } else {
        return (hitCol == col && hitRow >= row && hitRow < row + size);
    }
}

//Marqu� le navire coul�
void Ship::markAsSunk() {
    isSunk = true;
}
