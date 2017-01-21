#include "playscene.hpp"

PlayScene::PlayScene(){

}

void PlayScene::update(float deltaTime, sf::RenderWindow*window){
    //float dx = InputManager::action(InputAction::moveX0);
    //_buttons[0]->move(dx,0);
    //std::cout << dx << std::endl;
    for(unsigned int i = 0; i < _buttons.size(); ++i){
        _buttons[i]->update(window->mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(*window))));
    }
}

void PlayScene::draw(sf::RenderWindow* window){
    for(unsigned int i = 0; i < _buttons.size(); ++i){
        window->draw(*_buttons[i]);
    }
}

void PlayScene::updateEvents(sf::Event e){
//    std::cout << "update menu buttons" << std::endl;
    for(unsigned int i = 0; i < _buttons.size(); ++i){
        _buttons[i]->handleMouseEvent(e);
    }
    MyGame* g = static_cast<MyGame*>(Game::i());
    if (_start.getClicks() > 0){
//        g->changeScene(GameScene::inGame);
        std::cout << "Game not ready to be played. Please Wait." << std::endl;
    }
    else if(_exit.getClicks() > 0) g->isRunning = false;

}
