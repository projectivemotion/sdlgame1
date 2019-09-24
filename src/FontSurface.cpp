/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FontSurface.cpp
 * Author: eye
 * 
 * Created on September 24, 2019, 3:05 AM
 */

#include <SDL2/SDL_ttf.h>

#include "FontSurface.h"

void FontSurface::init(const char* fontpath, int sz) {
    if(TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
    }
    font = TTF_OpenFont(fontpath, sz);
}

SDL_Surface *FontSurface::render(const char* t, const SDL_Color &textColor){
//    if(surface != nullptr)
//        SDL_FreeSurface(surface);
//    
//    surface = nullptr;
    surface = TTF_RenderText_Solid(font, t, textColor);
    if( surface == nullptr )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        return nullptr;
    }
    return surface;
}

SDL_Surface *FontSurface::getSurface()
{
    return surface;
}

FontSurface::FontSurface(const FontSurface& orig) {
}
FontSurface::FontSurface() {
    font = nullptr;
    surface = nullptr;
}

FontSurface::~FontSurface() {
    TTF_CloseFont(font);
    TTF_Quit();
}

