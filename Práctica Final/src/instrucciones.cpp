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
    
    string linea,subcadena = '';
    stack<ArbolBinario<string>> p;
    int comienzo = 0, fin = 0, ariedad = 0;
    bool busca_accion = true; //me indica si ya he encontrado la accion
    
    getline(in,linea);
    
    while(linea.size() != 0){
        
        for(int i = 0; i < linea.size() && busca_accion; i++){
            //caso en el que la accion y los ingredientes esten en la misma linea, ejemplo: cortar lechuga
            if(linea[i] == ' '){
                fin = i;
                if(busca_accion){
                    subcadena = linea.substr(comienzo,fin-comienzo); //nombre de la accion
                    ariedad = instrucciones.ariedad(subcadena); //ariedad de la accion
                    //ArbolBinario<string> arbol(subcadena); //creamos el arbol con el nombre de la accion como etiqueta
                    comienzo = fin;
                    comienzo++;
                    busca_accion = false;
                }
                
            }
            
        }
        
        //casos en el que aparece una accion y un ingrediente en al misma linea
        if(subcadena.size() > 1){
            ArbolBinario<string> arbol(subcadena);//creamos el arbol con la accion como raiz
            if(ariedad == 1){ //caso en el que la accion sea unaria y el ingrediente este en la misma linea
                subcadena = linea.substr(comienzo,subcadena.size() - comienzo);
                //insertar hijo a la izquierda
                arbol.Insertar_Hi(arbol.getRaiz(),subcadena);
                //meter en la pila
                p.push(arbol);
            }
        
            if(ariedad == 2){ //caso en el que la accion sea binaria y aparezca un elemento en la misma linea linea
                subcadena = linea.substr(comienzo,subcadena.size() - comienzo);
                //insertar como hijo a la derecha
                arbol.Insertar_Hd(arbol.getRaiz(),subcadena);
                //y coger elemeto de la pila e insertarlo como hijo a la izquierda
                arbol.Insertar_Hi(arbol.getRaiz(),p.top());
                p.pop();
                //finalmente meterlos en la pila
                p.push(arbol);
            }
            
        }else{ //en este caso aparece solo la accion en la linea
            subcadena = linea.substr(comienzo, linea.size() - comienzo);
            ariedad = instrucciones.ariedad(subcadena);
            ArbolBinario<string> arbol(subcadena);//creamos el arbol con la accion como raiz
            
            if(ariedad == 1){
             //meter elemento que haya en la pila como hijo a la izquierda
                arbol.Insertar_Hi(arbol.getRaiz(),p.top());
             //meterlo en la pila
                p.pop();
                p.push(arbol);
            }else{ //si la ariedad == 2
                //insertar primero hijo a la derecha y luego hijo a la izquierda
                arbol.Insertar_Hd(arbol.getRaiz(),p.top());
                p.pop();
                arbol.Insertar_Hd(arbol.getRaiz(), p.top());
                p.pop();
                //meterlo en la pila
                p.push(arbol);
            }
            
        }
        
        
        
        
        getline(in,linea);
        //restablezco las variables para las siguientes iteraciones
        subcadena = '';
        busca_accion = true;
        ariedad = 0;
        comienzo = fin = 0;
    }
    
}

