#include "wave.hpp"


bool Wave::getDirection() const
{
    return direction;
}


Wave::Wave(bool dir){
    direction = dir;
    ASSERT(texture.loadFromFile(spriteFile));
    setTexture(texture);
    setOrigin(texture.getSize().x/2,texture.getSize().y - 1);
//    sf::IntRect rect = sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y);
//    setTextureRect(rect);
}

void Wave::update(float deltaTime){
    float pos = getPosition().x;
    if (direction){
        pos += 640*deltaTime; // AMOUNT??
    }
    else{
        pos -= 640*deltaTime; // ""
    }
    setPosition(pos, getPosition().y);
}


