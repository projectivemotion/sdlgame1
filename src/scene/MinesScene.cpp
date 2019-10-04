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


bool MinesScene::init() {
//    auto menu = std::make_shared<menuoptions>(app);
    state.init(20,20);
    state.Easy();
    auto mines = std::make_shared<MinesDrawable>(app);
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