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
        compas.increaseTime();
        time = 0;
    }
    return false;
}

bool Player::event(sf::Event e) {
    switch(e.type) {
    case (sf::Event::KeyPressed):
        if(e.key.code == sf::Keyboard::C) {
            std::string sample = "note"+std::to_string(rand()%4+1);
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

DefenseResult::defenseResult Player::event(sf::Event e, int note) {
    std::cout << "Let's read an event" << std::endl;
    switch(e.type) {
    case (sf::Event::KeyPressed):
        if(e.key.code == sf::Keyboard::C) {
            std::string sample = "note"+std::to_string(rand()%4+1);
            SoundManager::playSound(sample);
            std::cout << "playing sample " << sample << std::endl;
            if(!compas.isPressed()) compas.start();
            error = false;
        }
        if(e.key.code == sf::Keyboard::Space) {
            if (animate == PlayerState::idle && !error) {
                std::cout << "Let's check notes" << std::endl;
                bool correct = compas.check(note);
                if(!correct) {
                    animate = PlayerState::hurt;
                    compas.end();
                    return DefenseResult::fail;
                }
                else {
                    animate = PlayerState::attacking;
                    return DefenseResult::success;
                }
            }
            else {
                if (!error) {
                    compas.fail();
                    animate = PlayerState::hurt;
                    error = true;
                    return DefenseResult::fail;
                }
            }
        }
        break;
    default:
        break;
    }
    return DefenseResult::nothing;
}
