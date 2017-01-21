#include "score.hpp"


Score::Score() {
    ASSERT(_texture.loadFromFile(_spriteFile));
    _scoreSprite.push_back(sf::Sprite());
    _scoreSprite[0].setTexture(_texture);
    _score = 0;
    setScore();
}


Score::Score(int num) : Score() {
    if (num == 0) {
        _posX = W_WIDTH*0.15f;
        _posY = W_HEIGHT*0.05f;
    }
    else {
        _posX = W_WIDTH*0.75f;
        _posY = W_HEIGHT*0.05f;
    }
    _scoreSprite[0].setPosition(_posX, _posY);
}

void Score::draw(sf::RenderWindow *window){
    for (int i = 0; i < _scoreSprite.size(); ++i)
        window->draw(_scoreSprite[i]);
}

void Score::incrisScore() {
    ++_score;
    setScore();
}


void Score::setScore() {
    int height = _texture.getSize().y;
    int width  = _texture.getSize().x/10;
    int s = _score;
    for (int i = 0; i < _scoreSprite.size(); ++i) {
        int num = s%10;
        s = s/10;
        sf::IntRect rect = sf::IntRect(num*width, 0, width, height);
        _scoreSprite[i].setTextureRect(rect);
    }
    while (s > 0) {
        int num = s%10;
        s = s/10;
        _scoreSprite.push_back(sf::Sprite());
        int i = _scoreSprite.size() - 1;
        _scoreSprite[i].setTexture(_texture);
        sf::IntRect rect = sf::IntRect(num*width, 0, width, height);
        _scoreSprite[i].setTextureRect(rect);
        _scoreSprite[i].setPosition(_posX-(width*i),_posY);
    }
}
