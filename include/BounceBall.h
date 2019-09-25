/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BounceBall.h
 * Author: eye
 *
 * Created on September 25, 2019, 2:32 AM
 */

#ifndef BOUNCEBALL_H
#define BOUNCEBALL_H

#include "DrawableTexture.h"

class BounceBall : public DrawableTexture {
public:
    BounceBall(AppClass *app);
    virtual SDL_Rect* clipRect();
    virtual SDL_Rect *getRect();
    virtual ~BounceBall();
private:
    SDL_Rect clip;
};

#endif /* BOUNCEBALL_H */

