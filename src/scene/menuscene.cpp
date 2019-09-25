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
}
bool menuscene::handle_ev_mousedown(SDL_Event* e){
    printf("mouse down %d %d\n", e->motion.x, e->motion.y);
    
        auto* sel = menu->getSelection();

        if(sel == nullptr)
            printf("No selection\n");
        else
            printf("Selection: %s\n", sel->t);
        
        
    if(sel != nullptr){
        app->getSceneManager()->gotoScene(sel->sceneidv);
    //    menu->handleMouseEv(e);
        return false;    
    }
    return true;
}

bool menuscene::handle_ev_mmotion(SDL_Event* e){
//    printf("mouse motion %d %d", e->motion.x, e->motion.y);
    menu->handleMouseEv(e);
    return true;    
}

bool menuscene::init() {
    menu = std::make_shared<menuoptions>(app);
//    menu->setOptionHandler([this](void){
//        auto* sel = menu->getSelection();
//
//        if(sel == nullptr)
//            printf("No selection\n");
//        else
//            printf("Selection: %s\n", sel->t);
//    });
//    
    
    group.add(menu);
    
    return true;
}