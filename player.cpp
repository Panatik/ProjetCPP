#include <iostream>
#include "player.h"
#include <vector>
#include <algorithm>
using namespace std;

player::player(string playerColor, string playerName, int nbcoupon){
    color = playerColor;
    name = playerName;
    coupon = nbcoupon;

}
void player::chooseName(){
    string nameChoose;
    cout<<"Enter your pseudonym here : ";
    cout<<endl;
    cin>>nameChoose;
    name = nameChoose;
}

string player::chooseColor(vector<string>& vectorColors){
    int index = 1;
    int result;
    for(vector<string>::iterator it = vectorColors.begin(); it != vectorColors.end(); ++it){
        cout<<*it<< "color "<< "\033[0m" << index <<endl;
        index +=1 ;
    }
    cout<< "\033[0m" <<"enter the index of the color wanted : ";
    cin>>result;
    color = vectorColors[result - 1];

    return color;
}
string player::getName(){
    return name;
}
string player::getColor(){
    return color;
}
int player::getCoupon(){
    return coupon;
}
