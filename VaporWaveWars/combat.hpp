#ifndef COMBAT_H
#define COMBAT_H

#include "commons.hpp"
#include "compas.hpp"
#include "scene.hpp"
#include "player.hpp"
#include "iaenemy.hpp"
#include "actor.hpp"

class Combat : public Scene {
public:
    Combat();
    Combat(bool ia);
    Combat(const Combat& m) = delete;
    Combat(const Combat&& m) = delete;
    Combat& operator=(Combat& m) = delete;
    Combat& operator=(Combat&& m) = delete;
    void update(float deltaTime, sf::RenderWindow *window) final override;
    void draw(sf::RenderWindow *window) final override;
    void updateEvents(sf::Event e) final override;
private:
    bool playerOneTurn, ia;
    Player player;
    Actor *enemy;
    sf::Sprite _background;
    static sf::Shader _shader;

};

#endif // COMBAT_H
