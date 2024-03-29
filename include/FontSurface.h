/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FontSurface.h
 * Author: eye
 *
 * Created on September 24, 2019, 3:05 AM
 */

#ifndef FONTSURFACE_H
#define FONTSURFACE_H

#include "SurfaceMaker.h"
#include <SDL2/SDL_ttf.h>
#include <memory>

class AssetManager;

class FontSurface : public SurfaceMaker {
public:
//    FontSurface();
    FontSurface(const char* fontpath, int sz, AssetManager *am);
    
    void init(const char* fontpath, int sz);
    FontSurface(const FontSurface& orig);
    
    virtual std::shared_ptr<SDL_Surface> prender(const char* t, const SDL_Color& color);
    virtual SDL_Surface* render(const char* t, const SDL_Color& color);
    virtual SDL_Surface* getSurface();
    virtual ~FontSurface();
private:
    AssetManager *mgr;
    SDL_Surface* surface;
    TTF_Font *font;
};

#endif /* FONTSURFACE_H */

