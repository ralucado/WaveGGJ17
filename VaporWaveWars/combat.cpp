#include "combat.hpp"

Combat::Combat() {
    ia = playerOneTurn = true;
    enemy = new IaEnemy();
}


void Combat::update(float deltaTime, sf::RenderWindow *window) {
    if (playerOneTurn) player.update(deltaTime, window);
    else if (ia) playerOneTurn = enemy->update(deltaTime, window);
}

void Combat::draw(sf::RenderWindow *window) {
    player.draw(window);
    enemy->draw(window);
    //draw background
}

void Combat::updateButtons(sf::Event e) {
    if (playerOneTurn) playerOneTurn = player.event(e);
    else if (!ia) playerOneTurn = !enemy->event(e);
}
