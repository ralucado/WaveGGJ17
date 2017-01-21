#include "player.hpp"

Player::Player() {
    animate = false;
}

bool Player::update(float deltaTime, sf::RenderWindow *window) {
    if (deltaTime > BLACKVALUE) compas.incraeseTime();
    return false;
}

bool Player::event(sf::Event e) {
    switch(e.type) {
    case (sf::Event::KeyPressed):
        if(e.key.code == sf::Keyboard::C) compas.start();
        if(e.key.code == sf::Keyboard::Space) {
            compas.add();
            animate = true;
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
