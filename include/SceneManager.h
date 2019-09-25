/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SceneManager.h
 * Author: eye
 *
 * Created on September 24, 2019, 10:20 PM
 */

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <map>
#include <memory>
#include "BaseScene.h"
#include "sceneslib.h"

class AppClass;

class SceneManager {
public:
    SceneManager();
    SceneManager(const SceneManager& orig);
    
    virtual bool init(AppClass* app);
    virtual BaseScene* gotoScene(sceneid id);
    virtual bool loop();
    
    virtual ~SceneManager();
private:
    AppClass *app;
    BaseScene *activescene;
    std::map<sceneid,std::shared_ptr<BaseScene>> scenes;
};

#endif /* SCENEMANAGER_H */

