/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   drawable.h
 * Author: eye
 *
 * Created on September 23, 2019, 11:32 PM
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2/SDL.h>
class AppClass;

class drawable {
public:
    drawable(AppClass *c);
    drawable(const drawable& orig);
    
    virtual bool draw();
    virtual SDL_Texture *getTexture();
    virtual SDL_Rect *getrect();
    virtual SDL_Rect *clipRect();
    
    virtual bool init(){ return true;};
    virtual ~drawable();
protected:
    AppClass *app;
    
};

#endif /* DRAWABLE_H */

