/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   entity.cpp
 * Author: eye
 * 
 * Created on September 17, 2019, 10:25 PM
 */

#include "entities/entity.h"

entity::entity(){
    
}

entity::entity(SDL_Texture *texture) {
    x = texture;
}

void entity::free(){
    if(x == NULL)
        return;
    SDL_DestroyTexture(x);
    x = NULL;
}

entity& entity::move(int x, int y) {
    t.x = x;
    t.y = y;
    return *this;    
}

SDL_Rect& entity::getrect(){
    return t;
}

entity& entity::resize(int w, int h){
    t.w = w;
    t.h = h;
    return *this;    
}

entity* entity::from(int x, int y, int w, int h) {
    s.x = x;
    s.y = y;
    s.w = w;
    s.h = h;
    
    t.x = 0;
    t.y = 0;
    t.w = w;
    t.h = h;
    return this;
}

void entity::draw(SDL_Renderer *ren) {
    SDL_RenderCopy(ren, x, &s, &t);
//    return true;
}

entity::entity(const entity& orig) {
}

entity::~entity() {
}

