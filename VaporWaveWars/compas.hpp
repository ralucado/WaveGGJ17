#ifndef COMPAS_HPP
#define COMPAS_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <commons.hpp>

class Compas {
private:
    bool isPress;
    bool failed;
    int spaceTime;
    std::vector<int> notes;

public:
    Compas();
    int get(int i) const;
    int size() const;
    void start();
    void add();
    void end();
    void fail();
    void increaseTime();
    bool isPressed() const;
    bool isFailed() const;
    bool check(int note);
    bool operator ==(const Compas& d) const;
    const std::vector<int> &getNotes() const;
};

#endif // COMPAS_HPP
