/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instrucciones.h
 * Author: francisco
 *
 * Created on 20 de diciembre de 2019, 12:19
 */

#include <iostream>
#include <string>
#include "arbolbinario.h"
#include "acciones.h"
#include "ingredientes.h"

using namespace std;

#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H
class instrucciones{
private:
    ArbolBinario<string> datos;
    
    
public:
    //instrucciones(acciones actions, ingredientes ing){acc = actions; ings = ing;}
    static acciones acc;
    static ingredientes ings;
    ArbolBinario<string>& getDatos(){return datos;}
    void setDatos(ArbolBinario<string> dat){datos = dat;}
    int ariedad(string nombre){return acc.ariedad(nombre);}
    
    class iterator{
    private:
        ArbolBinario<string>::postorden_iterador it;
    public:
        
        string & operator*(){return *it;}
        bool operator==(const iterator & other) {return it == other.it;}
        bool operator!=(const iterator & other) {return it != other.it;}
        //postorden_iterador& operator ++() {it++; return *this;}
        
        friend class instrucciones;
    };
    
   
    friend istream& operator>> (istream &in, instrucciones &instrucciones);
    friend ostream& operator<< (ostream &out, const instrucciones &instrucciones);

    
};

/*postorden_iterador begin();
postorden_iterador end();*/

#endif /* INSTRUCCIONES_H */

