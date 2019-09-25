/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AppClass.cpp
 * Author: eye
 * 
 * Created on September 17, 2019, 7:31 PM
 */

#include "app/AppClass.h"
#include "../scene/proofofconcept/scene.h"
#include "scene/menuscene.h"

#include <SDL2/SDL_mixer.h>


AppClass::AppClass() {
    quit = false;
}

AppClass::AppClass(const AppClass& orig) {
}

AppClass::~AppClass() {
    
	//Destroy window	
	SDL_DestroyRenderer( ren );
	SDL_DestroyWindow( win );
	win = NULL;
	ren = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

bool AppClass::init() {

    initWindow();
    loadScenes();
    return true;
}

bool AppClass::initWindow() {    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
            printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
            return false;
    }
    
            //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
            printf( "Warning: Linear texture filtering not enabled!" );
            return false;
    }

    //Create window
    win = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( win == NULL )
    {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            return false;
    }

    //Create vsynced renderer for window
    ren = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			//try software render if hardware fails
    if( ren == NULL )
    {
        SDL_Log( "Accelerated renderer could not be created! SDL Error: %s\nSwitching to software renderer", SDL_GetError() );
        ren = SDL_CreateRenderer( win, -1, SDL_RENDERER_SOFTWARE);
    }
    
    if( ren == NULL )
    {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            return false;
    }
    
        //Initialize SDL_mixer
   if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
   {
       printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
       return false;
   }
    // extra ?
    
    //Initialize renderer color
    SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            return false;
    }

    return true;
}

bool AppClass::loadAssets() {
    return true;
}

bool AppClass::loadScenes() {
    
    scenes.init(this);
//    scenes.push_back(new menuscene(this));
//    scenes.back()->init();
//    scenes.push_back(new scene(this));
    return true;
}

SDL_Rect AppClass::getRect(){
    SDL_Rect r = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    return r;
}

SceneManager* AppClass::getSceneManager(){    
    return &scenes;
}

bool AppClass::apploop(){
//    int quit = false;
    
    while ( false == quit )
    {        
        scenes.loop();
//        scenes.front()->loop();
    }
    
    return true;    
//    return true;
}

bool AppClass::draw(entity& e){
    e.draw(ren);    
    return true;
//    SDL_RenderCopy(ren, x, &s, &t);
}

entity* AppClass::createEntity(const char* path){
    return new entity(loadSurface(path));
}

entity* AppClass::red(){
    return createEntity("dots.png")->from(0,0,100,100);
}

entity* AppClass::blue(){
    return createEntity("dots.png")->from(100,100,100,100);
}

entity* AppClass::yellow(){
    return createEntity("dots.png")->from(0,100,100,100);
}
entity* AppClass::green(){
    return createEntity("dots.png")->from(100,0,100,100);
}

SDL_Texture* AppClass::loadSurface(const char* path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL )
    {
            printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
            return NULL;
    }

    //Color key image
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface( ren, loadedSurface );
    if( newTexture == NULL )
    {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
            return NULL;
    }


    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    return newTexture;
}

bool AppClass::run() {
    if(!init())
    {
        
    }else{
        if(!loadAssets())
        {
            
        }else{
            return apploop();
        }
    }
    return false;
}

