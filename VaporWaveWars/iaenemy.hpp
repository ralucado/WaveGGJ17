#ifndef IAENEMY_H
#define IAENEMY_H

#include "actor.hpp"

class IaEnemy : public Actor {
public:
    IaEnemy();
    bool update(float deltaTime, sf::RenderWindow *window) final override;
    bool event(sf::Event e) final override;
};

#endif // IAENEMY_H
