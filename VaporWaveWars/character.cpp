#include "character.hpp"

Character::Character(int player){
    playerNum = player;
    ASSERT(texture.loadFromFile(spriteFile));
    height = texture.getSize().y/5;
    width = texture.getSize().x/5;
    next = timestamp = indexX = indexY = 0;
    setTexture(texture);
    sf::IntRect rect = sf::IntRect(indexX*width, indexY*height, width, height);
    setTextureRect(rect);
    actualState = previousState = PlayerState::idle;

    if (playerNum == 0){
        setPosition(posX1, posY1);
    }
    else{
        setPosition(posX2, posY2);
    }
}

void Character::update(float deltaTime){
    timestamp += deltaTime;
    if (timestamp >= frameTime){
        timestamp = 0;

        if (actualState == PlayerState::attacking and indexX >= 3){
            setState(PlayerState::idle);
        }
        else {
            indexX = (indexX+1)%4;
        }

        sf::IntRect rect = sf::IntRect(indexX*width, indexY*height, width, height);
        setTextureRect(rect);
    }
}

void Character::setState(PlayerState::playerState state){
    previousState = actualState;
    actualState = state;
    if (state == PlayerState::idle){
        indexX = 0;
        indexY = 0;
    }
    else{
        indexX = 0;
        indexY = 1;
    }
}

