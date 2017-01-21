#ifndef MENU_HPP
#define MENU_HPP
#include "commons.hpp"
#include "scene.hpp"
#include "button.hpp"
class Menu : public Scene{
    public:
        Menu();
        Menu(const Menu& m) = delete;
        Menu(const Menu&& m) = delete;
        Menu& operator=(Menu& m) = delete;
        Menu& operator=(Menu&& m) = delete;
        void update(float deltaTime, sf::RenderWindow *window) final override;
        void draw(sf::RenderWindow *window) final override;
        void updateEvents(sf::Event e) final override;
    private:
        Button _start = Button(WORK_DIR+"Resources/play-spreadsheet.png");
        Button _exit = Button(WORK_DIR+"Resources/exit-spreadsheet.png");
        std::vector<Button*> _buttons;
};

#endif // MENU_HPP
