/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menuoptions.cpp
 * Author: eye
 * 
 * Created on September 24, 2019, 1:49 AM
 */

#include "menuoptions.h"
#include "FontSurface.h"

typedef enum {
    OPT1,
    OPT2,
    OPT3,
    TOPTS
} opts;

void menuoptions::addOption(const char *pt, const SDL_Color& col, int x, int y){
    
//    int citems = opts.size();
    int iheight = 30;
    int width = 300; 
    
//    int y = (citems+1)*iheight;
        
    opts.push_front({pt, letters.render(pt, col), {x,y,width,iheight}});
}
    
bool menuoptions::init(){
    
    
    textx = nullptr;
    
    letters.init("assets/unispace.ttf", 33);
    
//    SDL_Color black = {0,0,0,0}
    addOption("opcion 1", {0,0,0,0}, 100,100);
    addOption("opcion 2", {255, 255, 255, 255}, 100, 200);

//    
    rect.h = 200;
    rect.w = 200;
    rect.x = 0;
    rect.y = 0;
    
    return true;
}

SDL_Texture *menuoptions::getTexture(){
    return buildTexture();
}

SDL_Texture *menuoptions::buildTexture(){
    
    // render opts
    
    if(textx != nullptr)
        SDL_DestroyTexture(textx);
    
    SDL_Texture *mTexture = nullptr;
    SDL_Surface *surface = nullptr;
    
    surface = SDL_CreateRGBSurface(0, 600, 600, 32, 0, 0, 0, 0);
    
    // fill
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 99));
    
    // draw
    for(auto& opt : opts){
        printf("%d %d %d %d\n", opt.rec.x, opt.rec.y, opt.rec.w, opt.rec.h);
        SDL_BlitSurface(opt.ren, nullptr, surface, &opt.rec);
        printf("%d %d %d %d\n", opt.rec.x, opt.rec.y, opt.rec.w, opt.rec.h);
    }
    //
    
    textx = SDL_CreateTextureFromSurface( app->ren, surface );
    
    
    SDL_FreeSurface(surface);
    return textx;
}



SDL_Rect *menuoptions::getRect(){    
    return &rect;
}




menuoptions::~menuoptions() {
}

