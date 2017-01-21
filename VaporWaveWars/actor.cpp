#include "actor.hpp"
Actor::Actor() {}

Actor::Actor(int num) {
    animate = true;
    this->character = new Character(num);
}

void Actor::draw(sf::RenderWindow *window) {
    window->draw(*character);
}

bool Actor::update(float deltaTime, sf::RenderWindow *window) {
    character->update(deltaTime);
    if (animate) {
        character->setState(PlayerState::attacking);
        animate = false;
    }
    return this->updateLogic(deltaTime, window);
}

void Actor::hitBy(Compas enemy) const {
    if (enemy == compas) std::cout << "dodge" << std::endl;
    else std::cout << "hit" << std::endl;
}

Compas Actor::getAttack() const {
    return compas;
}
