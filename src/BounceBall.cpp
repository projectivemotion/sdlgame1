/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BounceBall.cpp
 * Author: eye
 * 
 * Created on September 25, 2019, 2:32 AM
 */

#include "BounceBall.h"
#include "app/AppClass.h"

BounceBall::BounceBall(AppClass *app) 
: DrawableTexture(app, app->loadSurface("assets/dots.png"), {280,190, 100, 100})
{
//    int x = 3+4;
    
    clip.x = 100;
    clip.y = 100;
    clip.w = 100;
    clip.h= 100;    
}

SDL_Rect *BounceBall::clipRect()
{
    return &clip;
}

SDL_Rect *BounceBall::getrect()
{
//    SDL_GetMouseState( &rect.x, &rect.y);
    return &rect;
}
//    auto *r = ballptr->getRect();
//    int get_fX, get_fY;
//
//BounceBall::BounceBall(const BounceBall& orig) {
//}

BounceBall::~BounceBall() {
}

