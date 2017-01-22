#include "mygame.hpp"

MyGame::MyGame() {
    _scene = GameScene::menu;
    _scenes = std::vector<Scene*>(SCENE_NUM);
    _menu = new Menu;
    _scenes[GameScene::menu] = _menu;
    _scenes[GameScene::inGame] = _combat;
    _scenes[GameScene::help] = _menu;
    _scenes[GameScene::credits] = _menu;
    std::cout << "in menu" << std::endl;
    SoundManager::load();
    SoundManager::setLoop(true, "intro");
    SoundManager::playMusic("intro");
}

MyGame::~MyGame() {
    delete _menu;
    delete _combat;
}

MyGame* i(){
}

void MyGame::changeScene(GameScene::gameScene n){
    _scene = n;
    if(_scenes[_scene] == NULL){
        if(_scene == GameScene::inGame){
            SoundManager::stopMusic("intro");
            _combat = new Combat;
            _scenes[_scene] = _combat;
            SoundManager::setLoop(true, "clicks");
            SoundManager::playMusic("clicks");
        }
    }
}

// Main game loop
void MyGame::update(float deltaTime, sf::RenderWindow*window) {
    //    std::cout << deltaTime << std::endl;
    sf::Event event;
    while(window->pollEvent(event)){
        switch (event.type) {
        case (sf::Event::Closed):
            Game::i()->isRunning = false;
            break;
        case (sf::Event::KeyPressed):
            if(event.key.code == sf::Keyboard::Escape)
                // Exit the game like this
                Game::i()->isRunning = false;
            break;
        case (sf::Event::MouseMoved):
        case (sf::Event::MouseButtonPressed):
        case (sf::Event::MouseButtonReleased):

            switch(_scene){
            case(GameScene::menu):
                //std::cout << "still in menu" << std::endl;
                break;
            default:
                break;
            }
        default:
            break;
        }
        _scenes[_scene]->updateEvents(event);
    }

    // do shit
    _scenes[_scene]->update(deltaTime,window);
}

void MyGame::draw(sf::RenderWindow*window) {
    //a e s t h e t i c s
    window->clear(sf::Color::Black);
    // draw shit
    _scenes[_scene]->draw(window);
    window->display();
}
