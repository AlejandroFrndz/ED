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

istream& operator >>(istream& in, instrucciones &instrucciones){
    
    string linea,subcadena = "", accion = "", ing1 = "", ing2 = "";
    stack<ArbolBinario<string>> p;
    int comienzo = 0, fin = 0, ariedad = 0;
    //bool busca = true; //me indica si ya he encontrado la accion
    
    getline(in,linea);
    
    while(linea.size() != 0){
        
        for(int i = comienzo; i <= linea.size(); i++){
            if(linea[i] == ' ' || i == linea.size()){
                fin = i;
                accion = linea.substr(comienzo,fin-comienzo); //nombre de la accion
                ariedad = instrucciones.ariedad(accion); //ariedad de la accion
                comienzo = fin;
                comienzo++;
                break;
            }    
        }
        
        for(int i = comienzo; i <= linea.size(); i++){
            if(linea[i] == ' ' || i == linea.size()){
                fin = i;
                ing1 = linea.substr(comienzo,fin-comienzo); //nombre de la accion
                comienzo = fin;
                comienzo++;
                break;
            }    
        }
        
        for(int i = comienzo; i <= linea.size(); i++){
            if(linea[i] == ' ' || i == linea.size()){
                fin = i;
                ing2 = linea.substr(comienzo,fin-comienzo); //nombre de la accion
                comienzo = fin;
                comienzo++;
                break;
            }    
        }
        
        ArbolBinario<string> arbol(accion);
        
        if(ariedad == 1){
            if(ing1 == ""){
                arbol.Insertar_Hi(arbol.getRaiz(),p.top());
                p.pop();
            }
            else{
                arbol.Insertar_Hi(arbol.getRaiz(),ing1);
            }            
        }
        
        else{
            if(ing1 == ""){
                arbol.Insertar_Hd(arbol.getRaiz(),p.top());
                p.pop();
                arbol.Insertar_Hi(arbol.getRaiz(),p.top());
                p.pop();
            }
            
            else{
                if(ing2 == ""){
                    arbol.Insertar_Hi(arbol.getRaiz(),ing1);
                    arbol.Insertar_Hd(arbol.getRaiz(),p.top());
                    p.pop();
                }
                
                else{
                    arbol.Insertar_Hi(arbol.getRaiz(),ing1);
                    arbol.Insertar_Hd(arbol.getRaiz(),ing2);
                }
            }
        }
        
        p.push(arbol);
        
        getline(in,linea);
        //restablezco las variables para las siguientes iteraciones
        subcadena = "";
        ing1 = "";
        ing2 = "";
        accion = "";
        //busca = true;
        ariedad = 0;
        comienzo = fin = 0;
    }
    
    instrucciones.datos = p.top();
}

