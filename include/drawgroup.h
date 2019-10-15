/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   drawgroup.h
 * Author: eye
 *
 * Created on September 24, 2019, 12:11 AM
 */

#ifndef DRAWGROUP_H
#define DRAWGROUP_H

#include <list>
#include <memory>
#include "drawable.h"
#include "app/AppClass.h"
#include "EntityRenderer.h"

class drawgroup {
public:
    drawgroup();
    drawgroup(const drawgroup& orig);
    drawable* add(std::shared_ptr<drawable> ptr);
    
    template <class T>
    drawable* add(const entity<T>& e, AppClass *app){
        drawables.push_back(std::make_shared<EntityRenderer<T>>(e, app));
        return nullptr;
    }

//    drawable* add(entity<SDL_Texture> e, AppClass *app);
    virtual bool draw(AppClass *app);
    virtual ~drawgroup();
private:
    std::list<std::shared_ptr<drawable>> drawables;
};

#endif /* DRAWGROUP_H */

