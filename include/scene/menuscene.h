/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menuscene.h
 * Author: eye
 *
 * Created on September 23, 2019, 1:49 AM
 */

#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <SDL2/SDL_ttf.h>
#include <memory>
#include "ManagedScene.h"
#include "menuoptions.h"
#include "FontSurface.h"

class menuscene : public ManagedScene {
public:
    using ManagedScene::ManagedScene;
    virtual bool handle_ev_mmotion(SDL_Event *e);
    virtual bool handle_ev_mousedown(SDL_Event *e);
    
    virtual bool init();
    virtual ~menuscene();
    
private:
    std::shared_ptr<menuoptions> menu;
};

#endif /* MENUSCENE_H */

