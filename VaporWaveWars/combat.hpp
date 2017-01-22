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
#include "wave.hpp"
#include <time.h>

#define PI 3.14159265


class Combat : public Scene {

    public:
        Combat();
        ~Combat();
        Combat(bool ia);
        Combat(const Combat& m) = delete;
        Combat(const Combat&& m) = delete;
        Combat& operator=(Combat& m) = delete;
        Combat& operator=(Combat&& m) = delete;
        void update(float deltaTime, sf::RenderWindow *window) final override;
        void draw(sf::RenderWindow *window) final override;
        void updateEvents(sf::Event e) final override;
    private:
        bool playerOneTurn, ia, attacking, toEnemy;
        Actor *player, *enemy;
        float time;
        CombatState::combatState state;
        std::vector<Wave*> waves;
        sf::Texture _text, _haloT, _plataformT, axisT;
        sf::Sprite _background, _halo, _plataform, _axis;
        sf::Shader _shader, _shaderHalo;
        Score *scoreEnemy, *scorePlayer;
        void initShader();
        void enemyManager(bool aux);
        void animationTo(bool toEnemy, float deltaTime);
        bool isAttack() const;
        bool isPlayerOne() const;
        void updateHalo();
        void doMahWaves(bool p);
        int aux;

};

#endif // COMBAT_H
