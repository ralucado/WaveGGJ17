#include "combat.hpp"

Combat::Combat() {
    ia = playerOneTurn = true;
    enemy = new IaEnemy();

}

Combat::Combat(bool ia) {
    this->ia = ia;
    playerOneTurn = true;
    if (ia) enemy = new IaEnemy();
    else enemy = new Player();
}

void Combat::update(float deltaTime, sf::RenderWindow *window) {
    if (playerOneTurn) player.update(deltaTime, window);
    else if (ia) playerOneTurn = enemy->update(deltaTime, window);
}

void Combat::draw(sf::RenderWindow *window) {
    player.draw(window);
    enemy->draw(window);

}

void Combat::updateEvents(sf::Event e) {
    if (playerOneTurn) playerOneTurn = player.event(e);
    else if (!ia) playerOneTurn = !enemy->event(e);
}
