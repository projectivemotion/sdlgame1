/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   scene.h
 * Author: eye
 *
 * Created on September 17, 2019, 7:40 PM
 */

#ifndef SCENE_H
#define SCENE_H
#include "app/AppClass.h"
#include "BaseScene.h"
#include "../../entities/player/bob.h"
#include "entities/projectiles.h"

class scene : public BaseScene {
public:
    using BaseScene::BaseScene;
    virtual bool init();
    virtual bool draw();
    virtual bool handle_ev_scene(SDL_Event* e);
    virtual ~scene();
private:
    SDL_Texture* loadSurface;
    AppClass * tapp;
    
    projectiles collider;
    bob* player;
    
    int x, y;
};

#endif /* SCENE_H */

