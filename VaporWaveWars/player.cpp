#include "player.hpp"

Player::Player(int num) : Actor(num) {
    compas = Compas();
    error = false;
}

Player::Player() : Actor() {
    compas = Compas();
    error = false;
}

bool Player::updateLogic(float deltaTime, sf::RenderWindow *window) {
    if (deltaTime > BLACKVALUE) compas.incraeseTime();
    return false;
}

bool Player::event(sf::Event e) {
    switch(e.type) {
    case (sf::Event::KeyPressed):
        if(e.key.code == sf::Keyboard::C) {
            compas.start();
            error = false;
        }
        if(e.key.code == sf::Keyboard::Space) {
            if (animate == PlayerState::idle && !error) {
                compas.add();
                if (compas.isPressed()) animate = PlayerState::attacking;
            }
            else {
                compas.end();
                error = true; //weird?
                if (animate != PlayerState::inMidle) animate = PlayerState::hurt;

            }
        }
        break;
    case (sf::Event::KeyReleased):
        if (e.key.code == sf::Keyboard::C) {
            compas.end();
            return false;
        }
        break;
    default:
        break;
    }
    return true;
}
