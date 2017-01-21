#ifndef IAENEMY_H
#define IAENEMY_H

#include "enemy.hpp"

class IaEnemy : public Enemy {
public:
    IaEnemy();
    bool update(float deltaTime, sf::RenderWindow *window) final override;
    bool event(sf::Event e) final override;
};

#endif // IAENEMY_H
