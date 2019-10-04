/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinesDrawable.h
 * Author: eye
 *
 * Created on October 4, 2019, 2:21 AM
 */

#ifndef MINESDRAWABLE_H
#define MINESDRAWABLE_H
#include "drawable.h"
#include "MinesState.h"

class MinesDrawable : public drawable {
public:
    using drawable::drawable;

    virtual SDL_Texture *getTexture();
    virtual SDL_Rect *getRect();
//    virtual SDL_Rect *clipRect();    
    virtual bool init();
//    virtual bool draw();
    
    SDL_Texture *buildTexture();
    
public:
    void setState(MinesState *pstate);
    virtual ~MinesDrawable();
    
private:
    
    std::map<int, entity<SDL_Surface>> shapes;
    
    SDL_Texture* textx = nullptr;
    
    std::shared_ptr<SDL_Surface> dots;
    
    SDL_Rect rect;
    MinesState *state;
    
    int cellpos;
};

#endif /* MINESDRAWABLE_H */

