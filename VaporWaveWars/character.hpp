#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "commons.hpp"

class Character : public sf::Sprite{
private:
    //CONFIG
    const double frameTime = 0.15;
    const int numFrames = 4;
    const std::string spriteFile = WORK_DIR+"Resources/spreadsheet.png";
    //POSICIO PLAYER 1
    float posX1 = 0, posY1 = 250;
    //POSICIO PLAYER 2
    float posX2 = 500, posY2 = 250;
    //END CONFIG

    int magicNumber;

    sf::Texture texture;
    int indexX, indexY, width, height;
    int playerNum;
    PlayerState::playerState actualState;
    float timestamp;

public:
    int idleFrame;

    Character();
    Character(int player);
    void update(float deltaTime);
    void setState(PlayerState::playerState state);
    bool isLastFrame();

};

#endif // CHARACTER_HPP
