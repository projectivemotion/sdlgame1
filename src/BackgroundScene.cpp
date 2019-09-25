/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BackgroundScene.cpp
 * Author: eye
 * 
 * Created on September 24, 2019, 11:15 PM
 */

#include "scene/BackgroundScene.h"
#include "DrawableTexture.h"
#include "app/AppClass.h"


bool BackgroundScene::init() {
    
    SDL_Rect rr = {0,0,222,222};
    auto b = std::make_shared<DrawableTexture>( app, app->loadSurface("assets/dots.png"), rr);
    group.add(b);
        return true;
}

BackgroundScene::~BackgroundScene() {
}

