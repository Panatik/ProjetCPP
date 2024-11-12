#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <vector>

class player
{
private:
    std::string color;
    std::string name;
    int coupon;
public:
    player(std::string playerColor = "", std::string playerName = "", int nbcoupon = 1);
        void place();
        void exchange();
        void chooseName();
        std::string getColor();
        std::string getName();
        std::string chooseColor(std::vector<std::string>& vectorColors);
        int getCoupon();

};

#endif // PLAYER_H_INCLUDED
