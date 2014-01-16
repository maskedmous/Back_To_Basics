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

        static void Play(std::string soundName, bool loop );
        static void Stop();
        static void Pause();
        static void UnPause();
        static void SetVolume(float value);
        static void Mute();

    protected:
    private:
       static sf::Music music;

       static sf::SoundBuffer bufferSound;
       static sf::Sound sound;

       static bool muted;
       static float volume;
};

#endif // AUDIOPLAYER_HPP
