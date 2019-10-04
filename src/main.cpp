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
#include "MinesState.h"

//using namespace std;


int main( int argc, char* args[] )
{
//    MinesState s;
//    s.print();
//    s.setmine(7,6);
//    printf("\n\n");
//    s.print();
//    s.setmine(2,1);
//    printf("\n\n");
//    s.print();
//    s.setmine(3,3);
//    printf("\n\n");
//    s.print();
    
//    MinesState s;
//    s.print();
//    s.setmine(1,1);
//    printf("\n\n");
//    s.print();
//    s.setmine(2,1);
//    printf("\n\n");
//    s.print();
//    s.setmine(3,3);
//    printf("\n\n");
//    s.print();
    
    MinesState easy;
    printf("\n\n");
    easy.Easy();
    return 0;
//    AppClass app;
//    return app.run();
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

