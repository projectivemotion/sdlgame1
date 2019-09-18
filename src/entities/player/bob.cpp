/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bob.cpp
 * Author: eye
 * 
 * Created on September 17, 2019, 10:28 PM
 */

#include "bob.h"

bob::bob(AppClass& app) {
    e = app.blue();
}

bob::bob(const bob& orig) {
}

bob::~bob() {
    e->free();
    delete e;
}

entity* bob::getentity(){
    return e;
}

