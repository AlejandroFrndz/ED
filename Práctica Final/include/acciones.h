/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acciones.h
 * Author: alejandro
 *
 * Created on 13 de diciembre de 2019, 11:48
 */

#include <map>
#include <string>
#include <iostream>

using namespace std;

#ifndef ACCIONES_H
#define ACCIONES_H

class acciones {
private:
    map<string,unsigned char> datos;
public:
    
    void insert(pair<const string, unsigned char> p){datos.insert(p);}
    class iterator{
    private:
        map<string,unsigned char>::iterator it;
    public:
        pair<const string,unsigned char> & operator*() {return *it;}
        bool operator==(const iterator & other) {return it == other.it;}
        bool operator!=(const iterator & other) {return it != other.it;}
        iterator& operator++() {it++; return *this;}
        iterator& operator--() {it--; return *this;}
        
        friend class acciones;
    };
    
    class const_iterator{
    private:
        map<string,unsigned char>::const_iterator it;
    public:
        const pair<const string,unsigned char> & operator*() {return *it;}
        bool operator==(const const_iterator & other) {return it == other.it;}
        bool operator!=(const const_iterator & other) {return it != other.it;}
        const_iterator& operator++() {it++; return *this;}
        const_iterator& operator--() {it--; return *this;}
        
        friend class acciones;
    };
    
    //acciones();
    
    iterator begin();
    iterator end();
    
    const_iterator cbegin() const;
    const_iterator cend() const;
    
};

/**
 * @brief operador de entrada
 * @param in:flujo de entrada
 * @param ingredientes:objeto de tipo acciones en el que se depositaran las acciones leidas. Es modificado
 * @return referencia al flujo de entrada
 */
istream& operator>>(istream& in, acciones& acciones);
/**
 * @brief operador de salida
 * @param out:flujo de salida
 * @param ingredientes:objeto de tipo acciones del que se mostrará el contenido
 * @return referencia al flujo de salida
 */
ostream& operator<<(ostream& os, acciones& acciones);

#endif /* ACCIONES_H */

