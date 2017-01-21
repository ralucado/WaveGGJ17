#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "commons.hpp"

class Character : public sf::Sprite{
private:
    //CONFIG
    const double frameTime = BLACKVALUE/4.0f;
    const int numFrames = 4;
    const std::string spriteFile = WORK_DIR+"Resources/spreadsheet.png";
    //POSICIO PLAYER 1
    float posX1 = W_WIDTH*0.05f, posY1 = W_HEIGHT*0.5f;
    //POSICIO PLAYER 2
    float posX2 = W_WIDTH*0.65f, posY2 = W_HEIGHT*0.5f;
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
