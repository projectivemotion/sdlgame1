/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   entity.h
 * Author: eye
 *
 * Created on September 17, 2019, 10:25 PM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL_render.h>


class entity {
public:
    entity();
    entity(SDL_Texture *texture);
    entity(const entity& orig);
    
    virtual entity* from(int x, int y, int w, int h);
    virtual entity& move(int x, int y);
    virtual entity& resize(int w, int h);
    
    SDL_Rect &getrect();
    
    virtual void draw(SDL_Renderer *ren);
    virtual void free();
    
    virtual ~entity();
protected:
    SDL_Texture *x;
    SDL_Rect t;
    SDL_Rect s;
};

#endif /* ENTITY_H */

