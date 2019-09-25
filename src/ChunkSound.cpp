/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChunkSound.cpp
 * Author: eye
 * 
 * Created on September 25, 2019, 2:03 AM
 */

#include "ChunkSound.h"

ChunkSound::ChunkSound(const char* path) {
    s1 = nullptr;
//    s1 = Mix_LoadWAV( "assets/guncock.wav" );
    s1 = Mix_LoadWAV(path);
    if( s1 == nullptr )
    {
        printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//        return false;
    }
}

void ChunkSound::play(){
    Mix_PlayChannel( -1, s1, 0 );
}

//ChunkSound::ChunkSound(const ChunkSound& orig) {
//}

ChunkSound::~ChunkSound() {
    Mix_FreeChunk(s1);
}

