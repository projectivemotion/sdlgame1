/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   painter.h
 * Author: eye
 *
 * Created on September 24, 2019, 2:42 AM
 */

#ifndef PAINTER_H
#define PAINTER_H

#include "app/AppClass.h"


class painter {
public:
    painter(AppClass *papp);
    painter(const painter& orig);
    
    void Accept(SDL_Surface *surf);
    
    virtual ~painter();
private:
    AppClass *app;
};

#endif /* PAINTER_H */

