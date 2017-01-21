#include "iaenemy.hpp"

IaEnemy::IaEnemy() : Actor(1) {}
IaEnemy::IaEnemy(int numplayer): Actor(numplayer) {}
bool IaEnemy::updateLogic(float deltaTime, sf::RenderWindow *window) {
    //some playe return true
    return true;
}

bool IaEnemy::event(sf::Event e) {return false;}
