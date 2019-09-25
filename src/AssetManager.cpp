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

#include "AssetManager.h"

AssetManager::AssetManager() {
}

std::shared_ptr<FontSurface> AssetManager::getFont(const char* path, int size) {
    return std::make_shared<FontSurface>(path, size);
}
std::shared_ptr<ChunkSound> AssetManager::getSound(const char* path) {
    return std::make_shared<ChunkSound>(path);
}

SDL_Surface* AssetManager::open(SDL_Surface *s) {
    ptr.insert((void*)s);
    return s;
}

AssetManager::AssetManager(const AssetManager& orig) {
}

AssetManager::~AssetManager() {
}

