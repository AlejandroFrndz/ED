/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instrucciones.cpp
 * Author: francisco
 * 
 * Created on 24 de diciembre de 2019, 20:24
 */

#include "instrucciones.h"
#include "arbolbinario.h"
#include "acciones.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stack>


using namespace std;

/*instrucciones:: ArbolBinario<string>::postorden_iterador instrucciones::begin() const{
    postorden_iterador i;
    
}*/


istream& operator >>(istream& in, instrucciones &instrucciones){
    stack<ArbolBinario<string>> p1;
    string linea,subcadena;
    int comienzo = 0, fin, ariedad;
    bool accion = true; //me indica si ya he encontrado la accion
    
    getline(in,linea);
    
    while(linea.size() != 0){
        accion = true;
        for(int i = 0; i < linea.size(); i++){
            if(linea[i] == ' '){
                fin = i;
                subcadena = linea.substr(comienzo,fin-comienzo);
            }
            
            if(accion){
                accion = false;
            }
        }
        getline(in,linea);
    }
    
}

