/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BallScene.cpp
 * Author: eye
 * 
 * Created on September 25, 2019, 2:30 AM
 */

#include "BallScene.h"
#include "BounceBall.h"

bool BallScene::init() {
    BackgroundScene::init();
    
    auto ball = std::make_shared<BounceBall>(app);
    group.add(ball);
    ballptr = ball.get();
    // sup
    return true;
}

//BallScene::BallScene(const BallScene& orig) {
//}
bool BallScene::handle_ev_mmotion(SDL_Event* e){
    
    auto *r = ballptr->getRect();
    r->x = e->motion.x-50;
    r->y = e->motion.y-50;
//    printf("%d %d", r->x, r->y);
    return true;    
}

BallScene::~BallScene() {
}

