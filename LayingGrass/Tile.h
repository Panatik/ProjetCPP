#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED


class Tile
{   public:
    int x, y;  // Position de la pièce sur la grille
    bool Placement; // Booleen pour savoir s'il faut faire une rotation
    bool IsSet; // Savoir si la pièce à été utilisé

    Ship(int size, int row, int col, bool isHorizontal);

    bool checkHit(int hitRow, int hitCol); //vérifie si le navire a été touché
    void markAsSunk(); //marque le navire "coulé"
};

#endif // TILE_H_INCLUDED
