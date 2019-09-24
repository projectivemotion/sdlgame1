/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menuscene.cpp
 * Author: eye
 * 
 * Created on September 23, 2019, 1:49 AM
 */

#include "scene/menuscene.h"

menuscene::~menuscene() {
//    TTF_CloseFont(font);
//    TTF_Quit();
}

bool menuscene::handle_mouse_motion(SDL_Event* e){
    printf("mouse motion %d %d", e->motion.x, e->motion.y);
    menu->handleMouseEv(e);
    return true;    
}


bool menuscene::draw(){
    
    SDL_RenderClear(app->ren );
    group.draw(app);
    SDL_RenderPresent( app->ren );
    
    return true;
}

bool menuscene::init() {
//    tapp = &app;
    menu = std::make_shared<menuoptions>(app);
    group.add(menu);
    sfbg = app->loadSurface("dots.png");
    return true;
}