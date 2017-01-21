#include "actor.hpp"

Actor::Actor() {}

void Actor::draw(sf::RenderWindow *window) {

}

bool Actor::update(float deltaTime, sf::RenderWindow *window) {
    character.update(deltaTime);

    return this->updateLogic(deltaTime, window);
}
