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

//typedef enum {
//    OPT1,
//    OPT2,
//    OPT3,
//    TOPTS
//} opts;

//void menuoptions::addOption(sceneid scenev, const char *pt, const SDL_Color& col, int x, int y){    
void menuoptions::initOptions(){
    
    auto letters = app->getAssetManager().getFont("assets/unispace.ttf", 33);
    auto add = [this, letters](sceneid scenev, const char *pt, const SDL_Color& col, int x, int y){    
        int iheight = 50;
        int width = 200; 

        opt mopt = {pt, letters->render(pt, col), {x,y,width,iheight}, 0, scenev};
        opts.push_front(mopt);
    };
    
    add(SCENE_BACKGROUND, "4 Balls", {0,0,255,128}, 100,100);
    add(SCENE_5BALLS, "5 Balls", {255, 255, 255, 255}, 100, 200);
    add(SCENE_BACKGROUND, "Scene 3", {255, 0, 255, 255}, 100, 300);
    add(SCENE_MINES, "Mines", {255, 0, 255, 255}, 100, 400);
}
    
bool menuoptions::init(){
    selectedOpt = nullptr;
    textx = nullptr;
    
    rect.w = 640;
    rect.h = 480;
    rect.x = 0;
    rect.y = 0;
    
    changed = true;
    initOptions();
    
    sound = app->getAssetManager().getSound("assets/guncock.wav");
        
    
    return true;
}

SDL_Texture *menuoptions::getTexture(){
    if(textx == nullptr)
        return buildTexture();
    return textx;
}

opt *menuoptions::getSelection(){
    return selectedOpt;
}
//
//void menuoptions::setOptionHandler(std::function<void(void)> h){
//    handler = h;
//}

bool menuoptions::setChanged(bool nv){
    bool ov = changed;
    changed = nv;
    
    clean();
//    handler();
    
    if(selectedOpt != nullptr)
    {
        sound->play();
//        Mix_PlayChannel( -1, s1, 0 );
    }
    
    return changed;
}


bool menuoptions::handleMouseEv(SDL_Event *e){
    auto* prevSelection = selectedOpt;
    selectedOpt = nullptr;
    
    switch(e->type){
        case SDL_MOUSEMOTION:
            int x = e->motion.x;
            int y = e->motion.y;
            
//            printf("Mouse %d %d\n", x, y);
            for(auto& opt : opts){
                bool hover = (x > opt.rec.x && x < opt.rec.x+opt.rec.w
                        && y > opt.rec.y && y < opt.rec.y + opt.rec.h
                        );
                int newstate = hover ? 1 : 0;
                
                if(hover){
//                    printf("Hit: %s %d %d %d %d\n", opt.t, opt.rec.x, opt.rec.y,
//                            opt.rec.w, opt.rec.h);
                    
                    selectedOpt = &opt;
                }
                
                opt.state = hover ? 1 : 0;
            }
            
            break;
    }
    if(prevSelection != selectedOpt)
    {
        setChanged(true);
    }
    return true;
}

void menuoptions::clean(){
    
    if(textx == nullptr)
        return;
    
    SDL_DestroyTexture(textx);
    textx = nullptr;
}

SDL_Texture *menuoptions::buildTexture(){
    
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
//        printf("%d %d %d %d\n", opt.rec.x, opt.rec.y, opt.rec.w, opt.rec.h);
        SDL_FillRect(surface, &opt.rec, opt.state == 1 ? red : black);//
        SDL_BlitSurface(opt.ren, nullptr, surface, &opt.rec);
//        printf("%d %d %d %d\n", opt.rec.x, opt.rec.y, opt.rec.w, opt.rec.h);
    }
    //
    
    textx = SDL_CreateTextureFromSurface( app->ren, surface );
    
    
    SDL_FreeSurface(surface);
    
//    setChanged(false);
    return textx;
}



SDL_Rect *menuoptions::getRect(){    
    return &rect;
}




menuoptions::~menuoptions() {
    clean();
    // @todo clear opt surfaces
}

