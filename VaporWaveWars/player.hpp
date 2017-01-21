#ifndef PLAYER_H
#define PLAYER_H

#include "commons.hpp"
#include "compas.hpp"
#include "actor.hpp"
class Player : public Actor {
public:
    Player();
    Player(int num);
    bool event(sf::Event e, bool def) final override;
protected:
    bool updateLogic(float deltaTime, sf::RenderWindow *window);

private:
    float time;
    bool error;
};

#endif // PLAYER_H
