#include "actor.hpp"
Actor::Actor() {}

Actor::Actor(int num) {
    animate = PlayerState::attacking;
    this->character = new Character(num);
}

void Actor::draw(sf::RenderWindow *window) {
    window->draw(*character);
}

bool Actor::update(float deltaTime, sf::RenderWindow *window) {
    character->update(deltaTime);
    if (animate == PlayerState::attacking) {
        character->setState(PlayerState::attacking);
        animate = PlayerState::inMidle;
    }
    else if (animate == PlayerState::inMidle) {
        if (character->isLastFrame()) animate = PlayerState::idle;
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
