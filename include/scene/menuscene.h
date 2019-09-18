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
#include <SDL2/SDL_ttf.h>

class menuscene : public BaseScene {
    using BaseScene::BaseScene;
    
    virtual bool init();
    virtual bool draw();
    virtual ~menuscene();
private:
    SDL_Texture *sfbg;
    TTF_Font *font;
};

#endif /* MENUSCENE_H */

