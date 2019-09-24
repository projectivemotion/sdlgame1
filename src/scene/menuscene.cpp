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
#include "menuoptions.h"

menuscene::~menuscene() {
//    TTF_CloseFont(font);
//    TTF_Quit();
}


bool menuscene::draw(){
    
    SDL_RenderClear(app->ren );
    group.draw(app);
    SDL_RenderPresent( app->ren );
    
    return true;
}

bool menuscene::init() {
//    tapp = &app;
    group.add(std::make_shared<menuoptions>(app));
    sfbg = app->loadSurface("dots.png");
    return true;
}