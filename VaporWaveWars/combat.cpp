#include "combat.hpp"

Combat::Combat() {
    ia = playerOneTurn = true;
    player = new Player(0);
    enemy = new IaEnemy(1);
    initShader();
}

Combat::Combat(bool ia) {
    this->ia = ia;
    player = new Player(0);
    playerOneTurn = true;
    if (ia) enemy = new IaEnemy(1);
    else enemy = new Player(1);
}

void Combat::initShader() {
    time = 0;
    _text.create(W_WIDTH, W_HEIGHT);
    _background.setTexture(_text);
    _shader.loadFromFile("./Resources/shader.frag", sf::Shader::Fragment);
    _shader.setParameter("resolution", sf::Vector2f(W_WIDTH, W_HEIGHT));
}

void Combat::update(float deltaTime, sf::RenderWindow *window) {
    player->update(deltaTime, window);
    enemy->update(deltaTime, window);
    time += deltaTime;
    _shader.setParameter("time", time);
}

void Combat::draw(sf::RenderWindow *window) {
    player->draw(window);
    enemy->draw(window);
    window->draw(_background, &_shader);
}

void Combat::updateEvents(sf::Event e) {
    if (playerOneTurn) playerOneTurn = player->event(e);
    else if (!ia) playerOneTurn = !enemy->event(e);
}
