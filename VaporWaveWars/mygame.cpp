#include "mygame.hpp"

MyGame::MyGame() {
    _state = GameState::menu;
    std::cout << "in menu" << std::endl;
    compas2 = compas = Compas();
}

MyGame::~MyGame() {
}

// Main game loop
void MyGame::update(float deltaTime, sf::RenderWindow*window) {
//    std::cout << deltaTime << std::endl;
    if (deltaTime > BLACKVALUE) compas.incraeseTime();
    sf::Event event;
    while(window->pollEvent(event)){
        switch (event.type) {
            case (sf::Event::Closed):
            Game::i()->isRunning = false;
            break;
            case (sf::Event::KeyPressed):
                if(event.key.code == sf::Keyboard::Escape)
                    Game::i()->isRunning = false; // Exit the game like this
                if(event.key.code == sf::Keyboard::C)
                    compas.start();
                if(event.key.code == sf::Keyboard::Space)
                    compas.add();
            break;
            case (sf::Event::KeyReleased):
                if (event.key.code == sf::Keyboard::C) {
                    compas.end();
                    std::cout << (compas == compas2) << std::endl;
                    compas2 = compas;
                }
            break;
            case (sf::Event::MouseMoved):
            case (sf::Event::MouseButtonPressed):
            switch(_state){
                case(GameState::menu):
                //std::cout << "still in menu" << std::endl;
                break;
                default:
                break;
            }

            default:
            break;

        }
    }

    // do shit
}

void MyGame::draw(sf::RenderWindow*window) {
    //a e s t h e t i c s
    window->clear(sf::Color::Cyan);
    // draw shit
    window->display();
}
