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
#include "ingredientes.h"
#include "ingrediente.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

istream& operator >>(istream& in, instrucciones &instrucciones){
    
    string linea, accion = "", ing1 = "", ing2 = "";
    stack<ArbolBinario<string>> p;
    int comienzo = 0, fin = 0, ariedad = 0;
    ingrediente ing;
    bool hay_segundo = false, hay_primero = false;
    
    getline(in,linea);
    
    while(linea.size() != 0){
        
        //Ciclo para extraer la acción
        for(int i = comienzo; i <= linea.size(); i++){
            if(linea[i] == ' ' || i == linea.size()){
                fin = i;
                accion = linea.substr(comienzo,fin-comienzo); //nombre
                ariedad = instrucciones.ariedad(accion); //ariedad
                comienzo = fin;
                comienzo++;
                break;
            }    
        }
        
        //Comienza el proceso de extracción del primer ingrediente
        //Este ciclo extrae el primer elemento del nombre
        for(int i = comienzo; i <= linea.size(); i++){
            if(linea[i] == ' ' || i == linea.size()){
                fin = i;
                ing1 += linea.substr(comienzo,fin-comienzo);
                comienzo = fin;
                comienzo++;
                hay_primero = true; //Para evitar que el segundo ciclo de extracción se ejecute cuando no hay ingrediente
                break;
            }    
        }
            
        ing = instrucciones.ings.get(ing1);
        
        //Este ciclo extrae el reto de elementos del nombre, no se ejecuta si el nombre no es compuesto o no hay ingrediente
        while(ing.getNombre() == "Undefined" && hay_primero){
            ing1 += " "; //Ya que el procesamiento de los nombres se rige por los espacios, se añaden espacios entre las distintas componentes del nombre compuesto
            for(int i = comienzo; i <= linea.size(); i++){
                if(linea[i] == ' ' || i == linea.size()){
                    fin = i;
                    ing1 += linea.substr(comienzo,fin-comienzo);
                    comienzo = fin;
                     break;
                }    
            
            }
            
            ing = instrucciones.ings.get(ing1);
            comienzo++;
        }
        //Fin de la extracción de primer ingrediente
        
        //Comienza la extracción del segundo ingrediente
        for(int i = comienzo; i <= linea.size(); i++){
            if(linea[i] == ' ' || i == linea.size()){
                fin = i;
                ing2 += linea.substr(comienzo,fin-comienzo);
                comienzo = fin;
                comienzo++;
                hay_segundo = true;
                break;
            }    
        }
            
        ing = instrucciones.ings.get(ing2);
        
        while(ing.getNombre() == "Undefined" && hay_segundo){
            ing2 += " ";
            for(int i = comienzo; i <= linea.size(); i++){
                if(linea[i] == ' ' || i == linea.size()){
                    fin = i;
                    ing2 += linea.substr(comienzo,fin-comienzo);
                    comienzo = fin;
                     break;
                }    
            
            }
            
            ing = instrucciones.ings.get(ing2);
        }
        //Fin de la extracción del segundo ingrediente
        
        ArbolBinario<string> arbol(accion);
        
        //Creación del subarbol en función de la ariedad de la acción y el número de ingredientes proporcionados
        if(ariedad == 1){
            if(ing1 == ""){ //Ariedad 1 sin ingrediente
                arbol.Insertar_Hi(arbol.getRaiz(),p.top()); 
                p.pop();
            }
            else{   //Ariedad 1 con ingrediente
                arbol.Insertar_Hi(arbol.getRaiz(),ing1);    
            }            
        }
        
        else{
            if(ing1 == ""){ //Ariedad 2 sin ingredientes
                arbol.Insertar_Hd(arbol.getRaiz(),p.top());
                p.pop();
                arbol.Insertar_Hi(arbol.getRaiz(),p.top());
                p.pop();
            }
            
            else{
                if(ing2 == ""){ //Ariedad 2 con 1 ingrediente
                    arbol.Insertar_Hi(arbol.getRaiz(),ing1);
                    arbol.Insertar_Hd(arbol.getRaiz(),p.top());
                    p.pop();
                }
                
                else{   //Ariedad 2 con 2 ingredientes
                    arbol.Insertar_Hi(arbol.getRaiz(),ing1);
                    arbol.Insertar_Hd(arbol.getRaiz(),ing2);
                }
            }
        }
        //Fin de la creación del subarbol
        
        p.push(arbol); //Introducción el subarbol en la pila
        
        getline(in,linea); 
        
        //Reseteo de las variables para subsecuentes iteraciones
        ing1 = "";
        ing2 = "";
        accion = "";
        hay_segundo = false;
        hay_primero = false;
        ariedad = 0;
        comienzo = fin = 0;
    }
    
    instrucciones.datos = p.top(); //Cuando se acaban las instrucciones, se extrae de la pila el árbol completo y se coloca en datos
}

ostream& operator<< (ostream& out, const instrucciones &instrucciones){
    ArbolBinario<string>::postorden_iterador it = instrucciones.datos.beginpostorden();
    string ing1 = "", ing2 = "";
    stack<string> p;
    
    for(it; it != instrucciones.datos.endpostorden(); ++it){
        if(it.hi().nulo() && ing1 == ""){
            ing1 = *it;
            if((*it.padre()) == "Add"){
                p.push(ing1);
                ing1 = "";
            }
                
        }
        else{
            if(it.hi().nulo())
                ing2 = *it;
            else{
                out << *it;
                
                if(ing1 != ""){
                    out << " " << ing1;
                    ing1 = "";
                }
                
                if(ing2 != ""){
                    out << " " << ing2;
                    ing2 = "";
                }
                
                break;
            }
        }
    }
    
    ++it;
    
    for(it; it != instrucciones.datos.endpostorden(); ++it){
        if(it.hi().nulo() && ing1 == ""){
            ing1 = *it;
            if((*it.padre()) == "Add"){
                p.push(ing1);
                ing1 = "";
            }
        }
        else{
            if(it.hi().nulo())
                ing2 = *it;
            else{
                out << "\n" << *it;
                
                if(*it == "Add" && ! p.empty()){
                    out << " " << p.top();
                    p.pop();
                }
                else{
                    if(ing1 != ""){
                        out << " " << ing1;
                        ing1 = "";
                    }

                    if(ing2 != ""){
                        out << " " << ing2;
                        ing2 = "";
                    }
                }
            }
        }
    }
}