/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   drawable.cpp
 * Author: eye
 * 
 * Created on September 23, 2019, 11:32 PM
 */

#include "drawable.h"

drawable::drawable(AppClass *c) {
    app = c;
}

SDL_Texture *drawable::getTexture() {
    return nullptr;
}

SDL_Rect *drawable::getRect() {
    return nullptr;
}

SDL_Rect *drawable::clipRect() {
    return nullptr;
}

bool drawable::draw(){
    SDL_RenderCopy(app->ren, getTexture(), clipRect(), getRect());
    return true;
}

drawable::drawable(const drawable& orig) {
}

drawable::~drawable() {
}

