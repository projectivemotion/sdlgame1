/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BackgroundScene.h
 * Author: eye
 *
 * Created on September 24, 2019, 11:15 PM
 */

#ifndef BACKGROUNDSCENE_H
#define BACKGROUNDSCENE_H

#include "ManagedScene.h"


class BackgroundScene : public ManagedScene {
public:
    using ManagedScene::ManagedScene;
    
    virtual bool init();
    virtual ~BackgroundScene();
private:

};

#endif /* BACKGROUNDSCENE_H */

