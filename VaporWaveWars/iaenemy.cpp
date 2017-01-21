#include "iaenemy.hpp"

IaEnemy::IaEnemy() : Actor() {}
IaEnemy::IaEnemy(int numplayer): Actor(numplayer) {}
bool IaEnemy::updateLogic(float deltaTime, sf::RenderWindow *window) {

    return true;
}

bool IaEnemy::event(sf::Event e, bool def) {return false;}
