#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "commons.hpp"

class Character : public sf::Sprite{
private:
    //CONSTS
    const double frameTime = 0.2;
    const int numFrames = 4;
    const std::string spriteFile = "";
    //CONSTS

    int indexX, indexY, width, height;
    int posX, posY;
    PlayerState::playerState actualState, previousState;
    float timestamp, next;

public:
    Character();
    void update(float deltaTime);
    void setState(PlayerState::playerState state);

};

#endif // CHARACTER_HPP
