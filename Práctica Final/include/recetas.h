/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   recetas.h
 * Author: alejandro
 *
 * Created on 20 de noviembre de 2019, 17:29
 */

#ifndef RECETAS_H
#define RECETAS_H

#include <map>

#include "receta.h"

class recetas {
private:
    map<string,receta> datos;
public:
    class iterator{
    private:
        map<string,receta>::iterator it;
    public:
        receta & operator*() {return (*it).second;}
        bool operator==(const iterator & other) {return it == other.it;}
        bool operator!=(const iterator & other) {return it != other.it;}
        iterator& operator++() {it++;return *this;}
        iterator& operator--() {it--;return *this;}
        
        friend class recetas;
    };
    
    class const_iterator{
    private:
        map<string,receta>::const_iterator it;
    public:
        const receta & operator*() {return (*it).second;}
        bool operator==(const const_iterator & other) {return it == other.it;}
        bool operator!=(const const_iterator & other) {return it != other.it;}
        const_iterator& operator++() {it++;return *this;}
        const_iterator& operator--() {it--;return *this;}
        
        friend class recetas;
    };
    
    iterator begin() {iterator i; i.it = datos.begin(); return i;}
    iterator end() {iterator i; i.it = datos.end(); return i;}
    
    const_iterator cbegin() const {const_iterator i; i.it = datos.begin(); return i;}
    const_iterator cend() const {const_iterator i; i.it = datos.end(); return i;}
    
    long unsigned int size() const {return datos.size();}
    receta& operator[](string code) {return datos[code];}
    void borrar(string code) {datos.erase(code);}
    void calcularNutrientes(const ingredientes &lista);
    void add(const pair<string,receta>& par) {datos.insert(par);}
    friend ostream& operator<<(ostream& os, const recetas& recetas);
    friend istream& operator>>(istream& in, recetas& recetas);


};

#endif /* RECETAS_H */

