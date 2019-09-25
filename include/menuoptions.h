/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menuoptions.h
 * Author: eye
 *
 * Created on September 24, 2019, 1:49 AM
 */

#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H

#include "drawable.h"
#include "FontSurface.h"
#include <SDL2/SDL_mixer.h>
#include <algorithm>
//#include <functional>

struct opt {
    const char* t;
    SDL_Surface* ren;
    SDL_Rect rec;
    int state;
    sceneid sceneidv;
};

class menuoptions : public drawable {
public:
    using drawable::drawable;
    
    virtual bool init();
    virtual SDL_Rect *getRect();
    virtual SDL_Texture *getTexture();
    
public:
    
//    virtual void setOptionHandler(std::function<void(void)> h);
    virtual bool handleMouseEv(SDL_Event *e);
    virtual ~menuoptions();
    
    virtual opt* getSelection();
    
    
protected:
    
    virtual void clean();
    bool setChanged(bool nv);
    
    virtual SDL_Texture *buildTexture();    
    virtual void initOptions();
//    virtual void addOption(sceneid scenev, const char *pt, const SDL_Color& color, int x, int y);
    
    
private:
//    std::function<void(void)> handler;

    std::shared_ptr<ChunkSound> sound;
    
    opt* selectedOpt;
    bool changed;
    std::list<opt> opts;
    
    SDL_Rect rect;
    SDL_Texture *textx;
};

#endif /* MENUOPTIONS_H */

