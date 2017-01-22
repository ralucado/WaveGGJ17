#include "combat.hpp"

Combat::Combat() {
    ia = false;
//    ia = true;
    state = CombatState::player_atk;
    player = new Player(0);
    //    enemy = new IaEnemy(1);
    enemy = new Player(1);
    scorePlayer = new Score(0);
    scoreEnemy = new Score(1);
    ASSERT(axisT.loadFromFile(WORK_DIR+"Resources/axis.png"));
    _axis.setTexture(axisT);
    _axis.setOrigin(axisT.getSize().x/2,axisT.getSize().y);
    _axis.setPosition(W_WIDTH/2,W_HEIGHT/2+18);
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
    state = CombatState::player_atk;
    if (ia) enemy = new IaEnemy(1);
    else enemy = new Player(1);
    initShader();
}

bool Combat::isAttack() const {
    return state == CombatState::player_atk or state == CombatState::enemy_atk;
}

bool Combat::isPlayerOne() const {
    return state == CombatState::player_def or state == CombatState::player_atk;
}

void Combat::updateHalo() {
    switch(state) {
    case CombatState::player_def:
    case CombatState::enemy_def:
        _shaderHalo.setParameter("type", 0.0f);
        break;
    case CombatState::enemy_atk:
        _shaderHalo.setParameter("type", 1.0f);
        break;
    case CombatState::player_atk:
        _shaderHalo.setParameter("type", 2.0f);
        break;
    default:
        break;
    }

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
    _shaderHalo.setParameter("time", time);
    updateHalo();
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



    if (isPlayerOne()) {
        if(_halo.getPosition().x != W_WIDTH*0.05f)
            toEnemy = false;
    }
    else  {
        if(_halo.getPosition().x != W_WIDTH*0.65f)
            toEnemy = true;
    }
    animationTo(toEnemy, deltaTime);

    updateHalo();


    sf::IntRect rect;
    if (isPlayerOne())
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
    window->draw(_axis);
    for(std::vector<Wave*>::iterator w = waves.begin(); w != waves.end(); ++w){
        window->draw(*(*w));
    }
}

void Combat::updateEvents(sf::Event e) {
    if (isPlayerOne()) {
        if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::C && !isAttack()) doMahWaves(!isPlayerOne());
        bool compasFinish = !player->event(e);
        enemyManager(compasFinish);
    }
    else if (!ia) {
        if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::C && !isAttack()) doMahWaves(!isPlayerOne());
        bool compasFinish = !enemy->event(e);
        enemyManager(compasFinish);
    }
}

void Combat::enemyManager(bool compasFinish) {
    if(compasFinish) {
        Compas compas;
        if(isPlayerOne()) compas = enemy->getAttack();
        else compas = player->getAttack();

        if(!isAttack()) {
            if(!ia) {
                bool hit;
                if(isPlayerOne()) hit = !player->hitBy(compas);
                else hit = !enemy->hitBy(compas);
                if(hit) {
                    if(isPlayerOne())
                        scoreEnemy->incrisScore();
                    else
                        scorePlayer->incrisScore();
                }
            }
        }
        else if(compas.isFailed())
            state = (CombatState::combatState) ((((int) state)+1) % 4);
        state = (CombatState::combatState) ((((int) state)+1) % 4);
    }
}

void Combat::doMahWaves(bool p) {
    std::cout << "defensa jugador " << p << std::endl;
    std::vector<int> notes;
    if(p){
        notes = player->getAttack().getNotes();
    }
    else notes = enemy->getAttack().getNotes();
    if (notes.size() > 0){
        int anterior = notes[0];
        if(!p) anterior = 256+256*anterior;
        else anterior = 768-256*anterior;
        for(int i = 0; i < notes.size(); ++i){
            std::cout << notes[i] << std::endl;
            Wave* w = new Wave(p);
            //if(!p) w->setPosition(anterior,500);
            //else w->setPosition(512-512*anterior,500);
            w->setPosition(anterior,200);
            if(i<notes.size()) {
                if(!p) anterior += 176*notes[i+1];
                else anterior -= 176*notes[i+1];
            }
            waves.push_back(w);
        }

//        int anterior = 1;
//        if(!p) anterior = 512+256*anterior;
//        else anterior = 512-256*anterior;
//        for(int i = 0; i < 20; ++i){
//            //std::cout << 0 << std::endl;
//            Wave* w = new Wave(p);
//            //if(!p) w->setPosition(anterior,500);
//            //else w->setPosition(512-512*anterior,500);
//            w->setPosition(anterior,200);
//            if(i<20) {
//                if(!p) anterior += 128*4;
//                else anterior -= 128*4;
//            }
//            waves.push_back(w);
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
