/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menuscene.cpp
 * Author: eye
 * 
 * Created on September 23, 2019, 1:49 AM
 */

#include "scene/menuscene.h"

menuscene::~menuscene() {
    TTF_CloseFont(font);
    TTF_Quit();
}


bool menuscene::draw(){
    SDL_Texture *mTexture = nullptr;
    //Render text surface
    SDL_Color textColor = {0, 255, 0,128};
    
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, "amadin", textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        return false;
    }

    
//    SDL_BlitSurface()
    
    SDL_Rect baz = {0,0,200,60};
    SDL_Surface *surface = nullptr;
    
    int width = 300; int height = 300;
    surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

    if (surface == nullptr) {
        SDL_Log("SDL_CreateRGBSurface() failed: %s", SDL_GetError());
        exit(1);
    }

    /* or using the default masks for the depth: */
//    surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 99));
    
    SDL_Rect r = {0,0,300,100};
    SDL_BlitSurface(textSurface, NULL, surface, &r);

    mTexture = SDL_CreateTextureFromSurface( app->ren, surface );

    if( mTexture == nullptr )
    {
        printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

		//Get rid of old surface
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(surface);
    
    SDL_RenderClear(app->ren );
    SDL_RenderCopy(app->ren, sfbg, nullptr, nullptr);
    SDL_RenderCopy(app->ren, mTexture, nullptr,&baz);
    
    SDL_RenderPresent( app->ren );
    
    SDL_DestroyTexture(mTexture);
    return true;
}

bool menuscene::init() {
//    tapp = &app;
    if(TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
    }
    
//    font=TTF_OpenFont("assets/CircleOfDust.ttf", 16);
    font=TTF_OpenFont("assets/unispace.ttf", 100);
    
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        // handle error
    }

    sfbg = app->loadSurface("dots.png");
    return true;
}