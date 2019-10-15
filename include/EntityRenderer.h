/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntityRenderer.h
 * Author: eye
 *
 * Created on October 15, 2019, 5:12 PM
 */

#ifndef ENTITYRENDERER_H
#define ENTITYRENDERER_H

#include "entities/entity.h"
#include "drawable.h"
#include "app/AppClass.h"

template <class E>
class EntityRenderer : public drawable {
public:
    EntityRenderer(entity<E> i, AppClass *papp) : drawable(papp), item(i) 
    {
    }
    
    virtual bool draw(){        
        SDL_RenderCopy(app->ren, item.getTexture(), item.getclip(), &item.getrect());
        return true;
    }
private:
    entity<E> item;
};

#endif /* ENTITYRENDERER_H */

