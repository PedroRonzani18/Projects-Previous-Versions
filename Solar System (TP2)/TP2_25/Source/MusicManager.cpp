#include "../Header/MusicManager.h"

// Define configurações de música da SDL2_mixer
void MusicManager::configureMusic()
{
    // Cria um canal de audio
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);

    // Adiciona o arquivo de música ao canal de música
    addMusic(Mix_LoadMUS("audio/background1.mp3"));

    // Inicia a reprodução da música na posição 0 do vector de Mix_Music*
    Mix_PlayMusic(getMusic(0),-1);

    // Define o volume da música para 0 para que ela só possa ser escutada perto de Marte
    Mix_VolumeMusic(0);
}

// Função que determina o volume da música ao aproximar-se de marte analisando a distância entre a câmera e o planeta.
void MusicManager::marsMusic(double distance)
{
    if(6 < distance)
        Mix_VolumeMusic(0);

    else if(2.5 <= distance && distance <= 6)
        Mix_VolumeMusic(-36.5 * distance + 219);
    
    else if(distance < 2.5)
        Mix_VolumeMusic(128);
}
