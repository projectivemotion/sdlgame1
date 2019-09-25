/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManagedScene.cpp
 * Author: eye
 * 
 * Created on September 24, 2019, 11:03 PM
 */

#include "ManagedScene.h"

bool ManagedScene::draw() {
    
    SDL_RenderClear(app->ren );
    group.draw(app);
    SDL_RenderPresent( app->ren );
    
    return true;
}

ManagedScene::~ManagedScene() {
}

