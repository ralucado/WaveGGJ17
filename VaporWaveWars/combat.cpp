#include "combat.hpp"

Combat::Combat() {
    ia = playerOneTurn = true;
    enemy = new IaEnemy();
    initShader();
}

Combat::Combat(bool ia) {
    this->ia = ia;
    playerOneTurn = true;
    if (ia) enemy = new IaEnemy();
    else enemy = new Player();
    initShader();
}

void Combat::initShader() {
    _text.create(W_WIDTH, W_HEIGHT);
    _background.setTexture(_text);
    _shader.loadFromFile("./resources/shader.frag", sf::Shader::Fragment);
    _shader.setParameter("resolution", sf::Vector2f(W_WIDTH, W_HEIGHT));
}

void Combat::update(float deltaTime, sf::RenderWindow *window) {
    if (playerOneTurn) player.update(deltaTime, window);
    else if (ia) playerOneTurn = enemy->update(deltaTime, window);
    _shader.setParameter("time", deltaTime);
}

void Combat::draw(sf::RenderWindow *window) {
    player.draw(window);
    enemy->draw(window);
    window->draw(_background, &_shader);
}

void Combat::updateEvents(sf::Event e) {
    if (playerOneTurn) playerOneTurn = player.event(e);
    else if (!ia) playerOneTurn = !enemy->event(e);
}
