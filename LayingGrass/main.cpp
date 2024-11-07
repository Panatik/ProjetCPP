#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    int nbJoueur;
    Board test;

    cout << "Combien de joueurs ? (9 max)" << endl;

    test.displayGrid();

    return 0;
}
