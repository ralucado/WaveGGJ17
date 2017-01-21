#ifndef COMPAS_HPP
#define COMPAS_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <commons.hpp>

class Compas {
private:
    bool isPress;
    int spaceTime;
    std::vector<int> notes;
    int get(int i) const;
    int size() const;

public:
    Compas();
    void start();
    void add();
    void end();
    void incraeseTime();
    bool isPressed() const;
    bool operator ==(const Compas& d) const;
    const std::vector<int> &getNotes() const;
};

#endif // COMPAS_HPP
