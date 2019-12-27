/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   recetas.cpp
 * Author: alejandro
 * 
 * Created on 20 de noviembre de 2019, 17:29
 */

#include <map>

#include "recetas.h"

ostream& operator<<(ostream& os, const recetas& recetas){
    recetas::const_iterator it = recetas.cbegin();
    
    for(it; it != recetas.cend(); ++it)
        os << *it << endl;
    
    return os;
}

istream& operator>>(istream& in, recetas& recetas){
    receta rec, rec_prev;
    
    in >> rec;
    pair<string,receta> par;
    par.first = rec.getCode();
    par.second = rec;
    recetas.datos.insert(par);
    rec_prev = rec;
    in >> rec;
    
    while(rec != rec_prev){
        par.first = rec.getCode();
        par.second = rec;
        recetas.datos.insert(par);
        rec_prev = rec;
        in >> rec;
    }
    
    return in;
}

void recetas::calcularNutrientes(const ingredientes& lista){
    recetas::iterator it = begin();
    
    for(it; it != end(); ++it)
        (*it).calcularNutrientes(lista);
}