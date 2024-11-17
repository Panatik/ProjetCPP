#ifndef TILE_H
#define TILE_H
#include <vector>
#include <string>
#include <map>

// Déclaration de la classe tile
class tile
{
    private:
        int index; // Indice ou identifiant de la tuile
        char x; // Coordonnée x de la tuile
        char y; // Coordonnée y de la tuile
        std::string ftile; // Nom du fichier associé à la tuile
        std::vector<std::vector<char>> firstTile; // Structure pour stocker la première tuile de jeu
        std::vector<int> gameVectorTile; // Vecteur pour stocker l'état du jeu associé aux tuiles

    public:
        // Constructeur de la classe tile avec des valeurs par défaut pour les paramètres
        tile(int game_index = 1, char co_x = 'a', char co_y = 'a', std::string file_tile = "message.txt",
             std::vector<int> game_Vector_Tile = {},
             std::vector<std::vector<char>> first_Tile = {{'1','0','0','0','0'},{'0','0','0','0','0'},{'0','0','0','0','0'},{'0','0','0','0','0'},{'0','0','0','0','0'}});

        // Méthode pour choisir la position de la tuile en fonction du nom et de la couleur
        void choosePlaceTile(std::string name);

        // Vérifie si la tuile est plaçable sur le plateau
        bool placeableTile(std::vector<std::vector<char>> &board, std::vector<std::vector<char>> &tile, char x, char y, int sizeboard, bool isFirstTile, int tour);

        // Place la tuile sur le plateau de jeu
        std::vector<std::vector<char>> placeTile(std::vector<std::vector<char>>& board, std::vector<std::vector<char>>& tuile, char x, char y, int tour);

        // Accesseur pour obtenir la coordonnée x
        char getX();

        // Accesseur pour obtenir la coordonnée y
        char getY();

        // Accesseur pour obtenir l'index
        int getIndex();

        // Mutateur pour définir l'index avec un incrément
        void setIndex(int increment);

        // Accesseur pour obtenir la première tuile
        std::vector<std::vector<char>>& getfirstTile();

        // Méthode pour récupérer une collection de tuiles sous forme de dictionnaire (map)
        std::map<int,std::vector<std::vector<char>>> recupTiles();

        // Accesseur pour obtenir le vecteur des tuiles de jeu
        std::vector<int> getGameVectorTile();

        // Définit la taille du vecteur de jeu
        void setGameVectorTile(int sizeVector);

        // Affiche la tuile courante en fonction de l'index et d'un dictionnaire de tuiles
        void displayCurrentTile(int index, std::map<int,std::vector<std::vector<char>>> dicoTiles);

        // Effectue une rotation de 90 degrés vers la gauche sur la tuile
        void rotation90DegreesLeft(std::vector<std::vector<char>>& initialTile);

        // Effectue une rotation de 90 degrés vers la droite sur la tuile
        void rotation90DegreesRight(std::vector<std::vector<char>>& initialTile);

        // Retourne la tuile (symétrie)
        void flip(std::vector<std::vector<char>>& initialTile);

        // Échange un coupon pour une action ou un bonus dans le jeu
        void exchangeCoupon();

        // Réinitialise l'index à sa valeur de départ
        void resetIndex();
};

#endif // TILE_H
