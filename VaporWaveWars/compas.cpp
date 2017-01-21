#include "compas.hpp"

Compas::Compas() {
    spaceTime = 1;
    isPress = false;
}

void Compas::start() {
    if (not isPress) {
//        std::cout << "start" << std::endl;
        isPress = true;
        spaceTime = 1;
        notes = std::vector<int>();
    }
}

void Compas::add() {
    if (isPress) {
        notes.push_back(spaceTime);
        spaceTime = 1;
//        std::cout << "add" << std::endl;
    }
}

void Compas::end() {
    if (isPress) {
        isPress = false;
//        std::cout << "end" << std::endl;
//        for (int i = 0; i < notes.size(); ++i) {
//            std::cout << notes[i] << std::endl;
//        }
    }
}

void Compas::incraeseTime() {
    ++spaceTime;
}

bool Compas::isPressed() const {
    return isPress;
}

const std::vector<int>& Compas::getNotes() const
{
    return notes;
}


int Compas::get (int i) const {
    return notes[i];
}

int Compas::size() const {
    return notes.size();
}

bool Compas::operator ==(const Compas& d) const{
    int n = notes.size();
    if (n != d.size()) return false;
    for (int i = 0; i  < n; ++i) {
        float diff = ((float) (std::abs(notes[i] - d.get(i))))/((float) (notes[i]));
        if (diff > MARGEERR) return false;
    }
    return true;
}
