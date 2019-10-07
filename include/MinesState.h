/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinesState.h
 * Author: eye
 *
 * Created on October 3, 2019, 11:54 PM
 */

#ifndef MINESSTATE_H
#define MINESSTATE_H

#include <list>
#include <iostream>

struct cellstate {
    int x;
    int y;
//    int* value;    
    int value = 0;
    int uncovered;
};

class MinesState {
public:
    MinesState();
    MinesState(const MinesState& orig);
//    void getcellstate(cellstate& state);
    
//    cellstate* setmine(int x, int y);
    cellstate* setmine(cellstate *cell);
//    int* inccell(int x, int y);
    
    inline bool ismine(cellstate* c){
        return c->value == MINE;
    }
    
    inline cellstate* getcell(int x, int y){        
        return grid+y*w+x;
    }
    
    std::list<cellstate*> getcells();
    
public:
    void init(int x, int y);    
    void Easy();    
    
    int getW();
    int getH();
    
    void print();
    
    virtual ~MinesState();
    
    const int MINE = -1;
private:
    int w;
    int h;
    
//    int *grid = nullptr;
    cellstate *grid = nullptr;
};

#endif /* MINESSTATE_H */

