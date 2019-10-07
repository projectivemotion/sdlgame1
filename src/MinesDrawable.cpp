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
    if(textx != nullptr)
        SDL_DestroyTexture(textx);
}

bool MinesDrawable::init(){
    dots = app->getAssetManager().openid(ASSET_DOTSIMG);
    auto font = app->getAssetManager().openFont(ASSET_FONT, 20);
    
    int w = 640;
    int h = 480;
    int cw = floor(w/state->getW());
    int ch = floor(h/state->getH());
    
    // init shapes map
    entity<SDL_Surface> red(dots);
    entity<SDL_Surface> yellow(dots);
    entity<SDL_Surface> green(dots);
    
        yellow.from(0, 100, 100, 100)->resize(cw, ch);
        red.from(0, 0, 100, 100)->resize(cw, ch);
        green.from(100, 0, 100, 100)->resize(cw, ch);

        shapes[state->MINE] = red;
        shapes[0] = yellow;
        shapes[1] = app->getAssetManager().write(green, 
                font->prender("1", {0,255,128,128}).get());
//        shapes[1] = font->render("1", {0,0,0,255});
        shapes[2] = app->getAssetManager().write(green, 
                font->prender("2", {0,255,128,128}).get());
        shapes[3] = app->getAssetManager().write(green, 
                font->prender("3", {0,255,128,128}).get());
        shapes[4] = app->getAssetManager().write(green, 
                font->prender("4", {0,255,128,128}).get());
        shapes[5] = app->getAssetManager().write(green, 
                font->prender("5", {0,255,128,128}).get());
        shapes[6] = app->getAssetManager().write(green, 
                font->prender("6", {0,255,128,128}).get());
        shapes[7] = app->getAssetManager().write(green, 
                font->prender("7", {0,255,128,128}).get());
        shapes[8] = app->getAssetManager().write(green, 
                font->prender("8", {0,255,128,128}).get());
        
        for(auto &b : shapes)
        {
//            if(b.first > 1)
                b.second.resize(cw, ch);
        }
    
    // end init shapes map
    
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
    
    entity<SDL_Surface> *sprite;
    for(auto *cell : state->getcells())
    {
        int v = cell->value;
//        int v = cell->value;
//        sprite = &yellow;
        sprite = &shapes[v];
//        if(state->ismine(*cell.value))
//        {
//            sprite = &red;
//        }
        
//        printf("Drawing v:%d %d %d %d %d\n", v, cell.x, cell.y, cw, ch);
        printf("Drawing v:%d %d %d %d %d\n", v, cell->x, cell->y, cw, ch);
        sprite->move(cell->x*cw, cell->y*ch);

        SDL_BlitScaled(sprite->get(), sprite->getclip(), surfaceptr.get(), &sprite->getrect());
//        SDL_BlitScaled(sprite->get(), nullptr, surfaceptr.get(), &sprite->t);
    }
        
    textx = SDL_CreateTextureFromSurface(app->ren, surfaceptr.get());
    
    return textx;    
}
