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
#include <array>
#include "MinesState.h" 

MinesState::MinesState() {
//    init(8,8);
}

MinesState::MinesState(const MinesState& orig) {
}

MinesState::~MinesState() {
    if(grid != nullptr)
        delete [] grid;
}
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
            cell->covered = 1;
        }
    
}
    
cellstate* MinesState::setmine(cellstate *pcell){
    pcell->value = MINE;
        
    for(auto *cell : getsurrounding(pcell)){
        if(cell == nullptr)
            continue;   // DOES NOT EXIST..
        if(ismine(cell)) continue;
        // 
        cell->value++;
    }
    
//    int baz[18] = {
//            -1, -1,
//            0, -1,
//            1, -1,
//            -1, 0,
////            0, 0,
//            1, 0,
//            -1, 1,
//            0, 1,
//            1, 1,
//            0, 0    // end marker
//    };
//    
//    for(int *v = baz; *v != 0 || *(v+1) != 0;)
//    {
//        int cx = pcell->x+*(v++);
//        int cy = pcell->y+*(v++);
//        if(cx < 0 || cx >= w || cy < 0 || cy >= h) continue;
//        cellstate *cell = getcell(cx, cy);
//        if(ismine(cell)) continue;
//        cell->value++;
//    }
        
    return pcell;
}

int MinesState::getW(){
    return w;
}

int MinesState::getH(){
    return h;
}

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
    
    return l;
}

std::array<cellstate*, 8> MinesState::getsurrounding(cellstate* pcell){
    std::array<cellstate*, 8> l;

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
    
    int p = 0;
    for(int *v = baz; *v != 0 || *(v+1) != 0;)
    {
        int cx = pcell->x+*(v++);
        int cy = pcell->y+*(v++);
        if(cx < 0 || cx >= w || cy < 0 || cy >= h){
            l[p++] = nullptr;
            continue;
        }
        cellstate *cell = getcell(cx, cy);
        l[p++] = cell;
    }
    
    return l;
}

cellstate* MinesState::uncover(int x, int y){
    cellstate* cell = getcell(x, y);
    if(iscovered(cell))
        cell->covered = 0;

    return cell;
//        return; // ok
}
