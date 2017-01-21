#include "mygame.hpp"
#include "compas.hpp"
int main() {
    srand (time(NULL));
    MyGame game;
    game.run();
    return 0;
}
