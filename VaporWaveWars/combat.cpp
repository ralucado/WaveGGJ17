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

Combat::~Combat(){
     for(std::vector<Wave*>::iterator w = waves.begin(); w != waves.end();){
        w=waves.erase(w);
     }
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
    _shaderHalo.loadFromFile(WORK_DIR+"Resources/halo.frag", sf::Shader::Fragment);
    _shaderHalo.setParameter("blue", attacking);
    _shaderHalo.setParameter("time", time);

}

void Combat::update(float deltaTime, sf::RenderWindow *window) {
    player->update(deltaTime, window);
    bool aux = enemy->update(deltaTime, window);
    if (ia) enemyManager(aux); //end of player two ia rythm

    time += deltaTime;
    _shader.setParameter("time", time);
    for(std::vector<Wave*>::iterator w = waves.begin(); w != waves.end();){
        if ((*w)->getDirection() && (*w)->getPosition().x >= 1024) w=waves.erase(w);
        else if (!(*w)->getDirection() && (*w)->getPosition().x <= 0) w=waves.erase(w);

        else{
            (*w)->update(deltaTime);
            ++w;
        }
    }
    _shaderHalo.setParameter("time", time);
}

void Combat::draw(sf::RenderWindow *window) {
    window->draw(_background, &_shader);
    player->draw(window);
    enemy->draw(window);
    window->draw(_halo, &_shaderHalo);
    scorePlayer->draw(window);
    scoreEnemy->draw(window);
    for(std::vector<Wave*>::iterator w = waves.begin(); w != waves.end(); ++w){
        window->draw(*(*w));
    }
}

void Combat::updateEvents(sf::Event e) {
    if (playerOneTurn) {
        if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::C && !attacking) doMahWaves(!playerOneTurn);
        _halo.setPosition(W_WIDTH*0.05f, W_HEIGHT*0.5f);
        bool aux = player->event(e, !attacking);

        if (!aux) { //end of player one ritm

            if (!attacking) {
                if(!player->hitBy(enemy->getAttack())) {
                    scoreEnemy->incrisScore();
                }

            }
            else playerOneTurn = aux;
            attacking = !attacking;
            _shaderHalo.setParameter("blue", attacking);
        }
    }
    else if (!ia) {
        if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::C && !attacking) doMahWaves(!playerOneTurn);

        _halo.setPosition(W_WIDTH*0.65f, W_HEIGHT*0.5f);
        bool aux = !enemy->event(e, !attacking);
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
        _shaderHalo.setParameter("blue", attacking);
    }
}

void Combat::doMahWaves(bool p){
    std::cout << "defensa jugador " << p << std::endl;
    std::vector<int> notes;
    if(p){
        notes = player->getAttack().getNotes();
    }
    else notes = enemy->getAttack().getNotes();

    int anterior = notes[0];
    if(!p) anterior = 512+512*anterior;
    else anterior = 512-512*anterior;
    for(int i = 0; i < notes.size(); ++i){
        std::cout << notes[i] << std::endl;
        Wave* w = new Wave(p);
        //if(!p) w->setPosition(anterior,500);
        //else w->setPosition(512-512*anterior,500);
        w->setPosition(anterior,500);
        if(i<notes.size()) {
            if(!p) anterior += 256*notes[i+1];
            else anterior -= 256*notes[i+1];
        }
        waves.push_back(w);
    }
}
