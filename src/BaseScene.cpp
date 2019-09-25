/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseScene.cpp
 * Author: eye
 * 
 * Created on September 17, 2019, 7:40 PM
 */

#include "BaseScene.h"
#include "app/AppClass.h"
#include <SDL2/SDL.h>

BaseScene::BaseScene(AppClass* papp) {
    app = papp;
    // esto no se puede hacer aqui
//    this->init();
}

BaseScene::BaseScene(const BaseScene& orig) {
}

bool BaseScene::draw(){
    return true;    
}
bool BaseScene::init(){
    return true;    
}
bool BaseScene::handle_ev_scene(SDL_Event* e){
    return true;    
}
bool BaseScene::handle_ev_mousedown(SDL_Event* e){
    return true;    
}
bool BaseScene::handle_ev_mmotion(SDL_Event* e){
    return true;    
}

bool BaseScene::loop(){ 
    SDL_Event e;
    bool quitscene = false;
    while(false == quitscene){
        while(!quitscene && SDL_PollEvent(&e) != 0)
        {
            switch(e.type){
                
                case SDL_MOUSEBUTTONDOWN:
                    quitscene = false == handle_ev_mousedown(&e);
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                    {
                        app->getSceneManager()->gotoScene(SCENE_MENU);
                        return false;
                    }
                    break;
                case SDL_QUIT:
                    app->quit = true;
                    quitscene = true;
                    break;
                case SDL_MOUSEMOTION:
                    quitscene = false == handle_ev_mmotion(&e);
                    break;
                default:
                    quitscene = false == handle_ev_scene(&e);
            }
        }
        draw();
    }
    // bye 
    printf("Exiting Scene.");
    return true;
}

BaseScene::~BaseScene() {
}

