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
    clear();
}

bool MinesDrawable::init(){
    auto am = app->getAssetManager();
    dots = am.openid(ASSET_DOTSIMG);
    auto font = am.openFont(ASSET_FONT, 80);
    
    
    int w = 640;
    int h = 480;
    cw = floor(w/state->getW());
    ch = floor(h/state->getH());
    
    // init shapes map
    entity<SDL_Surface> red(dots);
    entity<SDL_Surface> yellow(dots);
    entity<SDL_Surface> green(dots);
    entity<SDL_Surface> blue(dots);
    
        yellow.from(0, 100, 100, 100)->resize(100,100);
        red.from(0, 0, 100, 100)->resize(100,100);
        green.from(100, 0, 100, 100)->resize(100,100);    
        blue.from(100, 100, 100, 100)->resize(100,100);
        
        auto makecell = [&am, yellow, font](const char *str){
            auto t = font->prender(str, {0,0,0,255});
            entity<SDL_Surface> te = t; //(t.get());
            te.from(0,0,100,100)->move(20,0);
            return am.write(yellow, te);
        };
        
        shapes[state->COVERED] = green;
        shapes[state->MINE] = red;
        shapes[0] = blue;
//        shapes[1] = app->getAssetManager().write(yellow, 
//                font->prender("1", {0,0,0,255}).get());
        shapes[1] = makecell("1");
//        shapes[1] = font->render("1", {0,0,0,255});
        shapes[2] = makecell("2");
        shapes[3] = makecell("3");
        shapes[4] = makecell("4");
        shapes[5] = makecell("5");
        shapes[6] = makecell("6");
        shapes[7] = makecell("7");
        shapes[8] = makecell("8");
        
        for(auto &b : shapes)
        {
            if(b.first > 1)
                b.second.from(0,0,100,100);
            
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
    if(textx == nullptr)
        return buildTexture();
    
    return textx;
}

SDL_Texture * MinesDrawable::buildTexture(){
    clear();
    
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
//        int v = cell->value;
        int v = state->getstate(cell);
        sprite = &shapes[v];
        printf("Drawing v:%d %d %d %d %d\n", v, cell->x, cell->y, cw, ch);
        sprite->move(cell->x*cw, cell->y*ch);

        SDL_BlitScaled(sprite->get(), sprite->getclip(), surfaceptr.get(), &sprite->getrect());
//        SDL_BlitScaled(sprite->get(), nullptr, surfaceptr.get(), &sprite->t);
    }
        
    textx = SDL_CreateTextureFromSurface(app->ren, surfaceptr.get());
    
    return textx;    
}
