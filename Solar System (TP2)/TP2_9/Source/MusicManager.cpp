#include "../Header/MusicManager.h"


void MusicManager::configureMusic()
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    addMusic(Mix_LoadMUS("audio/background1.mp3"));
    Mix_PlayMusic(getMusic(0),-1);
    Mix_VolumeMusic(0);
}

void MusicManager::marsMusic(double distance)
{
    if(6 < distance)
        Mix_VolumeMusic(0);

    else if(2.5 <= distance && distance <= 6)
        Mix_VolumeMusic(-36.5 * distance + 219);
    
    else if(distance < 2.5)
        Mix_VolumeMusic(128);
}
