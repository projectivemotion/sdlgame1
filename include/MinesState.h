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

class MinesState {
public:
    MinesState();
    MinesState(const MinesState& orig);
    
    inline int* getcell(int x, int y);
    inline bool ismine(int c){
        return c == MINE;
    }
    
    void init(int x, int y);    
    void Easy();
    
    
    int* inccell(int x, int y);    
    int* setmine(int x, int y);
    
    void print();
    
    virtual ~MinesState();
private:
    const int MINE = -1;
    int w;
    int h;
    
    int *grid = nullptr;
};

#endif /* MINESSTATE_H */

