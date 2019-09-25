/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManagedScene.h
 * Author: eye
 *
 * Created on September 24, 2019, 11:03 PM
 */

#ifndef MANAGEDSCENE_H
#define MANAGEDSCENE_H

#include "BaseScene.h"
#include "drawgroup.h"

class ManagedScene : public BaseScene {
public:    
    using BaseScene::BaseScene;
    
    virtual bool draw();
    virtual ~ManagedScene();
    
protected:
    drawgroup group;
};

#endif /* MANAGEDSCENE_H */

