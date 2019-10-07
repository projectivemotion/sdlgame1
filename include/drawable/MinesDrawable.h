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
    
    inline void clear(){
        if(textx == nullptr)
            return;
        
        SDL_DestroyTexture(textx);
        textx = nullptr;
    }

    virtual SDL_Texture *getTexture();
    virtual SDL_Rect *getRect(); 
    virtual bool init();
    
    SDL_Texture *buildTexture();
    
public:
    
    void getCWH(int& w, int&h){ w = cw; h = ch; }
    
    void setState(MinesState *pstate);
    virtual ~MinesDrawable();
    
private:
    SDL_Texture* textx = nullptr;
    std::map<int, entity<SDL_Surface>> shapes;
    std::shared_ptr<SDL_Surface> dots;
    
    SDL_Rect rect;
    MinesState *state;
    
    int cw;
    int ch;
    int cellpos;
};

#endif /* MINESDRAWABLE_H */

