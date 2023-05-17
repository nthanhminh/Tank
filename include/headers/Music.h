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
    void playSoundNew();
    void playSoundNoRepeat();
    void playSoundNoRepeatNew();
    void pauseSound();
    void stopSound();
    void resumeSound();
    void restartSound();
    void restartSoundNoRepeat();
    bool IsMusicPlaying();
    bool IsMusicPaused();
    Mix_Chunk* getSound();
    void setChannel(int channel);
    int getChannel();
private:
    Mix_Chunk* m_sound;
    int m_channel;
    std::string m_filePath;
};

#endif /* MUSIC_H */
