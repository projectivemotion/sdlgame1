/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinesScene.h
 * Author: eye
 *
 * Created on October 4, 2019, 2:05 AM
 */

#ifndef MINESSCENE_H
#define MINESSCENE_H

#include "ManagedScene.h"
#include "MinesState.h"
#include "drawable/MinesDrawable.h"


class MinesScene : public ManagedScene {
public:
    using ManagedScene::ManagedScene;
    
    virtual bool handle_ev_mousedown(SDL_Event *e);
    virtual bool handle_ev_keydown(SDL_Event *e);
    virtual bool init();
    virtual ~MinesScene();
private:
    MinesState state;
    std::shared_ptr<MinesDrawable> mines;
};

#endif /* MINESSCENE_H */

