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

using namespace std;

#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H
class instrucciones{
private:
    ArbolBinario<string>datos;
    static acciones &acc;
    
public:
    /*class iterator{
    private:
        ArbolBinario<string>::nodo it;
    public:
        string & operator*(){return *it;}
        bool operator==(const iterator & other) {return it == other.it;}
        bool operator!=(const iterator & other) {return it != other.it;}
        nodo& operator ++() {it++; return *this;}
        nodo& operator --() {it--; return *this;}
        
        friend class acciones;
    };
    
    postorden_iterador begin();
    postorden_iterador end();*/
    

};


#endif /* INSTRUCCIONES_H */

