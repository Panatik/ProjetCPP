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
    cout << "Enter your pseudonym here :" << endl << "> ";
    cin>>nameChoose;
    name = nameChoose;
}

string Player::chooseColor(vector<string>& vectorColors) {

    //transforme le string en int
    int result = IndexNumber();
    color = vectorColors[result - 1];

    return color;
}

int Player::IndexNumber(){ //fonction qui vérifie l'entrée de l'utilisateur dans un string jusqu'à que ce soit un int entre 2 et 9
    string resultStr;

    while(true){
        cout << "Enter the index of the color you want :" << endl << "> ";
        cin >> resultStr;

        try{
            int number = stoi(resultStr); //convertit le string nb en int dans number
            if(number >= 1 && number <= 7){
                return number;
            } else {
                cout << "/!\\ Only number between 1 and 7 !" << endl;
            }
        } catch (const std::invalid_argument&) {
            cout << "/!\\ Only number !" << endl;
        } catch (const std::out_of_range&) {
            cout << "/!\\ Only number between 1 and 7 !" << endl;
        }
    }
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
