/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: eye
 *
 * Created on September 17, 2019, 3:20 AM
 */

#include <cstdlib>
#include <string>
#include <stdio.h>

#include "app/AppClass.h"

//using namespace std;


int main( int argc, char* args[] )
{
    AppClass app;
    return app.run();
#ifdef _JS

                        emscripten_set_main_loop_arg(loop_handler, NULL, -1, 1);
#else
			//While application is running
//			while( !quit )
//			{
//		 	 loop_handler(NULL);	
//			}
#endif
}

