/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinesDrawable.cpp
 * Author: eye
 * 
 * Created on October 4, 2019, 2:21 AM
 */

#include <SDL2/SDL_render.h>

#include "drawable/MinesDrawable.h"
#include "app/AppClass.h"
#include "DrawableTexture.h"
#include "BounceBall.h"

//MinesDrawable::MinesDrawable() {
//}
//
//MinesDrawable::MinesDrawable(const MinesDrawable& orig) {
//}

void MinesDrawable::setState(MinesState *pstate)
{
    state = pstate;
}

MinesDrawable::~MinesDrawable() {
}

bool MinesDrawable::init(){
    dots = app->getAssetManager().openid(ASSET_DOTSIMG);
    
    buildTexture();
    rect.x = 0;
    rect.y = 0;
    rect.w =640;
    rect.h = 480;
    return true;
}

SDL_Rect *MinesDrawable::getRect(){
    return &rect;
}

SDL_Texture * MinesDrawable::getTexture(){
    return textx;
}

SDL_Texture * MinesDrawable::buildTexture(){
    if(textx != nullptr)
        SDL_DestroyTexture(textx);
    
    int w = 640;
    int h = 480;
    int cw = floor(w/state->getW());
    int ch = floor(h/state->getH());
    
    auto surfaceptr = app->getAssetManager().open(
        SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0)
    );
    
    entity<SDL_Surface> red(dots.get());
    entity<SDL_Surface> yellow(dots.get());
    
    yellow.from(0, 100, 100, 100)->resize(cw, ch);
    red.from(0, 0, 100, 100)->resize(cw, ch);
//    red.from(0, 100, cw, ch)->resize(cw, ch);
    
    entity<SDL_Surface> *sprite;
    for(const auto &cell : state->getcells())
    {
        sprite = &yellow;
        if(state->ismine(*cell.value))
        {
            sprite = &red;
        }
        
        printf("Drawing %d %d %d %d\n", cell.x, cell.y, cw, ch);
        sprite->move(cell.x*cw, cell.y*ch);

//            SDL_BlitSurface(red.get(), &red.s, surfaceptr.get(), &red.t);
        SDL_BlitScaled(sprite->get(), &sprite->s, surfaceptr.get(), &sprite->t);
    }
        
    textx = SDL_CreateTextureFromSurface(app->ren, surfaceptr.get());
    
    return textx;    
}
