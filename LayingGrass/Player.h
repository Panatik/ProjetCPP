#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <vector>

class Player
{
private:
    std::string color;
    std::string name;
    int coupon;
public:

    Player() = default; //constructeur par défaut
    Player(std::vector<std::string>& vectorColors); //constructeur
        void place();
        void exchange();
        void chooseName();
        std::string getColor();
        std::string getName();
        std::string chooseColor(std::vector<std::string>& vectorColors);
        int getCoupon();

};

#endif // PLAYER_H_INCLUDED
