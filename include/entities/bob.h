/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bob.h
 * Author: eye
 *
 * Created on September 17, 2019, 10:28 PM
 */

#ifndef BOB_H
#define BOB_H
#include "app/AppClass.h"
#include "entities/entity.h"


class bob{
public:
    bob(AppClass& app);
    bob(const bob& orig);
    
    entity<SDL_Texture> *getentity();
    virtual ~bob();
private:
    entity<SDL_Texture> *e;
};

#endif /* BOB_H */

