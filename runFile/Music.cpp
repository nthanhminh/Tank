#include "Music.h"
#include <iostream>

AudioManager::AudioManager() : m_sound(nullptr), m_channel(-1) {
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        std::cout << "Error: Failed to initialize SDL_mixer" << std::endl;
    }
}

AudioManager::~AudioManager() {
    Mix_FreeChunk(m_sound);
    Mix_CloseAudio();
}

bool AudioManager::loadSound(std::string filePath) {
    m_sound = Mix_LoadWAV(filePath.c_str());
    if (m_sound == nullptr) {
        std::cout << "Error: Failed to load sound file: " << filePath << std::endl;
        return false;
    }
    return true;
}

void AudioManager::playSound() {
    if (m_sound == nullptr) {
        std::cout << "Error: No sound loaded" << std::endl;
        return;
    }
    m_channel = Mix_PlayChannel(-1, m_sound, -1);
    if (m_channel == -1) {
        std::cout << "Error: Failed to play sound" << std::endl;
    }
}

void AudioManager::playSoundNoRepeat() {
    if (m_sound == nullptr) {
        std::cout << "Error: No sound loaded" << std::endl;
        return;
    }
    m_channel = Mix_PlayChannel(-1, m_sound, 0);
    if (m_channel == -1) {
        std::cout << "Error: Failed to play sound" << std::endl;
    }
}

void AudioManager::pauseSound() {
    if (m_channel != -1) {
        Mix_Pause(m_channel);
    }
}

void AudioManager::resumeSound() {
    if (m_channel != -1) {
        Mix_Resume(m_channel);
    }
}

void AudioManager::stopSound() {
    if (m_channel != -1) {
        Mix_HaltChannel(m_channel);
        m_channel = -1;
    }
}

void AudioManager::restartSound() {
    if (m_channel!=-1)
    {
        Mix_PlayChannel(m_channel,m_sound,-1);
    }
}

bool AudioManager::IsMusicPlaying() {
    return (Mix_PlayingMusic() == 1);
}

bool AudioManager::IsMusicPaused() {
    return (Mix_PausedMusic() == 1);
}

Mix_Chunk* AudioManager::getSound()
{
    return this->m_sound;
}

int AudioManager::getChannel()
{
    return this->m_channel;
}

void AudioManager::setChannel(int channel)
{
    this->m_channel=channel;
}