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

// Main game loop
void Game::run() {
    sf::Clock c;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    float oldTime = c.getElapsedTime().asSeconds();
    while (isRunning) {
        float time = c.getElapsedTime().asSeconds();
        float deltaTime = time-oldTime;
        oldTime = time;
        update(deltaTime, &window);
        draw( &window);
    }
    window.close();
}
