/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BallScene.h
 * Author: eye
 *
 * Created on September 25, 2019, 2:30 AM
 */

#ifndef BALLSCENE_H
#define BALLSCENE_H

#include "scene/BackgroundScene.h"
#include "BounceBall.h"


class BallScene : public BackgroundScene {
public:
    using BackgroundScene::BackgroundScene;
    virtual bool handle_ev_mmotion(SDL_Event *e);
    virtual bool init();
    virtual ~BallScene();
private:
    
    BounceBall* ballptr;

};

#endif /* BALLSCENE_H */

