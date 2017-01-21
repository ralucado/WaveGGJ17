#ifndef WAVE_HPP
#define WAVE_HPP
#include "commons.hpp"

class Wave : public sf::Sprite{
private:
    //CONFIG
    const std::string spriteFile = WORK_DIR+"Resources/pulsation.png";
    //POSICIO PLAYER 1
    float posX1 = W_WIDTH*0.05f, posY1 = W_HEIGHT*0.6f;
    //POSICIO PLAYER 2
    float posX2 = W_WIDTH*0.65f, posY2 = W_HEIGHT*0.6f;
    //END CONFIG

    bool direction; //TRUE => CAP A LA DRETA

    sf::Texture texture;

public:
    Wave();
    Wave(bool dir);
    void update(float deltaTime);
};

#endif // WAVE_HPP
