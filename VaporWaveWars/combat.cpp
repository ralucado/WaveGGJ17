#include "combat.hpp"

Combat::Combat() {
    ia = false;
//    ia = true;
    attacking = playerOneTurn = true;
    player = new Player(0);
//    enemy = new IaEnemy(1);
    enemy = new Player(1);
    scorePlayer = new Score(0);
    scoreEnemy = new Score(1);
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
    _shader.setParameter("time", time);

    ASSERT(_haloT.loadFromFile(WORK_DIR+"Resources/platform-halo.png"));
    _halo.setTexture(_haloT);
    _halo.setPosition(W_WIDTH*0.05f, W_HEIGHT*0.5f);
    ASSERT(_plataformT.loadFromFile(WORK_DIR+"Resources/platforms-spreadsheet.png"));
    _plataform.setTexture(_plataformT);
    _plataform.setPosition(W_WIDTH*0.05f, W_HEIGHT*0.5f);

    sf::IntRect rect = sf::IntRect(0, 0, _plataformT.getSize().x/2, _plataformT.getSize().y);
    _plataform.setTextureRect(rect);
    _shaderHalo.loadFromFile(WORK_DIR+"Resources/halo.frag", sf::Shader::Fragment);
    _shaderHalo.setParameter("type", 0.0f);
    _shaderHalo.setParameter("time", time);

}

void Combat::update(float deltaTime, sf::RenderWindow *window) {
    player->update(deltaTime, window);
    bool aux = enemy->update(deltaTime, window);
    if (ia) enemyManager(aux); //end of player two ia rythm

    time += deltaTime;
    _shader.setParameter("time", time);
    _shaderHalo.setParameter("time", time);



    if (playerOneTurn) {
        if(_halo.getPosition().x != W_WIDTH*0.05f)
            animationTo(false, deltaTime);
    }
    else  {
        if(_halo.getPosition().x != W_WIDTH*0.65f)
            animationTo(true, deltaTime);
    }

    if (!attacking) _shaderHalo.setParameter("type", 0.0f);
    else {
        if (playerOneTurn)_shaderHalo.setParameter("type", 2.0f);
        else _shaderHalo.setParameter("type", 1.0f);
    }

    sf::IntRect rect;
    if (playerOneTurn)
        rect = sf::IntRect(0, 0, _plataformT.getSize().x/2, _plataformT.getSize().y);
    else
        rect = sf::IntRect(_plataformT.getSize().x/2, 0, _plataformT.getSize().x/2, _plataformT.getSize().y);
    _plataform.setTextureRect(rect);
}

void Combat::draw(sf::RenderWindow *window) {

    window->draw(_background, &_shader);
    window->draw(_plataform);
    player->draw(window);
    enemy->draw(window);
    window->draw(_halo, &_shaderHalo);
    scorePlayer->draw(window);
    scoreEnemy->draw(window);
}

void Combat::updateEvents(sf::Event e) {
    if (playerOneTurn) {
        bool aux = player->event(e);
        if (!aux) { //end of player one ritm

            if (!attacking && !ia) {
                if(!player->hitBy(enemy->getAttack())) {
                    scoreEnemy->incrisScore();
                }
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
            if(!enemy->hitBy(player->getAttack())) {
                scorePlayer->incrisScore();
            }
        }
        else playerOneTurn = aux;
        attacking = !attacking;
    }
}


void Combat::animationTo(bool toEnemy, float deltaTime) {
   if (toEnemy) {
        _halo.move(deltaTime*2000, 0.0f);
        _plataform.move(deltaTime*2000, 0.0f);
        if (_halo.getPosition().x > W_WIDTH*0.65f) {
            _halo.setPosition(W_WIDTH*0.65f, _halo.getPosition().y);
            _plataform.setPosition(W_WIDTH*0.65f, _plataform.getPosition().y);
        }
   }
   else {
       _halo.move(deltaTime*-2000, 0.0f);
       _plataform.move(deltaTime*-2000, 0.0f);
       if (_halo.getPosition().x < W_WIDTH*0.05f) {
           _halo.setPosition(W_WIDTH*0.05f, _halo.getPosition().y);
           _plataform.setPosition(W_WIDTH*0.05f, _plataform.getPosition().y);
       }
   }
}
