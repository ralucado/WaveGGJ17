#include "compas.hpp"

Compas::Compas() {
    spaceTime = 0;
    isPress = false;
}

void Compas::start() {
    if (not isPress) {
        std::cout << "start" << std::endl;
        isPress = true;
        spaceTime = 0;
        notes = std::vector<int>();
    }
}

void Compas::add() {
    if (isPress) {
        notes.push_back(spaceTime);
        spaceTime = 0;
        std::cout << "add" << std::endl;
    }
}

void Compas::end() {
    if (isPress) {
        isPress = false;
        std::cout << "end" << std::endl;
        for (int i = 0; i < notes.size(); ++i) {
            std::cout << notes[i] << std::endl;
        }
    }
}

void Compas::incriseTime() {
    ++spaceTime;
}

int Compas::get (int i) const {
    return notes[i];
}

bool Compas::operator ==(const Compas& d) const{
    int n = notes.size();
    for (int i = 0; i  < n; ++i) {
        float diff = ((float) (std::abs(notes[i] - d.get(i))))/((float) (notes[i]));
        if (diff > margeErr) return false;
    }
    return true;
}
