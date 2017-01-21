#include "player.hpp"

Player::Player(int num) : Actor(num) {
    compas = Compas();
    error = false;
    time = 0;
}

Player::Player() : Actor() {
    compas = Compas();
    error = false;
    time = 0;
}

bool Player::updateLogic(float deltaTime, sf::RenderWindow *window) {
    time += deltaTime;
    if (time > BLACKVALUE) {
        compas.incraeseTime();
        time = 0;
    }
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
                if (!error) {
                    compas.end();
                    animate = PlayerState::hurt;
                    error = true;
                }
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
