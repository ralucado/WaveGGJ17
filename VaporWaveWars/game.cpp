#include "game.hpp"

Game* Game::instance = nullptr;

Game::Game() {
    ASSERT(Game::instance == nullptr); //Two games created
    Game::instance = this;
    isRunning = true;
}

Game::~Game() {
    isRunning = false;
    Game::instance = nullptr;
}

Game* Game::i() {
    return Game::instance;
}

// Main game loop
void Game::run() {
    sf::Clock c;
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "( ( ( Radio Wave ) ) )", sf::Style::Close);
    window.setFramerateLimit(25);
    window.setKeyRepeatEnabled(false);


    float oldTime = c.getElapsedTime().asSeconds();
    while (isRunning) {
        float time = c.getElapsedTime().asSeconds();
        float deltaTime = time-oldTime;
        oldTime = time;
        //std::cout << deltaTime << std::endl;
        update(deltaTime, &window);
        draw( &window);
    }
    window.close();
}
