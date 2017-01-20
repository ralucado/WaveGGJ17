#ifndef MYGAME_HPP
#define MYGAME_HPP
#include "game.hpp"


class MyGame : public Game{
public:
    MyGame();
    virtual ~MyGame();
private:
    GameState::gameState _state;
    virtual void update(float deltaTime, sf::RenderWindow *window) final override;
    virtual void draw(sf::RenderWindow *window) final override;
};

#endif // MYGAME_HPP
