/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   drawgroup.cpp
 * Author: eye
 * 
 * Created on September 24, 2019, 12:11 AM
 */

#include "drawgroup.h"
#include "EntityRenderer.h"

drawgroup::drawgroup() {
}

drawable* drawgroup::add(std::shared_ptr<drawable> ptr){
    ptr->init();
    drawables.push_back(ptr);
    return ptr.get();
}
//
//template <class T>
//drawable* drawgroup::add(entity<T>& e, AppClass *app){
//    drawables.push_back(std::make_shared<EntityRenderer<T>>(e, app));
//    return nullptr;
//}

bool drawgroup::draw(AppClass* app) {
    for(auto& it : drawables)
    {
        it->draw();
//        SDL_RenderCopy(app->ren, it->getTexture(), nullptr, it->getRect());
    }
    return true;
}

drawgroup::drawgroup(const drawgroup& orig) {
}

drawgroup::~drawgroup() {
}

