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
    receta rec;
    
    cout << "\nIntroduzca el código de la primera receta a fusionar: ";
    cin >> code;
    cout << "\nIntroduzca el código de la segunda receta que desea fusionar: ";
    cin >> code2;
    
    /*rec = recs[code];
    float hidratos = recs[code].getHidratos() +recs[code2].getHidratos();
    float grasas = recs[code].getGrasas() +recs[code2].getGrasas();
    float fibra = recs[code].getFibra() +recs[code2].getFibra();
    float proteinas = recs[code].getProteinas() +recs[code2].getProteinas();
    float calorias = recs[code].getCalorias() +recs[code2].getCalorias();
    
    receta fusion;
    //seguir
    fusion.setNutrientes(calorias,fibra,proteinas,grasas,hidratos);
    fusion.setNombre("Fusion " + recs[code].getNombre() + " y " + recs[code2].getNombre());
    fusion.setCode("F_"+code+"_"+code2);
    fusion.setInstrucciones(recs[code].getInstrucciones());*/
    
    receta fusion;
    cout << recs[code]<<endl;
    cout << recs[code2]<<endl;
    cout << "\nLa receta fusion es:"<<endl;
    fusion.fusionar(recs[code],recs[code2]);
    
    
    cout << fusion;
    
  /*  if(rec.getNombre() != "Undefined")
       cout << endl << rec;
    else
        cout << endl << BOLD(FRED("No existe ninguna receta con código ")) << code;
    */
    return 0;
}

