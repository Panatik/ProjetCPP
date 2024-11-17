#include <iostream>
#include "tile.h"
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <cstdlib>
#define RESET   "\033[0m"

using namespace std;

// Constructeur de la classe tile : initialise les attributs de la tuile
tile::tile(int game_index, char co_x, char co_y, string file_tile, vector<int> game_Vector_Tile, vector<vector<char>> first_Tile) {
    index = game_index;
    x = co_x;
    y = co_y;
    ftile = file_tile;
    firstTile = first_Tile;
    gameVectorTile = game_Vector_Tile;
}

// Méthode recupTiles : charge des tuiles depuis un fichier et les stocke dans un dictionnaire
map<int, vector<vector<char>>> tile::recupTiles() {
    ifstream fichier(ftile);
    if (!fichier.is_open()) {
        cerr << "Erreur" << endl; // Affiche un message d'erreur si le fichier ne peut pas être ouvert
    }
    string line;
    vector<vector<char>> colonne;
    map<int, vector<vector<char>>> dictionnaireTiles;
    int i = 0;
    int key = 1;
    while (getline(fichier, line)) {
        if (i < 5) {
            vector<char> ligne;
            for (int loop = 0; loop < 5; loop++) {
                ligne.push_back(line[loop]);
            }
            colonne.push_back(ligne);
            if (i == 4) { // Chaque 5 lignes représente une tuile
                dictionnaireTiles[key] = colonne;
                colonne.clear();
                key += 1;
            }
            i += 1;
        } else if (i == 6) {
            i = 0; // Reset après un espace entre les tuiles dans le fichier
        } else {
            i += 1;
        }
    }
    fichier.close();
    return dictionnaireTiles;
}

// Méthode placeableTile : vérifie si une tuile peut être placée à une position spécifique sur le plateau
bool tile::placeableTile(vector<vector<char>> &board, vector<vector<char>> &tile, char x, char y, int sizeboard, bool isFirstTile, int tour) {
    char joueur = to_string(tour + 1)[0];
    x = int(x) - 'A';
    y = int(y) - 'A';
    int offsetX = -1;
    int offsetY = -1;

    // Cherche la première occurrence de '1' dans la tuile pour définir l'origine de placement
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (tile[i][j] == '1') {
                offsetX = i;
                offsetY = j;
                break;
            }
        }
        if (offsetX != -1) {
            break;
        }
    }

    // Vérifie que la tuile ne sort pas du plateau et ne se superpose pas avec une autre tuile
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (tile[i][j] == '1') {
                if (board[x + i - offsetX][y + j - offsetY] != '.') {
                    cout << "Someone is already here" << endl;
                    return false;
                }
                if (x + i - offsetX > sizeboard || x + i - offsetX < 0 || y + j - offsetY > sizeboard || y + j - offsetY < 0) {
                    return false;
                }
            }
        }
    }

    // Vérifie que la tuile touche une autre tuile du même joueur (sauf si c'est la première tuile)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (tile[i][j] == '1' && !isFirstTile) {
                if ((board[x + i - 1 - offsetX][y + j - offsetY] == joueur) ||
                    (board[x + i + 1 - offsetX][y + j - offsetY] == joueur) ||
                    (board[x + i - offsetX][y + j - 1 - offsetY] == joueur) ||
                    (board[x + i - offsetX][y + j + 1 - offsetY] == joueur)) {
                    return true;
                }
            }
        }
    }

    // La première tuile peut toujours être placée n'importe où
    if (isFirstTile) {
        return true;
    } else {
        return false;
    }
}

// Méthode choosePlaceTile : invite le joueur à entrer les coordonnées pour placer une tuile
void tile::choosePlaceTile(string name) {
    cout << name << ", place your tile (X Y): " << RESET;
    cin >> x >> y;
}

// Méthode placeTile : place la tuile sur le plateau de jeu
vector<vector<char>> tile::placeTile(vector<vector<char>>& board, vector<vector<char>>& tuile, char x, char y, int tour) {
    x = int(x) - 'A';
    y = int(y) - 'A';
    int offsetX = -1;
    int offsetY = -1;

    // Cherche la première occurrence de '1' dans la tuile pour définir l'origine de placement
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (tuile[i][j] == '1') {
                offsetX = i;
                offsetY = j;
                break;
            }
        }
        if (offsetX != -1) {
            break;
        }
    }

    // Place la tuile sur le plateau
    char joueur = to_string(tour + 1)[0];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (x + i - offsetX < board.size() && y + j - offsetY < board[0].size()) {
                if (tuile[i][j] == '1') {
                    board[x + i - offsetX][y + j - offsetY] = joueur;
                }
            }
        }
    }
    return board;
}

// Accesseur pour la coordonnée x
char tile::getX() {
    return x;
}

// Accesseur pour la coordonnée y
char tile::getY() {
    return y;
}

// Accesseur pour obtenir l'index de la tuile
int tile::getIndex() {
    return index;
}

// Mutateur pour augmenter l'index
void tile::setIndex(int increment) {
    index += increment;
}

// Réinitialise l'index si nécessaire
void tile::resetIndex() {
    if (index == gameVectorTile.size() - 1) {
        index = 0;
    }
}

// Accesseur pour la première tuile
vector<vector<char>>& tile::getfirstTile() {
    return firstTile;
};

// Initialise le vecteur des indices des tuiles
void tile::setGameVectorTile(int sizeVector) {
    vector<int> vecteur;
    for (int i = 1; i < 96; ++i) {
        vecteur.push_back(i);
    }
    for (int loop = 1; loop < 96 - sizeVector; loop++) {
        int Vsize = vecteur.size();
        int sup_num = rand() % Vsize + 1;
        gameVectorTile.push_back(vecteur[sup_num]);
        vecteur.erase(vecteur.begin() + sup_num - 1);
    }
}

// Accesseur pour obtenir le vecteur des tuiles de jeu
vector<int> tile::getGameVectorTile() {
    return gameVectorTile;
}

// Affiche la tuile courante à partir d'un index et d'un dictionnaire de tuiles
void tile::displayCurrentTile(int index, map<int, vector<vector<char>>> dicoTiles) {
    for (int loop = 0; loop < 5; loop++) {
        for (int loop2 = 0; loop2 < 5; loop2++) {
            if (dicoTiles[gameVectorTile[index]][loop][loop2] == '1') {
                cout << "\u25A0" << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

// Effectue une rotation de 90 degrés vers la gauche sur la tuile
void tile::rotation90DegreesLeft(vector<vector<char>>& initialTile) {
    vector<vector<char>> rotatedLeft(5, vector<char>(5, '0'));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rotatedLeft[5 - j - 1][i] = initialTile[i][j];
        }
    }
    initialTile = rotatedLeft;
}

// Effectue une rotation de 90 degrés vers la droite sur la tuile
void tile::rotation90DegreesRight(vector<vector<char>>& initialTile) {
    vector<vector<char>> rotatedRight(5, vector<char>(5, '0'));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rotatedRight[j][5 - i - 1] = initialTile[i][j];
        }
    }
    initialTile = rotatedRight;
}

// Retourne la tuile horizontalement
void tile::flip(vector<vector<char>>& initialTile) {
    vector<vector<char>> flipped(5, vector<char>(5, '0'));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            flipped[i][5 - j - 1] = initialTile[i][j];
        }
    }
    initialTile = flipped;
}

// Permet au joueur de choisir une nouvelle tuile par échange
void tile::exchangeCoupon() {
    int new_index = 8;
    cout << "Enter the index of the tile wanted from 1 to 5" << endl;
    while (new_index < 0 || new_index > 5) {
        cout << "Enter a valid number" << endl;
        cin >> new_index;
    }
    for (int i = 1; i < new_index + 1; i++) {
        index += 1;
        if (index == gameVectorTile.size()) {
            index = 0;
        }
    }
}
