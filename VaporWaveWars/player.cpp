#include "player.hpp"

Player::Player(int num) : Actor(num) {
    compas = Compas();
    error = false;
    time = 0;
    mod = false;
}

Player::Player() : Actor() {
    compas = Compas();
    error = false;
    time = 0;
    mod = false;
}

bool Player::updateLogic(float deltaTime, sf::RenderWindow *window) {
    time += deltaTime;
    clock += deltaTime;
    if (time > BLACKVALUE) {
        compas.incraeseTime();
        time = 0;
    }
    if (clock >= 89.15) clock = 0.0;
    if (!mod && clock > 38.10 && clock < 64) mod = true;
    else if (mod && clock < 38.10 || clock > 64) mod = false;
    return false;
}

bool Player::event(sf::Event e) {
    switch(e.type) {
    case (sf::Event::KeyPressed):
        if(e.key.code == sf::Keyboard::C) {

            std::string sample = "mod"+std::to_string(rand()%2+1);
            if(!mod) sample = "note"+std::to_string(rand()%4+1);
            SoundManager::playSound(sample);
            std::cout << "playing sample " << sample << std::endl;
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
                    compas.fail();
                    animate = PlayerState::hurt;
                    error = true;
                    return false;
                }
            }
        }
        break;
    case (sf::Event::KeyReleased):
        if (compas.isPressed() and e.key.code == sf::Keyboard::C) {
            compas.end();
            return false;
        }
        break;
    default:
        break;
    }
    return true;
}
