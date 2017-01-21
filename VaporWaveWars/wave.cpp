#include "wave.hpp"

Wave::Wave(bool dir){
    direction = dir;
    ASSERT(texture.loadFromFile(spriteFile));
    setTexture(texture);
    sf::IntRect rect = sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y);
    setTextureRect(rect);
}

void Wave::update(float deltaTime){
    float pos = getPosition().x;
    if (direction){
        pos += 0; // AMOUNT??
    }
    else{
        pos -= 0; // ""
    }
    setPosition(pos, getPosition().y);
}


