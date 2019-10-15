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
#include "entities/entity.h"
#include "app/AppClass.h"

#include <iostream>

AssetManager::AssetManager() {
}

//std::shared_ptr<FontSurface> AssetManager::getFont(const char* path, int size) {
//    return std::make_shared<FontSurface>(path, size);
//}

std::shared_ptr<ChunkSound> AssetManager::getSound(const char* path) {
    return std::make_shared<ChunkSound>(path);
}

std::shared_ptr<SDL_Surface> AssetManager::openid(assetid id) {        
    return open(IMG_Load(assetlibj[id]));
}
std::shared_ptr<FontSurface> AssetManager::openFont(assetid id, int size) {
    
    int ix = size*1000+id;
    auto f = fontA.find(ix);
    if(f == fontA.end())
    {
        auto b = std::make_shared<FontSurface>(assetlibj[id], size, this);
        fontA[ix] = b;        
        return b;
    }
    
    return f->second;
}

//std::shared_ptr<SDL_Surface> AssetManager::write(entity<SDL_Surface> e, SDL_Surface *s) {
std::shared_ptr<SDL_Surface> AssetManager::write(entity<SDL_Surface> e, entity<SDL_Surface> tt) {
    auto *dr = &e.getrect();
    auto* d = SDL_CreateRGBSurface(0, dr->w, dr->h, 32, 0, 0, 0, 0);
    
//    SDL_FillRect(d, NULL, SDL_MapRGB(d->format, 255, 0, 0));

    SDL_BlitSurface(e.get(), e.getclip(), d, dr);
    SDL_BlitSurface(tt.get(), tt.getclip(), d, &tt.getrect());
    
    return open(d);
}


std::shared_ptr<SDL_Surface> AssetManager::open(SDL_Surface *sfc) {
    return std::shared_ptr<SDL_Surface>(sfc, [](auto p) {
       std::cout << "Call delete on Surface from lambda...\n";

       SDL_FreeSurface(p);
    }); 
}


entity<SDL_Surface> AssetManager::createSurfaceEntity(int w, int h) {        
    return open(
        SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0)
    );
}

entity<SDL_Texture> AssetManager::fromSurface(entity<SDL_Surface> &s, AppClass *app) {
    return openT(
            SDL_CreateTextureFromSurface(app->ren, s.get())
//        SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0)
    );
}

//    entity<SDL_Texture> fromSurface(entity<SDL_Surface> &s);

std::shared_ptr<SDL_Texture> AssetManager::openT(SDL_Texture *txt) {
    return std::shared_ptr<SDL_Texture>(txt, [](auto p) {
       std::cout << "Call delete on Texture from lambda...\n";

       SDL_DestroyTexture(p);
    }); 
}

//entity<SDL_Surface> AssetManager::clone(const entity<SDL_Surface> &e){
//    
//}
//AssetManager::AssetManager(const AssetManager& orig) {
//}

AssetManager::~AssetManager() {
}

