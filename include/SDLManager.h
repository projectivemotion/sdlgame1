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
#include <set>

class SDLManager {
public:
    SDLManager();
    SDL_Surface *open(SDL_Surface *sf);
    
    SDLManager(const SDLManager& orig);
    virtual ~SDLManager();
private:
    std::set<void*> ptr;
};

#endif /* SDLMANAGER_H */

