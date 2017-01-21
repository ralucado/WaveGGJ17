#ifndef PLAYER_H
#define PLAYER_H

#include "commons.hpp"
#include "compas.hpp"
#include "actor.hpp"
class Player : public Actor {
public:
    Player();
    Player(int num);
    bool event(sf::Event e) final override;
private:
    Compas compas;
protected:
    bool updateLogic(float deltaTime, sf::RenderWindow *window);

};

#endif // PLAYER_H
