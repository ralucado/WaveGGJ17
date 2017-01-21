#include "menu.hpp"
#include "mygame.hpp"

Menu::Menu() {
    _start.setPosition(512-160,200);
    _exit.setPosition(512-160,400);
    _start.turnOn();
    _exit.turnOn();
    _buttons.push_back(&_start);
    _buttons.push_back(&_exit);
    ASSERT(textureBackground.loadFromFile(WORK_DIR+"Resources/background.png"));
    background.setTexture(textureBackground);
    background.setPosition(0,0);

}

void Menu::update(float deltaTime, sf::RenderWindow*window){
    //float dx = InputManager::action(InputAction::moveX0);
    //_buttons[0]->move(dx,0);
    //std::cout << dx << std::endl;
    for(unsigned int i = 0; i < _buttons.size(); ++i){
        _buttons[i]->update(window->mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(*window))));
    }
}

void Menu::draw(sf::RenderWindow* window){
    window->draw(background);
    for(unsigned int i = 0; i < _buttons.size(); ++i){
        window->draw(*_buttons[i]);
    }
}

void Menu::updateEvents(sf::Event e){
//    std::cout << "update menu buttons" << std::endl;
    for(unsigned int i = 0; i < _buttons.size(); ++i){
        _buttons[i]->handleMouseEvent(e);
    }
    MyGame* g = static_cast<MyGame*>(Game::i());
    if (_start.getClicks() > 0){
        g->changeScene(GameScene::inGame);
        std::cout << "Game not ready to be played. Please Wait." << std::endl;
    }
    else if(_exit.getClicks() > 0) g->isRunning = false;

}
