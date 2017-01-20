#ifndef COMPAS_HPP
#define COMPAS_HPP

#include <vector>
#include <iostream>
#include <cmath>

static const float margeErr = 0.80f;

class Compas{

private:
    bool isPress;
    int spaceTime;
    std::vector<int> notes;

public:
    Compas();
    void start();
    void add();
    void end();
    void incriseTime();
    int get(int i) const;
    bool operator ==(const Compas& d) const;
};

#endif // COMPAS_HPP
