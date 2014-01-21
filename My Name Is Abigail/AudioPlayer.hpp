#ifndef AUDIOPLAYER_HPP
#define AUDIOPLAYER_HPP

#include <iostream>
#include <SFML/audio.hpp>
#include <string>

class AudioPlayer
{
    public:
        AudioPlayer();
        virtual ~AudioPlayer();

        void Play(std::string soundName, bool loop );
        void PlayMusic(std::string musicName);
        void Stop();
        void Pause();
        void UnPause();
        void SetVolume(float value);
        void Mute();

        const int CheckStatus();

    protected:
    private:
       sf::Music music;

       sf::SoundBuffer bufferSound;
       sf::Sound sound;

       bool muted;
       float volume;
};

#endif // AUDIOPLAYER_HPP
