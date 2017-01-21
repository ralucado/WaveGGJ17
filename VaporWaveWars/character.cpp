#include "character.hpp"

Character::Character(){
    sf::Texture texture;
    ASSERT(texture.loadFromFile(spriteFile));
    height = texture.getSize().y;
    width = texture.getSize().x;
    next = timestamp = indexX = indexY = 0;
    setTexture(texture);
    sf::IntRect rect = sf::IntRect(indexX*width, indexY*height, width, height);
    setTextureRect(rect);
    actualState = previousState = PlayerState::idle;
}

void Character::update(float deltaTime){
    timestamp += deltaTime;
    if (timestamp >= frameTime){
        timestamp = 0;
        if (actualState == previousState){
            if (actualState == PlayerState::idle){
                indexX = (indexX+1)%numFrames;
            }
            else if (actualState == PlayerState::attacking){
                if (indexX == width){
                    indexX = 0;
                    actualState = PlayerState::idle;
                }
            }
        }
        else {
            indexX = 0;
            if (actualState == PlayerState::idle){
                indexY = 1;
                actualState = PlayerState::attacking;
            }

            else if (actualState == PlayerState::attacking){
                indexY = 0;
                actualState = PlayerState::idle;
            }
        }

        sf::IntRect rect = sf::IntRect(indexX*width, indexY*height, width, height);
        setTextureRect(rect);
    }
}

void Character::setState(PlayerState::playerState state){
    previousState = actualState;
    actualState = state;
}

