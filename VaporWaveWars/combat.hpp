#ifndef COMBAT_H
#define COMBAT_H

#include "commons.hpp"
#include "compas.hpp"
#include "scene.hpp"
#include "player.hpp"
#include "iaenemy.hpp"
#include "actor.hpp"
#include "soundmanager.hpp"
#include "score.hpp"

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
    bool playerOneTurn, ia, attacking;
    Actor *player, *enemy;
    float time;

    sf::Texture _text, _haloT, _plataformT;
    sf::Sprite _background, _halo, _plataform;
    sf::Shader _shader, _shaderHalo;

    Score *scoreEnemy, *scorePlayer;
    void initShader();
    void enemyManager(bool aux);
    void animationTo(bool toEnemy, float deltaTime);
};

#endif // COMBAT_H
