#include "combat.hpp"

Combat::Combat() {
    ia = false;
//    ia = true;
    attacking = playerOneTurn = true;
    player = new Player(0);
//    enemy = new IaEnemy(1);
    enemy = new Player(1);
    initShader();
    SoundManager::load();
    SoundManager::playMusic("music");
}

Combat::Combat(bool ia) {
    this->ia = ia;
    player = new Player(0);
    attacking = playerOneTurn = true;
    if (ia) enemy = new IaEnemy(1);
    else enemy = new Player(1);
    initShader();
}

void Combat::initShader() {
    time = 0;
    _text.create(W_WIDTH, W_HEIGHT);
    _background.setTexture(_text);
    _shader.loadFromFile(WORK_DIR+"Resources/shader.frag", sf::Shader::Fragment);
    _shader.setParameter("resolution", sf::Vector2f(W_WIDTH, W_HEIGHT));
}

void Combat::update(float deltaTime, sf::RenderWindow *window) {
    player->update(deltaTime, window);
    bool aux = enemy->update(deltaTime, window);
    if (ia) enemyManager(aux); //end of player two ia ritm
    time += deltaTime;
    _shader.setParameter("time", time);
}

void Combat::draw(sf::RenderWindow *window) {
    window->draw(_background, &_shader);
    player->draw(window);
    enemy->draw(window);
}

void Combat::updateEvents(sf::Event e) {
    if (playerOneTurn) {
        bool aux = player->event(e);
        if (!aux) { //end of player one ritm
            if (!attacking) {
                if(!player->hitBy(enemy->getAttack())) enemy->upScore();
                std::cout << "player1: " << player->getScore() << std::endl;
                std::cout << "player2: " << enemy->getScore() << std::endl;
            }
            else playerOneTurn = aux;
            attacking = !attacking;
        }
    }
    else if (!ia) {
        bool aux = !enemy->event(e);
        enemyManager(aux); //end of player two not ia ritm
    }
}

void Combat::enemyManager(bool aux) {
    if (aux) {
        if (!attacking) {
            if(!enemy->hitBy(player->getAttack())) player->upScore();
            std::cout << "player1: " << player->getScore() << std::endl;
            std::cout << "player2: " << enemy->getScore() << std::endl;
        }
        else playerOneTurn = aux;
        attacking = !attacking;
    }
}
