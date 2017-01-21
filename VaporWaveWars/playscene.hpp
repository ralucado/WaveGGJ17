#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP

#include "scene.hpp"
class PlayScene : public Scene{
public:
    PlayScene();
    PlayScene(const Menu& m) = delete;
    PlayScene(const Menu&& m) = delete;
    PlayScene& operator=(Menu& m) = delete;
    PlayScene& operator=(Menu&& m) = delete;
    void update(float deltaTime, sf::RenderWindow *window) final override;
    void draw(sf::RenderWindow *window) final override;
    void updateEvents(sf::Event e) final override;

private:
    sf::Texture _backgroundTexture;
    sf::Sprite background;

};

#endif // PLAYSCENE_HPP
