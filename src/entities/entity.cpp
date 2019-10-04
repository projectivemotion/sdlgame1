/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   entity.cpp
 * Author: eye
 * 
 * Created on September 17, 2019, 10:25 PM
 */

#include "entities/entity.h"

//entity::entity(){
//    
//}
//template <class T>
//entity::entity(T *texture) {
//    x = texture;
//}

template <class T>
void entity<T>::free(){
    if(x == NULL)
        return;
//    SDL_DestroyTexture(x);
    x = NULL;
}

template <class T>
entity<T>& entity<T>::move(int x, int y) {
    t.x = x;
    t.y = y;
    return *this;    
}

//template <class T>
//SDL_Rect& entity<T>::getrect(){
//    return t;
//}

template <class T>
entity<T>& entity<T>::resize(int w, int h){
    t.w = w;
    t.h = h;
    return *this;    
}

template <class T>
entity<T>* entity<T>::from(int x, int y, int w, int h) {
    s.x = x;
    s.y = y;
    s.w = w;
    s.h = h;
    
    t.x = 0;
    t.y = 0;
    t.w = w;
    t.h = h;
    return this;
}

//void entity::draw(SDL_Renderer *ren) {
//    SDL_RenderCopy(ren, x, &s, &t);
////    return true;
//}

template <class T>
entity<T>::~entity() {
}



 template class entity<SDL_Texture>;
 template class entity<SDL_Surface>;