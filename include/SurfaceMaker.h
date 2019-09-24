/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SurfaceMaker.h
 * Author: eye
 *
 * Created on September 24, 2019, 2:15 AM
 */

#ifndef SURFACEMAKER_H
#define SURFACEMAKER_H

class SDL_Surface;

class SurfaceMaker {
public:
//    SurfaceMaker();
//    SurfaceMaker(const SurfaceMaker& orig);
    
    virtual SDL_Surface* getSurface() = 0;
//    virtual ~SurfaceMaker();
};

#endif /* SURFACEMAKER_H */

