#ifndef IAENEMY_H
#define IAENEMY_H

#include "actor.hpp"

class IaEnemy : public Actor {
public:
    IaEnemy();
    IaEnemy(int player);
    bool event(sf::Event e) final override;
protected:
    bool updateLogic(float deltaTime, sf::RenderWindow *window);

};

#endif // IAENEMY_H
