#ifndef PLAYER_H
#define PLAYER_H

#include "commons.hpp"
#include "compas.hpp"
#include "actor.hpp"
class Player : public Actor {
public:
    Player();
    bool update(float deltaTime, sf::RenderWindow *window) final override;
    bool event(sf::Event e) final override;
private:
    Compas compas;
};

#endif // PLAYER_H
