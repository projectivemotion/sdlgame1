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

//inline cellstate* MinesState::getcell(int x, int y){
//    return grid+y*w+x;
//}
    
//cellstate* MinesState::inccell(int x, int y){
//    return getcell(x,y);
//}
    
void MinesState::init(int pw, int ph){
    w = pw;
    h = ph;
    
    if(grid != nullptr)
        delete [] grid;
        
        int size = w*h;
        
    grid = new cellstate[size];
    
    cellstate* cell;
    for(int i = 0; i < h; i++)
        for(int z = 0; z < w ; z++)
        {
            cell = grid + i*w+z;
            cell->x = z;
            cell->y = i;            
            cell->value = 0;
            cell->uncovered = 0;
        }
//        grid[i] = 0;
    
    
}
//
//int* MinesState::setmine(int* cell){    
//        *cell = MINE;
//    
//}
    
cellstate* MinesState::setmine(cellstate *cell){
//    cellstate* cell = getcell(x,y);    
        cell->value = MINE;
        
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
        int cx = cell->x+*(v++);
        int cy = cell->y+*(v++);
        if(cx < 0 || cx >= w || cy < 0 || cy >= h) continue;
        cellstate *cell = getcell(cx, cy);
        if(ismine(cell)) continue;
        // 
        cell->value++;
//        (*cell)++;
    }
        
    return cell;
}

int MinesState::getW(){
    return w;
}

int MinesState::getH(){
    return h;
}

//void MinesState::getcellstate(cellstate* state){
//    int cell = state.value;
//    int pos = state-grid;    // 0 = 0, 1 = 1, 2 = 2..etc
    
//    state->x = pos%w;
//    state->y = floor(pos/w);
//}

void MinesState::Easy(){
    int minecount = ceil(w*h/10);
    
    // Choose a random mean between 1 and 6
    std::random_device dev;
    std::default_random_engine e1(dev());
    
//    std::uniform_int_distribution<int> rw(0,w-1);
//    std::uniform_int_distribution<int> rh(0,h-1);
    std::uniform_int_distribution<int> celld(0,w*h-1);
    
    cellstate *cs;
    for(int i = 0; i < minecount; i++){
        int rv = celld(e1);
//        cs.value = grid + rv;
        
        cs = grid + rv;
//        getcellstate(cs);
        
//        setmine(cs.x, cs.y);
        setmine(cs);
        printf("%d : %d / %d %d\n", i, rv, cs->x, cs->y);
    }
    
    print();
}
    
void MinesState::print(){
    for(int i=0; i < h; i++){
        for(int j = 0; j < w; j++){
            cellstate* cell = getcell(j, i);
            if(ismine(cell))
                printf("x");
            else if(cell->value == 0)
                printf("_");
            else
                printf("%d", cell->value);
        }
        printf("\n");
    }
}

std::list<cellstate*> MinesState::getcells(){
    std::list<cellstate*> l;
    
    for(int p = 0; p < w*h; p++)
        l.push_back(grid+p);
//    
//    for(int i = 0; i < h; i++){
//        for(int j = 0; j < w; j++){
//            l.push_back({j, i, getcell(j, i), 0});
//        }
//    }
    
    return l;
}

