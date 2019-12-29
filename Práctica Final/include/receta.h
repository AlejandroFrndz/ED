/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   receta.h
 * Author: alejandro
 *
 * Created on 15 de noviembre de 2019, 11:45
 */

#ifndef RECETA_H
#define RECETA_H

#include <string>
#include <list>
#include <iostream>
#include "ingredientes.h"
#include "instrucciones.h"
#include "arbolbinario.h"

using namespace std;

class receta {
private:
    string code;
    unsigned int plato;
    string nombre;
    list<pair<string,unsigned int>> ings;
    float calorias, hc, grasas, proteinas, fibra;
    instrucciones inst;  
    
public:
    receta();
    
    static string ruta_instrucciones;
    
    class iterator{
    private:
        list<pair<string,unsigned int>>::iterator it;
    public:
        pair<string,unsigned int> & operator*() {return *it;}
        bool operator==(const iterator & other) {return it == other.it;}
        bool operator!=(const iterator & other) {return it != other.it;}
        iterator& operator++() {it++;return *this;}
        iterator& operator--() {it--;return *this;}
        
        friend class receta;
    };
    
    class const_iterator{
    private:
        list<pair<string,unsigned int>>::const_iterator it;
    public:
        const pair<string,unsigned int> & operator*() {return *it;}
        bool operator==(const const_iterator & other) {return it == other.it;}
        bool operator!=(const const_iterator & other) {return it != other.it;}
        const_iterator & operator++() {it++; return *this;}
        const_iterator & operator--() {it--; return *this;}
        
        friend class receta;
    };
    
    iterator begin() {iterator i; i.it = ings.begin(); return i;}
    iterator end() {iterator i; i.it = ings.end(); return i;}
    
    const_iterator cbegin() const {const_iterator i; i.it = ings.begin(); return i;}
    const_iterator cend() const {const_iterator i; i.it = ings.end(); return i;}
    
    int ningredientes() const {return ings.size();}
    //gets
    string getNombre() const {return nombre;}
    string getCode() const {return code;}
    float getCalorias() const {return calorias;}
    float getFibra() const {return fibra;}
    float getProteinas() const {return proteinas;}
    float getGrasas() const {return grasas;}
    float getHidratos() const {return hc;}
    instrucciones getInstrucciones(){return inst;}
    unsigned int getPlato() const {return plato;}
    
    list<pair<string, unsigned int>> getIngredientes(){return ings;} 
    void setInstrucciones(ArbolBinario<string> arbol){inst.setDatos(arbol);};
    void fusionar( receta &r1,  receta &r2);
    
    bool operator !=(const receta & other) const {return code != other.code;}
    void calcularNutrientes(const ingredientes &lista);

    friend ostream & operator<<(ostream& os, const receta& receta);
    friend istream& operator>>(istream& in, receta& receta);
};

#endif /* RECETA_H */

