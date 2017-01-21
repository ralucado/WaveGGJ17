#include "soundmanager.hpp"

//PLACE HERE A FORWARD DECLARATION OF YOUR STATIC VARIABLES
//sf::SoundBuffer     SoundManager::SOUND_NAME;
//sf::Music           SoundManager::MUSIC_NAME;

/* Example:
sf::Music           SoundManager::overWorldMusic;*/
sf::Music     SoundManager::worldMusic;
sf::Music     SoundManager::clickTrack;

sf::SoundBuffer     SoundManager::atk1;
sf::SoundBuffer     SoundManager::atk2;
sf::SoundBuffer     SoundManager::atk3;
sf::SoundBuffer     SoundManager::atk4;
sf::SoundBuffer     SoundManager::atk5;
sf::SoundBuffer     SoundManager::atk6;
sf::SoundBuffer     SoundManager::atk7;
sf::SoundBuffer     SoundManager::atk8;
sf::SoundBuffer     SoundManager::atk9;
sf::SoundBuffer     SoundManager::atk10;
sf::SoundBuffer     SoundManager::atk11;
sf::SoundBuffer     SoundManager::atk12;
sf::SoundBuffer     SoundManager::atk13;
sf::SoundBuffer     SoundManager::atk14;
sf::SoundBuffer     SoundManager::atk15;
sf::SoundBuffer     SoundManager::atk16;
sf::SoundBuffer     SoundManager::atk17;
sf::SoundBuffer     SoundManager::atk18;
sf::SoundBuffer     SoundManager::atk19;
sf::SoundBuffer     SoundManager::atk20;


std::map<std::string, sf::Sound> SoundManager::soundMap;
std::map<std::string, sf::Music> SoundManager::musicMap;
std::map<std::string, sf::Sound>::iterator SoundManager::sit;
std::map<std::string, sf::Music>::iterator SoundManager::mit;


void SoundManager::load(){

    //LOAD HERE YOUR SOUNDS AND MUSIC
    /* Example: */
    musicMap["intro"].openFromFile(WORK_DIR+"Resources/Sounds/intro.wav");
    musicMap["clicks"].openFromFile(WORK_DIR+"Resources/Sounds/clicks.wav");
    ASSERT(atk1.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/1.wav"));
    soundMap["atk1"].setBuffer(atk1);
    ASSERT(atk2.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/2.wav"));
    soundMap["atk2"].setBuffer(atk2);
    ASSERT(atk3.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/3.wav"));
    soundMap["atk3"].setBuffer(atk3);
    ASSERT(atk4.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/4.wav"));
    soundMap["atk4"].setBuffer(atk4);
    ASSERT(atk5.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/5.wav"));
    soundMap["atk5"].setBuffer(atk5);
    ASSERT(atk6.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/6.wav"));
    soundMap["atk6"].setBuffer(atk6);
    ASSERT(atk7.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/7.wav"));
    soundMap["atk7"].setBuffer(atk7);
    ASSERT(atk8.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/8.wav"));
    soundMap["atk8"].setBuffer(atk8);
    ASSERT(atk9.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/9.wav"));
    soundMap["atk9"].setBuffer(atk9);
    ASSERT(atk10.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/10.wav"));
    soundMap["atk10"].setBuffer(atk10);
    ASSERT(atk11.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/11.wav"));
    soundMap["atk11"].setBuffer(atk11);
    ASSERT(atk12.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/12.wav"));
    soundMap["atk12"].setBuffer(atk12);
    ASSERT(atk13.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/13.wav"));
    soundMap["atk13"].setBuffer(atk13);
    ASSERT(atk14.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/14.wav"));
    soundMap["atk14"].setBuffer(atk14);
    ASSERT(atk15.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/15.wav"));
    soundMap["atk15"].setBuffer(atk15);
    ASSERT(atk16.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/16.wav"));
    soundMap["atk16"].setBuffer(atk16);
    ASSERT(atk17.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/17.wav"));
    soundMap["atk17"].setBuffer(atk17);
    ASSERT(atk18.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/18.wav"));
    soundMap["atk18"].setBuffer(atk18);
    ASSERT(atk19.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/19.wav"));
    soundMap["atk19"].setBuffer(atk19);
    ASSERT(atk20.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/20.wav"));
    soundMap["atk20"].setBuffer(atk20);

}



void SoundManager::playSound(std::string name){
    sit = soundMap.find(name);
    if (sit != soundMap.end()) (sit->second).play();
}

void SoundManager::playMusic(std::string name){
mit = musicMap.find(name);
if (mit != musicMap.end()) (mit->second).play();

}

void SoundManager::stopMusic(std::string name){
    mit = musicMap.find(name);
    if (mit != musicMap.end()) (mit->second).stop();

}

void SoundManager::pauseMusic(std::string name){
    mit = musicMap.find(name);
    if (mit != musicMap.end()) (mit->second).pause();

}

void SoundManager::setLoop(bool loop, std::string name){
    mit = musicMap.find(name);
    if (mit != musicMap.end()) (mit->second).setLoop(loop);

}

void SoundManager::setPitch(float pitch, std::string name){
    mit = musicMap.find(name);
    if (mit != musicMap.end()) (mit->second).setPitch(pitch);
}

void SoundManager::setVolume(float volume, std::string name){
    mit = musicMap.find(name);
    if (mit != musicMap.end()) (mit->second).setVolume(volume);
}

void SoundManager::setPosition(float x, float y, float z, std::string name){
    mit = musicMap.find(name);
    if (mit != musicMap.end()) (mit->second).setPosition(x,y,z);
}


void SoundManager::setGlobalSoundVolumen(float volume) {
    for (auto it = soundMap.begin(); it != soundMap.end(); ++it) (it->second).setVolume(volume);
}

void SoundManager::setGlobalMusicVolumen(float volume) {
    for (auto it = musicMap.begin(); it != musicMap.end(); ++it) (it->second).setVolume(volume);
}
