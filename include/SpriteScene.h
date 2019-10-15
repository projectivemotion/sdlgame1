/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SpriteScene.h
 * Author: eye
 *
 * Created on October 15, 2019, 4:33 PM
 */

#ifndef SPRITESCENE_H
#define SPRITESCENE_H

#include "ManagedScene.h"

class SpriteScene : public ManagedScene {
public:
    using ManagedScene::ManagedScene;
    
    virtual bool init();
    virtual ~SpriteScene();
private:
//    entity<SDL_Texture> t;
};

#endif /* SPRITESCENE_H */

