/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   projectiles.h
 * Author: eye
 *
 * Created on September 17, 2019, 11:56 PM
 */

#ifndef PROJECTILES_H
#define PROJECTILES_H

#include "app/AppClass.h"
#include "entities/entity.h"
#include <list>

typedef struct {
    entity<SDL_Texture>* ball;
    SDL_Rect speed;
} projectile;

class projectiles {
public:
    projectiles();
    projectiles(const projectiles& orig);
    void draw(AppClass& app);
    void fire(entity<SDL_Texture>* e, SDL_Rect speed);
    virtual ~projectiles();
private:
    std::list<projectile> flying;
};

#endif /* PROJECTILES_H */

