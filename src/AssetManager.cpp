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
#include <iostream>

AssetManager::AssetManager() {
}

std::shared_ptr<FontSurface> AssetManager::getFont(const char* path, int size) {
    return std::make_shared<FontSurface>(path, size);
}

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

std::shared_ptr<SDL_Surface> AssetManager::open(SDL_Surface *sfc) {

    return std::shared_ptr<SDL_Surface>(sfc, [](auto p) {
       std::cout << "Call delete from lambda...\n";

       SDL_FreeSurface(p);
    }); 
}

//AssetManager::AssetManager(const AssetManager& orig) {
//}

AssetManager::~AssetManager() {
}

