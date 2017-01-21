TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp \
    game.cpp \
    mygame.cpp \
    button.cpp \
    character.cpp \
    compas.cpp \
    scene.cpp \
    menu.cpp \
    combat.cpp \
    player.cpp \
    enemy.cpp \
    iaenemy.cpp

HEADERS += \
    game.hpp \
    mygame.hpp \
    commons.hpp \
    button.hpp \
    character.hpp \
    compas.hpp \
    scene.hpp \
    menu.hpp \
    combat.hpp \
    player.hpp \
    enemy.hpp \
    iaenemy.hpp
