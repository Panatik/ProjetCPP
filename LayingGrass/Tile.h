#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED


class Tile
{   public:
    int x, y;  // Position de la pi�ce sur la grille
    bool Placement; // Booleen pour savoir s'il faut faire une rotation
    bool IsSet; // Savoir si la pi�ce � �t� utilis�

    Ship(int size, int row, int col, bool isHorizontal);

    bool checkHit(int hitRow, int hitCol); //v�rifie si le navire a �t� touch�
    void markAsSunk(); //marque le navire "coul�"
};

#endif // TILE_H_INCLUDED
