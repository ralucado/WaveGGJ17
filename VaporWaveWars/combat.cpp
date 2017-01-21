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
    initShader();
    SoundManager::load();
    SoundManager::playMusic("music");

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
    _shaderHalo.setParameter("time", time);



    if (isPlayerOne()) {
        if(_halo.getPosition().x != W_WIDTH*0.05f)
            animationTo(false, deltaTime);
    }
    else  {
        if(_halo.getPosition().x != W_WIDTH*0.65f)
            animationTo(true, deltaTime);
    }

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
}

void Combat::updateEvents(sf::Event e) {
    if (isPlayerOne()) {
        bool compasFinish = !player->event(e);
        enemyManager(compasFinish);
    }
    else if (!ia) {
        bool compasFinish = !enemy->event(e);
        enemyManager(compasFinish);
    }
}

void Combat::enemyManager(bool compasFinish) {
    if(compasFinish) {
        Compas compas;
        if(isPlayerOne()) compas = player->getAttack();
        else compas = enemy->getAttack();

        if(!isAttack()) {
            if(!ia) {
                bool hit;
                if(isPlayerOne()) hit = !player->hitBy(compas);
                else hit = !enemy->hitBy(compas);
                if(!hit) {
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
