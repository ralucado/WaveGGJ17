#ifndef SCORE_H
#define SCORE_H

#include "commons.hpp"

class Score {
public:
    Score();
    Score(int num);
    void draw(sf::RenderWindow *window);
    void incrisScore();
private:
    std::vector<sf::Sprite> _scoreSprite;
    sf::Texture _texture;
    const std::string _spriteFile = WORK_DIR+"Resources/numbers-spreadsheet.png";
    int _score;
    int _posX, _posY;
    void setScore();
};

#endif // SCORE_H
