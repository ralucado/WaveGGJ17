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
sf::SoundBuffer     SoundManager::fail1;
sf::SoundBuffer     SoundManager::fail2;
sf::SoundBuffer     SoundManager::fail3;
sf::SoundBuffer     SoundManager::fail4;
sf::SoundBuffer     SoundManager::fail5;
sf::SoundBuffer     SoundManager::fail6;
sf::SoundBuffer     SoundManager::note1;
sf::SoundBuffer     SoundManager::note2;
sf::SoundBuffer     SoundManager::note3;
sf::SoundBuffer     SoundManager::note4;
sf::SoundBuffer     SoundManager::bona1;
sf::SoundBuffer     SoundManager::bona2;
sf::SoundBuffer     SoundManager::bona3;
sf::SoundBuffer     SoundManager::bona4;
sf::SoundBuffer     SoundManager::bona5;
sf::SoundBuffer     SoundManager::bona6;
sf::SoundBuffer     SoundManager::bona7;
sf::SoundBuffer     SoundManager::bona8;
sf::SoundBuffer     SoundManager::mod1;
sf::SoundBuffer     SoundManager::mod2;
sf::SoundBuffer     SoundManager::mod3;
sf::SoundBuffer     SoundManager::mod4;

std::map<std::string, sf::Sound> SoundManager::soundMap;
std::map<std::string, sf::Music> SoundManager::musicMap;
std::map<std::string, sf::Sound>::iterator SoundManager::sit;
std::map<std::string, sf::Music>::iterator SoundManager::mit;


void SoundManager::load(){

    //LOAD HERE YOUR SOUNDS AND MUSIC
    /* Example: */
    musicMap["intro"].openFromFile(WORK_DIR+"Resources/Sounds/intro.ogg");
    musicMap["clicks"].openFromFile(WORK_DIR+"Resources/Sounds/clicks.ogg");
    ASSERT(atk1.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/1.ogg"));
    soundMap["atk1"].setBuffer(atk1);
    ASSERT(atk2.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/2.ogg"));
    soundMap["atk2"].setBuffer(atk2);
    ASSERT(atk3.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/3.ogg"));
    soundMap["atk3"].setBuffer(atk3);
    ASSERT(atk4.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/4.ogg"));
    soundMap["atk4"].setBuffer(atk4);
    ASSERT(atk5.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/5.ogg"));
    soundMap["atk5"].setBuffer(atk5);
    ASSERT(atk6.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/6.ogg"));
    soundMap["atk6"].setBuffer(atk6);
    ASSERT(atk7.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/7.ogg"));
    soundMap["atk7"].setBuffer(atk7);
    ASSERT(atk8.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/8.ogg"));
    soundMap["atk8"].setBuffer(atk8);
    ASSERT(atk9.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/9.ogg"));
    soundMap["atk9"].setBuffer(atk9);
    ASSERT(atk10.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/10.ogg"));
    soundMap["atk10"].setBuffer(atk10);
    ASSERT(atk11.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/11.ogg"));
    soundMap["atk11"].setBuffer(atk11);
    ASSERT(atk12.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/12.ogg"));
    soundMap["atk12"].setBuffer(atk12);
    ASSERT(atk13.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/13.ogg"));
    soundMap["atk13"].setBuffer(atk13);
    ASSERT(atk14.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/14.ogg"));
    soundMap["atk14"].setBuffer(atk14);
    ASSERT(atk15.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/15.ogg"));
    soundMap["atk15"].setBuffer(atk15);
    ASSERT(atk16.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/16.ogg"));
    soundMap["atk16"].setBuffer(atk16);
    ASSERT(atk17.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/17.ogg"));
    soundMap["atk17"].setBuffer(atk17);
    ASSERT(atk18.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/18.ogg"));
    soundMap["atk18"].setBuffer(atk18);
    ASSERT(atk19.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/19.ogg"));
    soundMap["atk19"].setBuffer(atk19);
    ASSERT(atk20.loadFromFile(WORK_DIR+"Resources/Sounds/Samples/20.ogg"));
    soundMap["atk20"].setBuffer(atk20);
    ASSERT(fail1.loadFromFile(WORK_DIR+"Resources/Sounds/Fails/1.ogg"));
    soundMap["fail1"].setBuffer(fail1);
    ASSERT(fail2.loadFromFile(WORK_DIR+"Resources/Sounds/Fails/2.ogg"));
    soundMap["fail2"].setBuffer(fail2);
    ASSERT(fail3.loadFromFile(WORK_DIR+"Resources/Sounds/Fails/3.ogg"));
    soundMap["fail3"].setBuffer(fail3);
    ASSERT(fail4.loadFromFile(WORK_DIR+"Resources/Sounds/Fails/4.ogg"));
    soundMap["fail4"].setBuffer(fail4);
    ASSERT(fail5.loadFromFile(WORK_DIR+"Resources/Sounds/Fails/5.ogg"));
    soundMap["fail5"].setBuffer(fail5);
    ASSERT(fail6.loadFromFile(WORK_DIR+"Resources/Sounds/Fails/6.ogg"));
    soundMap["fail6"].setBuffer(fail6);
    ASSERT(note1.loadFromFile(WORK_DIR+"Resources/Sounds/Notes/1.ogg"));
    soundMap["note1"].setBuffer(note1);
    ASSERT(note2.loadFromFile(WORK_DIR+"Resources/Sounds/Notes/2.ogg"));
    soundMap["note2"].setBuffer(note2);
    ASSERT(note3.loadFromFile(WORK_DIR+"Resources/Sounds/Notes/3.ogg"));
    soundMap["note3"].setBuffer(note3);
    ASSERT(note4.loadFromFile(WORK_DIR+"Resources/Sounds/Notes/4.ogg"));
    soundMap["note4"].setBuffer(note4);
    ASSERT(bona1.loadFromFile(WORK_DIR+"Resources/Sounds/Bona/1.ogg"));
    soundMap["bona1"].setBuffer(bona1);
    ASSERT(bona2.loadFromFile(WORK_DIR+"Resources/Sounds/Bona/2.ogg"));
    soundMap["bona2"].setBuffer(bona2);
    ASSERT(bona3.loadFromFile(WORK_DIR+"Resources/Sounds/Bona/3.ogg"));
    soundMap["bona3"].setBuffer(bona3);
    ASSERT(bona4.loadFromFile(WORK_DIR+"Resources/Sounds/Bona/4.ogg"));
    soundMap["bona4"].setBuffer(bona4);
    ASSERT(bona5.loadFromFile(WORK_DIR+"Resources/Sounds/Bona/5.ogg"));
    soundMap["bona5"].setBuffer(bona5);
    ASSERT(bona6.loadFromFile(WORK_DIR+"Resources/Sounds/Bona/6.ogg"));
    soundMap["bona6"].setBuffer(bona6);
    ASSERT(bona7.loadFromFile(WORK_DIR+"Resources/Sounds/Bona/7.ogg"));
    soundMap["bona7"].setBuffer(bona7);
    ASSERT(bona8.loadFromFile(WORK_DIR+"Resources/Sounds/Bona/8.ogg"));
    soundMap["bona8"].setBuffer(bona8);
    ASSERT(mod1.loadFromFile(WORK_DIR+"Resources/Sounds/NotesMod/1.ogg"));
    soundMap["mod1"].setBuffer(mod1);
    ASSERT(mod2.loadFromFile(WORK_DIR+"Resources/Sounds/NotesMod/2.ogg"));
    soundMap["mod2"].setBuffer(mod2);
    ASSERT(mod3.loadFromFile(WORK_DIR+"Resources/Sounds/NotesMod/3.ogg"));
    soundMap["mod3"].setBuffer(mod3);
    ASSERT(mod4.loadFromFile(WORK_DIR+"Resources/Sounds/NotesMod/4.ogg"));
    soundMap["mod4"].setBuffer(mod4);

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
