#include "wave.hpp"

Wave::Wave(bool dir){
    direction = dir;
    ASSERT(texture.loadFromFile(spriteFile));
}

void Wave::update(float deltaTime){
    timestamp += deltaTime;
    float pos = getPosition().x;
    if (direction){
        pos += ; // AMOUNT??
    }
    else{
        pos -= ; // ""
    }
    setPosition(pos, getPosition().y);
}


