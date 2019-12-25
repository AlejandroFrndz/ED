/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acciones.cpp
 * Author: alejandro
 * 
 * Created on 13 de diciembre de 2019, 11:48
 */

#include "acciones.h"

acciones::iterator acciones::begin(){
    iterator i;
    i.it = datos.begin();
    
    return i;
}

acciones::iterator acciones::end(){
    iterator i;
    i.it = datos.end();
    
    return i;
}

acciones::const_iterator acciones::cbegin() const{
    const_iterator i;
    i.it = datos.begin();
    
    return i;
}

acciones::const_iterator acciones::cend() const{
    const_iterator i;
    i.it = datos.end();
    
    return i;
}

istream& operator>>(istream& in, acciones& acciones){
    pair<string,unsigned char> accion;
    string linea ,subcadena;
    int punto1;
    getline(in,linea);
    while( linea.size() != 0){
        

        for(int i = 0; i < linea.size(); i++){

            if(linea[i] == ' '){
                punto1 = i;
                subcadena = linea.substr(0,punto1);
                accion.first = subcadena;
                accion.second = linea[i+1];
                acciones.insert(accion);

            }

        }
        getline(in,linea);
    
    }
    
    
    return in;
}

ostream& operator<<(ostream& os, acciones& acciones){
    
    acciones::const_iterator it;
    
    for(it = acciones.cbegin();it != acciones.cend(); ++it){
        os << (*it).first << " " << (*it).second << endl;
    }
    
    return os;
}
