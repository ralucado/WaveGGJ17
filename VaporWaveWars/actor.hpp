#ifndef ENEMY_H
#define ENEMY_H

#include "commons.hpp"
#include "character.hpp"
class Actor
{
public:
    Actor();
    bool update(float deltaTime, sf::RenderWindow *window);
    void draw(sf::RenderWindow *window) ;
    virtual bool event(sf::Event e) = 0;
protected:
    bool animate;
    virtual bool updateLogic(float deltaTime, sf::RenderWindow *window) = 0;
private:
    Character character;
};

#endif // ENEMY_H
