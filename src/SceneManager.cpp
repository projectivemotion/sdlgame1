/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SceneManager.cpp
 * Author: eye
 * 
 * Created on September 24, 2019, 10:20 PM
 */

#include "SceneManager.h"
#include "scene/menuscene.h"
#include "scene/BackgroundScene.h"
#include "BallScene.h"
#include "MinesScene.h"
#include <memory>

SceneManager::SceneManager() {
//    app = papp;
}

BaseScene* SceneManager::gotoScene(sceneid id) {
    activescene = scenes[id].get();
    return activescene;
}

bool SceneManager::init(AppClass *app) {
//    
//    auto addscene = [this](sceneid id, std::shared_ptr<BaseScene> sp){
//        sp->init();
//        scenes[id] = sp;
//    };
//    
//    addscene(SCENE_MENU, std::make_shared<menuscene>(app));
    
    
    scenes[SCENE_MENU] = std::make_shared<menuscene>(app);
    scenes[SCENE_MENU]->init();
    scenes[SCENE_BACKGROUND] = std::make_shared<BackgroundScene>(app);
    scenes[SCENE_BACKGROUND]->init();
    scenes[SCENE_5BALLS] = std::make_shared<BallScene>(app);
    scenes[SCENE_5BALLS]->init();
    scenes[SCENE_MINES] = std::make_shared<MinesScene>(app);
    scenes[SCENE_MINES]->init();
    
    // test
//    for(int i = 0 ; i < 50000 ; i++){
//        auto *b = new BallScene(app);
//        b->init();
//    }
    
    gotoScene(SCENE_MENU);
    return true;
}

bool SceneManager::loop(){    
    activescene->loop();
    return true;
}

SceneManager::SceneManager(const SceneManager& orig) {
}

SceneManager::~SceneManager() {
}

