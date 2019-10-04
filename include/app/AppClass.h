/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AppClass.h
 * Author: eye
 *
 * Created on September 17, 2019, 7:31 PM
 */

#ifndef APPCLASS_H
#define APPCLASS_H
#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entities/entity.h"
#include "SceneManager.h"
#include "AssetManager.h"

class BaseScene;
//class AssetManager;
//class SceneManager;

class AppClass {
public:
    AppClass();
    AppClass(const AppClass& orig);
    
    AssetManager& getAssetManager();
    SceneManager* getSceneManager();
    SDL_Surface* loadSurfacex(const char* path);
    SDL_Texture* loadSurface(const char* path);
    entity<SDL_Texture>* createEntity(const char* path);
    
//    entity<SDL_Surface>* reds();
    entity<SDL_Texture>* red();
    entity<SDL_Texture> blue();
    entity<SDL_Texture>* yellow();
    entity<SDL_Texture>* green();
    
    bool draw(entity<SDL_Texture>& e);
    
    bool run();
    
    virtual ~AppClass();
    
    SDL_Rect getRect();
    
    bool quit;

    //The window we'll be rendering to
    SDL_Window* win = NULL;

    //The window renderer
    SDL_Renderer* ren = NULL;
//    std::list<BaseScene*> scenes;
    
protected:
    bool init();
    bool initWindow();
    bool loadAssets();
    bool loadScenes();
    bool apploop();
    
private:
    SceneManager scenes;
    AssetManager assets;
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;


};

#endif /* APPCLASS_H */

