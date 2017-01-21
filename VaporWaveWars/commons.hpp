#ifndef COMMONS_HPP
#define COMMONS_HPP
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <assert.h>
#include <stdlib.h>     /* getenv */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>
#include "soundmanager.hpp"
const int SCENE_NUM = 4;
#define MARGEERR 0.2f
#define BLACKVALUE 0.4f
#define W_WIDTH  1024
#define W_HEIGHT 768
const std::string WORK_DIR(getenv("WORK_DIR"));


#define ASSERT(expression) do \
{ \
    if(!(expression)) { \
    std::cout << "ASSERT FAILED, STOPPING " << std::endl;\
    std::cout << "At file " << __FILE__ \
    << " inside function " << __PRETTY_FUNCTION__ << " on line " << __LINE__ << std::endl; \
    assert(expression); \
    std::exit(-1); \
    } \
    } while (0)

namespace ButtonState {
//namespace for button states (for the menu)
//released is the regular state of the button, it activates when you move the mouse over it
//off means it is drawn but not clickable.
enum basicState {released, active, pressed, off};
}

namespace GameScene {
enum gameScene{menu,inGame,help,credits};
}

namespace PlayerState {
enum playerState{idle, attacking, inMidle, hurt, success};
}

#endif // COMMONS_HPP
