/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SDLManager.cpp
 * Author: eye
 * 
 * Created on September 24, 2019, 3:43 AM
 */

#include "SDLManager.h"

SDLManager::SDLManager() {
}

SDL_Surface* SDLManager::open(SDL_Surface *s) {
    ptr.insert((void*)s);
    return s;
}

SDLManager::SDLManager(const SDLManager& orig) {
}

SDLManager::~SDLManager() {
}

