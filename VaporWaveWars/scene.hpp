#ifndef SCENE_HPP
#define SCENE_HPP

#include "commons.hpp"
#include "game.hpp"
class Scene
{
    public:
        Scene();
        virtual ~Scene();
        virtual void update(float deltaTime, sf::RenderWindow *window) = 0;
        virtual void draw(sf::RenderWindow *window) = 0;
        virtual void updateEvents(sf::Event) = 0;
    protected:
        Game* parent;
};

#endif // SCENE_HPP
