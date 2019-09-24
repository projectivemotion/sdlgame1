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
    
    int iheight = 50;
    int width = 200; 
        
    opts.push_front({pt, letters.render(pt, col), {x,y,width,iheight}});
}
    
bool menuoptions::init(){
    textx = nullptr;
    
    letters.init("assets/unispace.ttf", 33);
    
    addOption("opcion 1", {0,0,0,0}, 100,100);
    addOption("opcion 2", {255, 255, 255, 255}, 100, 200);

    rect.w = 640;
    rect.h = 480;
    rect.x = 0;
    rect.y = 0;
    
    update = true;
    
    return true;
}

SDL_Texture *menuoptions::getTexture(){
    if(update)
        return buildTexture();
    return textx;
}


bool menuoptions::handleMouseEv(SDL_Event *e){
    switch(e->type){
        case SDL_MOUSEMOTION:
            int x = e->motion.x;
            int y = e->motion.y;
            
            printf("Mouse %d %d\n", x, y);
            for(auto& opt : opts){
                bool hover = (x > opt.rec.x && x < opt.rec.x+opt.rec.w
                        && y > opt.rec.y && y < opt.rec.y + opt.rec.h
                        );
                int newstate = hover ? 1 : 0;
                if(hover){
                    printf("Hit: %s %d %d %d %d\n", opt.t, opt.rec.x, opt.rec.y,
                            opt.rec.w, opt.rec.h);
                }
                
                if(newstate == opt.state) continue;
                
                update = true;
                opt.state = hover ? 1 : 0;
            }
            
            break;
    }
    return true;
}

SDL_Texture *menuoptions::buildTexture(){
    
    // render opts
    
    if(textx != nullptr)
        SDL_DestroyTexture(textx);
    
    SDL_Texture *mTexture = nullptr;
    SDL_Surface *surface = nullptr;
    
    surface = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);
    
    // fill
    auto blue = SDL_MapRGB(surface->format, 0, 0, 99);
    auto black = SDL_MapRGB(surface->format, 0, 0, 0);
    auto red = SDL_MapRGB(surface->format, 255, 0, 0);
    
    SDL_FillRect(surface, NULL, blue);//
    
    // draw
    for(auto& opt : opts){
        printf("%d %d %d %d\n", opt.rec.x, opt.rec.y, opt.rec.w, opt.rec.h);
        SDL_FillRect(surface, &opt.rec, opt.state == 1 ? red : black);//
        SDL_BlitSurface(opt.ren, nullptr, surface, &opt.rec);
        printf("%d %d %d %d\n", opt.rec.x, opt.rec.y, opt.rec.w, opt.rec.h);
    }
    //
    
    textx = SDL_CreateTextureFromSurface( app->ren, surface );
    
    
    SDL_FreeSurface(surface);
    
    update = false;
    return textx;
}



SDL_Rect *menuoptions::getRect(){    
    return &rect;
}




menuoptions::~menuoptions() {
    // @todo clear opt surfaces
}

