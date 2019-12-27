/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test_acciones.cpp
 * Author: francisco
 *
 * Created on 13 de diciembre de 2019, 12:31
 */

#include <cstdlib>
#include <iostream>
#include "acciones.h"
#include "instrucciones.h"
#include "ingredientes.h"
#include <fstream>
using namespace std;

/*
 * 
 */
int main() {
    acciones acc;
    ifstream fa("datos/Acciones.txt");
    ingredientes ings;
    ifstream fing("datos/ingredientes.txt");
    fa >> acc;
    fing >> ings;
    instrucciones conjunto(acc,ings);
    ifstream fi("datos/instrucciones/R1m.txt");
    
    
    fi >> conjunto;
    
    cout << "hola";
    
    
    return 0;
}

