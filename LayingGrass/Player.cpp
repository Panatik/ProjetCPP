#include <iostream>
#include "Player.h"
#include <vector>
#include <algorithm>
using namespace std;

Player::Player(vector<string>& vectorColors){
    //appel des méthodes pour initialiser
    chooseName();
    chooseColor(vectorColors);
    coupon = 1;
}

void Player::chooseName(){
    //choix du nom
    string nameChoose;
    cout << " - Enter your pseudonym here : ";
    cin>>nameChoose;
    name = nameChoose;
}

string Player::chooseColor(vector<string>& vectorColors) {
    int result;
    //demande l'index du vecteur de codes couleurs
    cout << " - Enter the index of the color you want: ";
    cin >> result;

    // Vérifie que l'index est valide sinon il redemande à l'utilisateur
    while(result <= 0 || result > vectorColors.size()){
        cout << "/!\\ Invalid choice, you need to put an index between 1 and " << vectorColors.size() << ": ";
        cin >> result;
    }
    color = vectorColors[result - 1];

    return color;
}

string Player::getName(){
    return name;
}
string Player::getColor(){
    return color;
}
int Player::getCoupon(){
    return coupon;
}
