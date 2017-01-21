#include "character.hpp"

Character::Character(int player){
    playerNum = player;
    ASSERT(texture.loadFromFile(spriteFile));
    height = texture.getSize().y/5;
    width = texture.getSize().x/5;
    next = timestamp = indexX = 0;
    indexY = magicNumber;
    setTexture(texture);
    sf::IntRect rect = sf::IntRect(indexX*width, indexY*height, width, height);
    setTextureRect(rect);
    actualState = previousState = PlayerState::idle;

    if (playerNum == 0){
        setPosition(posX1, posY1);
        magicNumber = 0;
    }
    else{
        setPosition(posX2, posY2);
        magicNumber = 2;
    }
}

void Character::update(float deltaTime){
    timestamp += deltaTime;
    if (timestamp >= frameTime){
        timestamp = 0;
        sf::IntRect rect = sf::IntRect(indexX*width, indexY*height, width, height);
        setTextureRect(rect);

        //Acabar automaticament la animacio de attack
        if (actualState == PlayerState::attacking and indexX >= 3){
            setState(PlayerState::idle);
        }
        else {
            indexX = (indexX+1)%4;
        }
    }
}

void Character::setState(PlayerState::playerState state){
    previousState = actualState;
    actualState = state;
    if (state == PlayerState::idle){
        indexX = 0;
        indexY = 0 + magicNumber;
    }
    else{
        indexX = 0;
        indexY = 1 + magicNumber;
    }
}

