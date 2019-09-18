/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   scene.cpp
 * Author: eye
 * 
 * Created on September 17, 2019, 7:40 PM
 */

#include "scene.h"
#include <stdio.h>
#include "../../entities/player/bob.h"
#include "entities/projectiles.h"

bool scene::init() {
//    tapp = &app;
    loadSurface = app->loadSurface("dots.png");
    player = new bob(*app);
    x = 0;
    y = 0;
    return true;
}

bool scene::draw(){
    SDL_RenderClear( app->ren );
    const SDL_Rect r = app->getRect();
    const SDL_Rect s = {0, 0, 20, 20};
    
//    player.
    SDL_RenderCopy(app->ren, loadSurface, &s, &r);
    
    collider.draw(*app);
    
    app->draw(
        player->getentity()->move(x, y)
    );
    
    SDL_RenderPresent( app->ren );
    
    
    return true;
}

scene::~scene() {    
    if(loadSurface != NULL)
    SDL_DestroyTexture(loadSurface);
    
    delete player;
}


bool scene::handle_ev_scene(SDL_Event* e){
    const int offx = 60;
//    if(e->type = SDL_KEYUP){
    if(e->type = SDL_KEYDOWN){
        SDL_Scancode scancode = e->key.keysym.scancode;
        if(scancode == SDL_SCANCODE_LEFT)
        {
            x = x - offx;
        }
        if(scancode == SDL_SCANCODE_RIGHT)
        {
            x = x + offx;
        }
        if(scancode == SDL_SCANCODE_UP)
        {
            y = y - offx;
        }
        if(scancode == SDL_SCANCODE_DOWN)
        {
            y = y + offx;
        }
        if(scancode == SDL_SCANCODE_SPACE)
        {
            collider.fire(&(tapp->blue()->move(x, y)), {60, 20});
        }
        if(scancode == SDL_SCANCODE_ESCAPE)
        {
            tapp->scenes.pop_front();   // bye!
            return false;
        }
    }
    return true;    
}