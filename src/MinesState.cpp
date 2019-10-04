/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinesState.cpp
 * Author: eye
 * 
 * Created on October 3, 2019, 11:54 PM
 */
#include <stdio.h>
#include <random>
#include "MinesState.h" 

MinesState::MinesState() {
    init(8,8);
}

MinesState::MinesState(const MinesState& orig) {
}

MinesState::~MinesState() {
    if(grid != nullptr)
        delete [] grid;
}

inline int* MinesState::getcell(int x, int y){
    return grid+y*w+x;
}
    
int* MinesState::inccell(int x, int y){
    return getcell(x,y);
}
    
void MinesState::init(int pw, int ph){
    w = pw;
    h = ph;
    
    if(grid != nullptr)
        delete [] grid;
        
    grid = new int[w*h];
    
    for(int i = 0; i < w*h; i++)
        grid[i] = 0;
    
    
}
//
//int* MinesState::setmine(int* cell){    
//        *cell = MINE;
//    
//}
    
int* MinesState::setmine(int x, int y){
    int* cell = getcell(x,y);    
        *cell = MINE;
        
    int baz[18] = {
            -1, -1,
            0, -1,
            1, -1,
            -1, 0,
//            0, 0,
            1, 0,
            -1, 1,
            0, 1,
            1, 1,
            0, 0    // end marker
    };
    
    for(int *v = baz; *v != 0 || *(v+1) != 0;)
    {
        int cx = x+*(v++);
        int cy = y+*(v++);
        if(cx < 0 || cx >= w || cy < 0 || cy >= h) continue;
        int *cell = getcell(cx, cy);
        if(ismine(*cell)) continue;
        (*cell)++;
    }
        
    return cell;
}

void MinesState::Easy(){
    int minecount = ceil(w*h/10);
    
    // Choose a random mean between 1 and 6
    std::random_device dev;
    std::default_random_engine e1(dev());
    
    std::uniform_int_distribution<int> rw(0,w-1);
    std::uniform_int_distribution<int> rh(0,h-1);
    
    for(int i = 0; i < minecount; i++){
        int pw = rw(e1);
        int ph = rw(e1);
        setmine(pw, ph);
        printf("%d %d\n", pw, ph);
    }
    
    print();
}
    
void MinesState::print(){
    for(int i=0; i < h; i++){
        for(int j = 0; j < w; j++){
            int cell = *getcell(j, i);
            if(ismine(cell))
                printf("x");
            else if(cell == 0)
                printf("_");
            else
                printf("%d", cell);
        }
        printf("\n");
    }
}

