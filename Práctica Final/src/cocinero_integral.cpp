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
#include "recetas.h"
#include "color.h"
#include <fstream>
using namespace std;

acciones instrucciones::acc;
ingredientes instrucciones::ings;
string receta::ruta_instrucciones;

int main(int argc, char ** argv) {
    acciones acc;
    ifstream fa(argv[1]);
    ingredientes ings;
    ifstream fing(argv[3]);
    fa >> acc;
    fing >> ings;
    
    receta::ruta_instrucciones = argv[4];
    
    instrucciones::acc = acc;
    instrucciones::ings = ings;
    
    ifstream f(argv[2]);
    recetas recs;
    
    cout << BOLD("RECETAS:") << endl;
    
    f >> recs;
    cout << recs;
    
    string code;
    receta rec;
    
    cout << "\nIntroduzca el código de la receta que desea inspeccionar: ";
    cin >> code;
    
    rec = recs[code];
    
    if(rec.getNombre() != "Undefined")
        cout << endl << rec;
    else
        cout << endl << BOLD(FRED("No existe ninguna receta con código ")) << code;
    
    return 0;
}

