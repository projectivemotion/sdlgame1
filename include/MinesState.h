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
#include <array>

struct cellstate {
    int x;
    int y;
//    int* value;    
    int value;
    int covered;
};

class MinesState {
public:
    MinesState();
    MinesState(const MinesState& orig);
    cellstate* setmine(cellstate *cell);
    
    inline bool ismine(cellstate* c){
        return c->value == MINE;
    }
    
    inline bool issafe(cellstate* c){
        return c->value == 0;
    }
    inline bool iscovered(cellstate* c){
        return c->covered == 1;
    }
    
    inline cellstate* getcell(int x, int y){        
        return grid+y*w+x;
    }
    
    inline int getstate(cellstate* c){
        if(iscovered(c))        
                return COVERED;        
        return c->value;
    }
    
    cellstate* uncover(cellstate *cell);
    
    std::list<cellstate*> getcells();
    std::array<cellstate*, 8> getsurrounding(cellstate* center);
    
public:
    void init(int x, int y);    
    void Easy();    
    
    int getW();
    int getH();
    
    void print();
    
    virtual ~MinesState();
    
    const int MINE = -1;
    const int COVERED = -2;
private:
    int w;
    int h;
    
//    int *grid = nullptr;
    cellstate *grid = nullptr;
};

#endif /* MINESSTATE_H */

