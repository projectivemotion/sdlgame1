/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DrawableTexture.h
 * Author: eye
 *
 * Created on September 24, 2019, 11:18 PM
 */

#ifndef DRAWABLETEXTURE_H
#define DRAWABLETEXTURE_H

#include "drawable.h"

class DrawableTexture : public drawable {
public:
    DrawableTexture(AppClass* a, SDL_Texture* t, const SDL_Rect& r) : drawable(a) {
        texture = t;
        rect = r;
    }
    
    bool init(){
        return true;
    }
    
    
    SDL_Texture* getTexture(){
        return texture;
    }
    
    SDL_Rect* getRect(){
        return &rect;
    }
    
    virtual ~DrawableTexture(){
        SDL_DestroyTexture(texture);
    }
private:
    SDL_Rect rect;
    SDL_Texture* texture;
};

#endif /* DRAWABLETEXTURE_H */

