/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseScene.h
 * Author: eye
 *
 * Created on September 17, 2019, 7:40 PM
 */

#ifndef BASESCENE_H
#define BASESCENE_H
//#include "app/AppClass.h"
#include <SDL2/SDL_events.h>

class AppClass;

class BaseScene {
public:
    BaseScene(AppClass* app);
    BaseScene(const BaseScene& orig);
    
    virtual bool init();
    virtual bool handle_ev_mmotion(SDL_Event *e);
    virtual bool handle_ev_mousedown(SDL_Event *e);
    virtual bool handle_ev_keydown(SDL_Event *e);
    virtual bool handle_ev_scene(SDL_Event *e);
    virtual bool loop();
    virtual bool draw();
    virtual ~BaseScene();
protected:
    AppClass* app;
};

#endif /* BASESCENE_H */

