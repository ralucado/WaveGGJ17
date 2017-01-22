#include "actor.hpp"
Actor::Actor() {
    animate = PlayerState::attacking;
    this->character = new Character(0);
}

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
    else if (animate == PlayerState::hurt) {
        character->setState(PlayerState::hurt);
        animate = PlayerState::inMidle;
    }
    else if (animate == PlayerState::inMidle) {
        if (character->isLastFrame()) animate = PlayerState::idle;
    }
    return this->updateLogic(deltaTime, window);
}

bool Actor::hitBy(Compas enemy) {
    bool dodge = enemy == compas;
    if (dodge) std::cout << "dodge" << std::endl;
    else std::cout << "hit" << std::endl;
    if (!dodge) {
        character->setState(PlayerState::hurt);
        animate = PlayerState::hurt;
    }
    return dodge;
}

Compas Actor::getAttack() const {
    return compas;
}

