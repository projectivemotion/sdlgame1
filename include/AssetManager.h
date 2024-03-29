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
#include <SDL2/SDL_image.h>

#include "FontSurface.h"
#include "ChunkSound.h"
#include "entities/entity.h"
#include <set>
#include <memory>
#include <map>

class AppClass;

enum assetid {
    ASSET_DOTSIMG,
    ASSET_FONT,
    ASSET_SPRITES,
    ASSETS_TOTAL
};

extern const char* assetlibj[];

struct asset {
    assetid id;
    const char* path;
};


class AssetManager {
public:
    AssetManager();
//    AssetManager(const AssetManager& orig);
    
//    std::shared_ptr<SDL_Surface> write(entity<SDL_Surface> e, SDL_Surface* t);
    std::shared_ptr<SDL_Surface> write(entity<SDL_Surface> e, entity<SDL_Surface> tt);
    std::shared_ptr<SDL_Surface> open(SDL_Surface *sfc);
    entity<SDL_Surface> createSurfaceEntity(int w, int h);
    entity<SDL_Texture> fromSurface(entity<SDL_Surface> &s, AppClass* app);
    
    std::shared_ptr<SDL_Texture> openT(SDL_Texture *sfc);
    std::shared_ptr<SDL_Surface> openid(assetid id);
    std::shared_ptr<FontSurface> openFont(assetid id, int size);
    
    
    std::shared_ptr<FontSurface> getFont(const char*path, int size);
    std::shared_ptr<ChunkSound> getSound(const char*path);
    
    virtual ~AssetManager();


    
private:
    std::map<assetid, std::shared_ptr<SDL_Surface>> surf;
    std::map<int, std::shared_ptr<FontSurface>> fontA;
    std::set<void*> ptr;
    
};

#endif /* SDLMANAGER_H */

