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

#include "scene/BaseScene.h"
#include "drawgroup.h"
#include <SDL2/SDL_ttf.h>
#include <memory>
#include "menuoptions.h"
#include "FontSurface.h"

class menuscene : public BaseScene {
    using BaseScene::BaseScene;
    virtual bool handle_mouse_motion(SDL_Event *e);
    
    virtual bool init();
    virtual bool draw();
    virtual ~menuscene();
    
private:
    drawgroup group;
    SDL_Texture *sfbg;
    std::shared_ptr<menuoptions> menu;
    std::unique_ptr<FontSurface> writer;
};

#endif /* MENUSCENE_H */

