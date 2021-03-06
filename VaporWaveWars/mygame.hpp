#ifndef MYGAME_HPP
#define MYGAME_HPP
#include "game.hpp"

#include "menu.hpp"
#include "combat.hpp"
#include "soundmanager.hpp"

class MyGame : public Game{
    public:
        MyGame();
        virtual ~MyGame();
        static MyGame* i();
        void changeScene(GameScene::gameScene n);
    private:
        GameScene::gameScene _scene;
        std::vector<Scene*> _scenes;
        Menu* _menu = NULL;
        Combat* _combat = NULL;
        virtual void update(float deltaTime, sf::RenderWindow *window) final override;
        virtual void draw(sf::RenderWindow *window) final override;
};

#endif // MYGAME_HPP
