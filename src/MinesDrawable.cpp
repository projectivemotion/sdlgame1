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
    auto sprites = am.openid(ASSET_SPRITES);
    auto font = am.openFont(ASSET_FONT, 80);
    
    
    int w = 640;
    int h = 480;
    cw = floor(w/state->getW());
    ch = floor(h/state->getH());
    
    // init shapes map
    
    int spwh = 17;
    
    entity<SDL_Surface> tree(sprites, spwh, spwh, 21, 21);
    entity<SDL_Surface> square(sprites, spwh, spwh, 21, 25);
    entity<SDL_Surface> red(dots);
    entity<SDL_Surface> yellow(dots);
    entity<SDL_Surface> green(dots);
    entity<SDL_Surface> blue(dots);
    
//        yellow.from(0, 100, 100, 100)->resize(100,100);
        yellow.from(0, 100, 100, 100);
        red.from(0, 0, 100, 100)->resize(100,100);
        green.from(100, 0, 100, 100)->resize(100,100);    
        blue.from(100, 100, 100, 100)->resize(100,100);
        
        auto makecell = [&am, yellow, font, this](const char *str, const SDL_Color& tcolor){
            auto t = font->prender(str, tcolor);
            entity<SDL_Surface> te(t, 100, 100, 0, 0); //(t.get());
//            te.from(0,0,100,100)->move(20,0);
            te.move(20,0);
            entity<SDL_Surface> e(am.write(yellow, te), 100, 100, 0, 0);
            e.resize(cw, ch);
            return e;
        };
        
//        square.resize(spwh*4, spwh*4);
//        square.resize(8, 8);
        
        shapes[state->COVERED] = square;    //.resize(cw, ch);
        shapes[state->MINE] = tree.resize(cw, ch);
        shapes[0] = blue;
        shapes[1] = makecell("1", {0,255,0,255});
        shapes[2] = makecell("2", {0,128,0,255});
        shapes[3] = makecell("3", {0,0,255,255});
        shapes[4] = makecell("4", {0,0,128,255});
        shapes[5] = makecell("5", {0,0,0,255});
        shapes[6] = makecell("6", {0,0,0,255});
        shapes[7] = makecell("7", {128,0,0,255});
        shapes[8] = makecell("8", {255,0,0,255});
        
    // end init shapes map
    
    buildTexture();
    rect.x = 0;
    rect.y = 0;
    rect.w =640;
    rect.h = 480;
    return true;
}

SDL_Rect *MinesDrawable::getrect(){
    return &rect;
}

SDL_Texture * MinesDrawable::getTexture(){
//    if(textx == nullptr)
        if(t.get() == nullptr)
        return buildTexture();
    
    return t.get();
//    return textx;
}

SDL_Texture * MinesDrawable::buildTexture(){
    clear();
    
    int w = 640;
    int h = 480;
    int cw = floor(w/state->getW());
    int ch = floor(h/state->getH());
    
    auto am = app->getAssetManager();
    auto surfaceptr = am.createSurfaceEntity(w,h);
    
    entity<SDL_Surface> *sprite;
    for(auto *cell : state->getcells())
    {
//        int v = cell->value;
        int v = state->getstate(cell);
        sprite = &shapes[v];
//        printf("Drawing v:%d %d %d %d %d\n", v, cell->x, cell->y, cw, ch);
        sprite->move(cell->x*cw, cell->y*ch);
        
        surfaceptr.draw(*sprite);

    }
        
    t = am.fromSurface(surfaceptr, app);
//    textx = SDL_CreateTextureFromSurface(app->ren, surfaceptr.get());
    
    return t.get();    
}
