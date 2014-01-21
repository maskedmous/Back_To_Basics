#include "AudioPlayer.hpp"

/*
sf::Music AudioPlayer::music;
sf::SoundBuffer AudioPlayer::bufferSound;
sf::Sound AudioPlayer::sound;
*/

//bool AudioPlayer::muted;
//float AudioPlayer::volume;


AudioPlayer::AudioPlayer()
{
    //ctor
}

AudioPlayer::~AudioPlayer()
{
    //dtor
}

void AudioPlayer::Play(std::string soundName, bool loop)
{
    if(loop)
    {
        if(music.openFromFile(("sound/" + soundName + ".wav").c_str()))
        {
            music.setLoop(true);
            volume = 100.0;
            music.play();
            std::cout << music.getStatus() << std::endl;
        }
    }
    else
    {
        //std::cout << sound.getStatus() << std::endl;
        //sf::SoundBuffer bufferSound;
        sound.resetBuffer();
        bufferSound.loadFromFile(("sound/" + soundName + ".wav").c_str());
        sound.setBuffer(bufferSound);
        sound.play();
    }
}

void AudioPlayer::PlayMusic(std::string musicName){
    music.openFromFile(("sound/" + musicName + ".wav").c_str());
    music.setLoop(true);
    music.play();

}

void AudioPlayer::Stop()
{
    music.stop();
    sound.stop();
}
void AudioPlayer::Pause()
{
    music.pause();
}

void AudioPlayer::UnPause()
{
    music.play();
}


void AudioPlayer::SetVolume(float value)
{
    music.setVolume(value);
}

void AudioPlayer::Mute()
{
    if(muted)
    {
        AudioPlayer::SetVolume(volume);
        muted = false;
    }
    else
    {
        volume = music.getVolume();
        AudioPlayer::SetVolume(0);
        muted = true;
    }
}
