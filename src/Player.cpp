#include "Player.h"

#include <iostream>

Player::Player() {
    // Initialiser les 5 bateaux avec des tailles différentes
    ships[0] = new Ship(5, 0, 0, true);  // Bateau de taille 5
    ships[1] = new Ship(4, 2, 2, true);  // Bateau de taille 4
    ships[2] = new Ship(3, 4, 4, true);  // Bateau de taille 3
    ships[3] = new Ship(3, 6, 6, false);  // Bateau de taille 3
    ships[4] = new Ship(2, 8, 8, true);  // Bateau de taille 2

    placeShips();
}

void Player::placeShips() {
    for (int i = 0; i < 5; ++i) {
        grid.placeShip(ships[i]);
    }
}

bool Player::attack(Player &opponent, int row, int col) {
    return opponent.grid.checkHit(row, col);
}
