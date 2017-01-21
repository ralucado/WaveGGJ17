#include "character.hpp"

Character::Character(int player){
    playerNum = player;
    ASSERT(texture.loadFromFile(spriteFile));
    height = texture.getSize().y/8;
    width = texture.getSize().x/4;
    timestamp = indexX = idleFrame = 0;
    indexY = magicNumber;
    setTexture(texture);
    sf::IntRect rect = sf::IntRect(indexX*width, indexY*height, width, height);
    setTextureRect(rect);
    actualState = PlayerState::idle;

    if (playerNum == 0){
        setPosition(posX1, posY1);
        magicNumber = 0;
    }
    else{
        setPosition(posX2, posY2);
        magicNumber = 4;
    }
}

void Character::update(float deltaTime){
    timestamp += deltaTime;
    if (timestamp >= frameTime){
        timestamp = 0;

        //std::cout << "PLAYER" << playerNum << ": indexX: " << indexX << ", idleFrame: " << idleFrame << std::endl;

        sf::IntRect rect = sf::IntRect(indexX*width, indexY*height, width, height);
        setTextureRect(rect);

        indexX = (indexX+1)%4;

        //Acabar automaticament la animacio de attack
        if ((actualState == PlayerState::attacking or actualState == PlayerState::hurt or actualState == PlayerState::success) and indexX%4 == 3){
            setState(PlayerState::idle);
        }

        idleFrame = (idleFrame+1)%4;
    }
}

void Character::setState(PlayerState::playerState state){
    actualState = state;
    if (state == PlayerState::idle){
        indexX = idleFrame;
        indexY = 0 + magicNumber;
    }
    else if (state == PlayerState::attacking){
        indexX = 0;
        indexY = 1 + magicNumber;
        std::string sample = "atk"+std::to_string(rand()%20+1);
        SoundManager::playSound(sample);
        std::cout << "playing sample " << sample << std::endl;
    }
    else if (state == PlayerState::hurt){
        std::cout << "i am hurt" << std::endl;
        indexX = 0;
        indexY = 2 + magicNumber;
    }
    else if (state == PlayerState::success){
        std::cout << "i am succeed!" << std::endl;
        indexX = 0;
        indexY = 3 + magicNumber;
    }
}

bool Character::isLastFrame(){
    return indexX == 3;
}


