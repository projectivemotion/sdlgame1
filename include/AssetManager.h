/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SDLManager.h
 * Author: eye
 *
 * Created on September 24, 2019, 3:43 AM
 */

#ifndef SDLMANAGER_H
#define SDLMANAGER_H

#include <SDL2/SDL.h>
#include "FontSurface.h"
#include "ChunkSound.h"
#include <set>
#include <memory>


class AssetManager {
public:
    AssetManager();
    AssetManager(const AssetManager& orig);
    
    SDL_Surface *open(SDL_Surface *sf);
    
    std::shared_ptr<FontSurface> getFont(const char*path, int size);
    std::shared_ptr<ChunkSound> getSound(const char*path);
    
    virtual ~AssetManager();
private:
    std::set<void*> ptr;
    
};

#endif /* SDLMANAGER_H */

