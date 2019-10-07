/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinesScene.cpp
 * Author: eye
 * 
 * Created on October 4, 2019, 2:05 AM
 */

#include "MinesScene.h"
#include "menuoptions.h"
#include "drawable/MinesDrawable.h"

MinesScene::~MinesScene() {
}



bool MinesScene::handle_ev_mousedown(SDL_Event* e){
    int cw, ch;
    mines->getCWH(cw, ch);
    
    int x = e->motion.x;
    int y = e->motion.y;
    printf("%d %x\n", x, y);
    
    int px = ceil(x/cw);
    int py = ceil(y/ch);
    
    state.uncover(px, py);
    mines->clear();
    
    return true;    
}
    
bool MinesScene::init() {
//    auto menu = std::make_shared<menuoptions>(app);
    state.init(20,20);
    state.Easy();
    mines = std::make_shared<MinesDrawable>(app);
    mines->setState(&state);
    
//    menu->setOptionHandler([this](void){
//        auto* sel = menu->getSelection();
//
//        if(sel == nullptr)
//            printf("No selection\n");
//        else
//            printf("Selection: %s\n", sel->t);
//    });
//    
    
    group.add(mines);
    
    return true;
}