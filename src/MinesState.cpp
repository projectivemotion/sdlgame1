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
#include <algorithm>
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
    
    std::random_device dev;
    std::default_random_engine e1(dev());
    
    std::uniform_int_distribution<int> celld(0,w*h-1);
    
    cellstate *cs;
    
    for(int i = 0; i < h; i++)
        for(int z = 0; z < w ; z++)
        {
            cs = grid + i*w+z;
            cs->x = z;
            cs->y = i;            
            cs->value = 0;
            cs->covered = 1;
//            cs->covered = 0;
        }
    
    auto cells = getcells();
    std::vector<cellstate*> v(cells.begin(), cells.end());
    std::random_shuffle(v.begin(), v.end());
    
    for(int i = 0; i < minecount; i++){
        cs = v[i];
        setmine(cs);
        printf("mine: %d : position: %d | x: %d y: %d\n", i, cs->x, cs->y);
    }
    
    print();
}
    
void MinesState::print(){
    
    std::list<cellstate*> mines;
//    int mines = 0;
    for(int i=0; i < h; i++){
        for(int j = 0; j < w; j++){
            cellstate* cell = getcell(j, i);
            if(ismine(cell))
            {
                mines.push_back(cell);
                printf("x");
            }
            else if(cell->value == 0)
                printf("_");
            else
                printf("%d", cell->value);
        }
        printf("\n");
    }
    
    printf("\n\nMines: %d\n", mines.size());
    for(auto *m : mines)
        printf("%d, %d\n", m->x, m->y);
    
    printf("\n\n");
    
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

cellstate* MinesState::uncover(cellstate* cell){
//    cellstate* cell = getcell(x, y);
    if(iscovered(cell))
        cell->covered = 0;
    else{
        return cell;    // nothing to do..?
    }

    if(issafe(cell)){
        // uncover adjacent cells and numbers..
//        std::list<cellstate*> expand;
        
//        do{
            auto neighbors = getsurrounding(cell);
//            expand.insert(expand.end(), neighbors.begin(), neighbors.end());
            for(auto *n : neighbors){
                if(n == nullptr)    continue;   // DNE
                if(!ismine(n))
                    uncover(n);
            }
//        }while(!expand.empty());
    }
    
    return cell;
//        return; // ok
}
