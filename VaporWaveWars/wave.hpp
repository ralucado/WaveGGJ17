#ifndef WAVE_HPP
#define WAVE_HPP
#include "commons.hpp"

class Wave : public sf::Sprite{
private:
    //CONFIG
    const std::string spriteFile = WORK_DIR+"Resources/pulsation.png";
    //END CONFIG

    bool direction; //TRUE => CAP A LA DRETA

    sf::Texture texture;

public:
    Wave(bool dir);
    void update(float deltaTime);
    bool getDirection() const;
};

#endif // WAVE_HPP
