/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChunkSound.h
 * Author: eye
 *
 * Created on September 25, 2019, 2:03 AM
 */

#ifndef CHUNKSOUND_H
#define CHUNKSOUND_H
#include <SDL2/SDL_mixer.h>

class ChunkSound {
public:
    ChunkSound(const char* path);
    
    void play();
//    ChunkSound(const ChunkSound& orig);
    virtual ~ChunkSound();
private:
    Mix_Chunk *s1;
};

#endif /* CHUNKSOUND_H */

