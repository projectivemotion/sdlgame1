/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   entity.h
 * Author: eye
 *
 * Created on September 17, 2019, 10:25 PM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL_render.h>
#include <memory>

template<class T>
class entity {
public:
    entity(){
    }
    entity(std::shared_ptr<T> texture){
        x = texture;
        from(0,0,0,0);
    }
//    entity(std::shared_ptr<T> p){
//        
//    }
//    entity(const entity& orig);
    
    virtual entity* from(int x, int y, int w, int h);
    virtual entity& move(int x, int y);
    virtual entity& resize(int w, int h);
    virtual T *get(){
        return x.get();
    }
    SDL_Rect &getrect() {
        return t;
    }
    
    SDL_Rect *getclip() {
        if(s.w == 0)
            return nullptr;
        return &s;
    }
//    virtual void draw(SDL_Renderer *ren);
    virtual void free();
    
    virtual ~entity();
    
protected:
    SDL_Rect s;
    SDL_Rect t;
    std::shared_ptr<T> x;
};

#endif /* ENTITY_H */

