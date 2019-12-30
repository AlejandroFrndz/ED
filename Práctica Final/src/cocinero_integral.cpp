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
#include <arbolbinario.h>
using namespace std;

acciones instrucciones::acc;
ingredientes instrucciones::ings;
string receta::ruta_instrucciones;

int main(int argc, char ** argv) {
    
    if(argc < 5){
	cout << "Ejecucción: cocinero_integral {archivo con las acciones} {archivo con las recetas} {archivo con los ingredientes} {ruta del directorio con las instrucciones de las recetas}\n";
	exit(-1);
    }
    
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
    
    string code,code2;
    
    cout << "\nIntroduzca el código de la receta que desea inspeccionar: ";
    cin >> code;
    
    if(recs[code].getNombre() == "Undefined")
        cout << BOLD(FRED("\nNo existe ninguna receta con código ")) << code;  
    else
        cout << recs[code];
    
    cout << "\nIntroduzca el código de la primera receta a fusionar: ";
    cin >> code;
    if(recs[code].getNombre() == "Undefined"){
        do{
            cout << BOLD(FRED("\nNo existe ninguna receta con ese código, por favor introduzca un código válido: "));
            cin >> code;
        }while(recs[code].getNombre() == "Undefined");
    }
    
    cout << "\nIntroduzca el código de la segunda receta a fusionar: ";
    cin >> code2;
    if(recs[code2].getNombre() == "Undefined"){
        do{
            cout << BOLD(FRED("\nNo existe ninguna receta con ese código, por favor introduzca un código válido: "));
            cin >> code2;
        }while(recs[code2].getNombre() == "Undefined");
    }

    receta fusion(recs[code],recs[code2]);

    cout << "\nLa receta fusion es:"<< endl << fusion;
  
    return 0;
}

