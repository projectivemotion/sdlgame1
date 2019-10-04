/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   projectiles.cpp
 * Author: eye
 * 
 * Created on September 17, 2019, 11:56 PM
 */

#include "entities/projectiles.h"

projectiles::projectiles() {
}

projectiles::projectiles(const projectiles& orig) {
}

projectiles::~projectiles() {    
    for(auto const& p : flying){
        delete p.ball;
    }
}

void projectiles::draw(AppClass& app) {
    const int s = 30;
    for(auto const& p : flying){
        SDL_Rect r = p.ball->getrect();
        SDL_Rect s = p.speed;
        p.ball->move(r.x + s.x, r.y + s.y);
        app.draw(*p.ball);
    }
}

void projectiles::fire(entity<SDL_Texture>* e, SDL_Rect speed){
    flying.push_front({e, speed});
}
