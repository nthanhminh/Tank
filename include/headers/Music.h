#pragma once
#ifndef MUSIC_H
#define MUSIC_H

#include "CommonFunc.h"
class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    bool loadSound(std::string filePath);
    void playSound();
    void pauseSound();
    void stopSound();
    bool IsMusicPlaying();
    bool IsMusicPaused();
    Mix_Chunk* getSound();
private:
    Mix_Chunk* m_sound;
    int m_channel;
};

#endif /* MUSIC_H */
