#ifndef ENEMY_H
#define ENEMY_H

#include "commons.hpp"

class Enemy
{
public:
    Enemy();
    virtual bool update(float deltaTime, sf::RenderWindow *window) = 0;
    void draw(sf::RenderWindow *window) ;
    virtual bool event(sf::Event e) = 0;
protected:
    bool animate;
};

#endif // ENEMY_H
