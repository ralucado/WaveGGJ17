#ifndef COMBAT_H
#define COMBAT_H

#include "commons.hpp"
#include "compas.hpp"
#include "scene.hpp"
#include "player.hpp"
#include "iaenemy.hpp"
#include "enemy.hpp"

class Combat : public Scene {
public:
    Combat();
    Combat(const Combat& m) = delete;
    Combat(const Combat&& m) = delete;
    Combat& operator=(Combat& m) = delete;
    Combat& operator=(Combat&& m) = delete;
    void update(float deltaTime, sf::RenderWindow *window) final override;
    void draw(sf::RenderWindow *window) final override;
    void updateButtons(sf::Event e) final override;
private:
    Compas compas;
    bool playerOneTurn, ia;
    Player player;
    Enemy *enemy;
};

#endif // COMBAT_H
