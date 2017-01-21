#ifndef GAME_HPP
#define GAME_HPP
#include "commons.hpp"

class Game {
    public:
        Game();
        virtual ~Game();
        static Game* i();

        virtual void run();

        bool isRunning =/* very very*/ true;
    protected:
        virtual void update(float deltaTime, sf::RenderWindow *window) = 0;
        virtual void draw(sf::RenderWindow *window) = 0;
    private:
        static Game* instance;
};
#endif // GAME_HPP
