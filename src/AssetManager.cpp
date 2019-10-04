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
//    auto f = surf.find(id);
//    if(f == surf.end()){
        
    return open(IMG_Load(assetlibj[id]));
//        auto ptr = std::shared_ptr<SDL_Surface>(IMG_Load(assetlibj[id]), [](auto p) {
//           std::cout << "Call delete from lambda...\n";
//           
//           SDL_FreeSurface(p);
//        });
     
//        surf[id] = ptr;
//        return ptr;
//    }
    
//    return surf[id];
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

std::shared_ptr<SDL_Surface> AssetManager::write(entity<SDL_Surface> e, SDL_Surface *s) {
    auto *r = &e.getrect();
    auto* d=SDL_CreateRGBSurface(0, r->w, r->h, 32, 0, 0, 0, 0);
    
    SDL_FillRect(d, NULL, SDL_MapRGB(d->format, 255, 0, 0));

//    SDL_BlitSurface(e.get(), nullptr, d, &r);    
    SDL_BlitSurface(s, nullptr, d, nullptr);
    
    return open(d);
}


std::shared_ptr<SDL_Surface> AssetManager::open(SDL_Surface *sfc) {
    return std::shared_ptr<SDL_Surface>(sfc, [](auto p) {
       std::cout << "Call delete from lambda...\n";

       SDL_FreeSurface(p);
    }); 
}

std::shared_ptr<SDL_Texture> AssetManager::openT(SDL_Texture *txt) {
    return std::shared_ptr<SDL_Texture>(txt, [](auto p) {
       std::cout << "Call delete from lambda...\n";

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

