/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SpriteScene.cpp
 * Author: eye
 * 
 * Created on October 15, 2019, 4:33 PM
 */

#include "SpriteScene.h"
#include "DrawableTexture.h"
#include "entities/entity.h"


bool SpriteScene::init() {    
    
    auto am = app->getAssetManager();
    auto canvas = am.createSurfaceEntity(300, 200);    
    auto dots = am.openid(ASSET_DOTSIMG);
    
    entity<SDL_Surface> a(dots, 100, 100, 0, 0);
    entity<SDL_Surface> b(dots, 100, 100, 1, 0);
    entity<SDL_Surface> c(dots, 100, 100, 0, 1);
    entity<SDL_Surface> d(dots, 100, 100, 1, 1);
    
    entity<SDL_Surface> z(dots, 200, 200);
    
    canvas.draw(z.move(200,100).resize(100,100));
    canvas.draw(a.move(0,0));
    canvas.draw(b.move(100,0));
    canvas.draw(c.move(200,0));
    canvas.draw(d.move(0,100));
//    canvas.draw(d);
    
//    auto clip = am.fromSurface(canvas, app).resize(100, 100);
    auto stretched = am.fromSurface(canvas, app).resize(300, 300);
    auto proportional = am.fromSurface(canvas, app).resize(300, 200).move(300,0);
    
    group.add(stretched, app);
    group.add(proportional, app);
    
    return true;
}

SpriteScene::~SpriteScene() {
}

