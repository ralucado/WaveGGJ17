#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "commons.hpp"

class Character : public sf::Sprite{
private:
    //CONFIG
    const double frameTime = 0.2;
    const int numFrames = 4;
    const std::string spriteFile = "./Resources/spreadsheet.png";
    //POSICIO PLAYER 1
    float posX1 = 0, posY1 = 0;
    //POSICIO PLAYER 2
    float posX2 = 300, posY2 = 0;
    //END CONFIG

    sf::Texture texture;
    int indexX, indexY, width, height;
    int playerNum;
    PlayerState::playerState actualState, previousState;
    float timestamp, next;

public:
    Character(int player);
    void update(float deltaTime);
    void setState(PlayerState::playerState state);

};

#endif // CHARACTER_HPP
