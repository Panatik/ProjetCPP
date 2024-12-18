#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <vector>

class Player
{
private:
    std::string color;
    std::string name;
public:
    int coupon;
    Player() = default; //constructeur par d�faut
    Player(std::vector<std::string>& vectorColors); //constructeur
        void place();
        void exchange();
        void chooseName();
        std::string getColor();
        std::string getName();
        std::string chooseColor(std::vector<std::string>& vectorColors);
        int getCoupon();
        int IndexNumber();

};

#endif // PLAYER_H_INCLUDED
