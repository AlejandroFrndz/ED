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
    acciones& acc;
    
public:
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
    
   
    
    
};

/*postorden_iterador begin();
postorden_iterador end();*/
istream& operator>> (istream &in, instrucciones &instrucciones);

#endif /* INSTRUCCIONES_H */

