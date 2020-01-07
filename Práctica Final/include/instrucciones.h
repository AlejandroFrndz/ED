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

/*
 TDA Instrucciones
 * Especificación--> lista de pasos a seguir para realizar una receta, se almacena en forma de arbol binario
 * Función de Abstraccion --> 
 * Invariante de la Representación --> si datos[accion] = 1 -> solo tiene hijo izquierda,
 *                                     si datos[accion] = 2 -> tiene dos hijos 
 
 
 
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
    static acciones acc;
    static ingredientes ings;
    /**
      @brief Devuelve el conjunto de datos
      @return arbol binario con el conjunto de instrucciones
    */
    ArbolBinario<string>& getDatos(){return datos;}
    /**
      @brief Asigna a datos el arbol binario pasado como argumento
      @param dat: arbol binario que queremos asignar a datos
    */
    void setDatos(ArbolBinario<string> dat){datos = dat;}
    /**
      @brief Devuelve el la ariedad de la instruccion pasada como parametro
      @param nombre: nombre de la instruccion que queremos consultar
      @return int con la ariedad de la instrucción solicitada
    */
    int ariedad(string nombre){return acc.ariedad(nombre);}
    
    class iterator{
    private:
        ArbolBinario<string>::postorden_iterador it;
    public:
        
        string & operator*(){return *it;}
        bool operator==(const iterator & other) {return it == other.it;}
        bool operator!=(const iterator & other) {return it != other.it;}
        
        friend class instrucciones;
    };
    
    /**
     @brief Sobrecarga del operador de entrada
     @param os: flujo de entrada
     @param instrucciones: instrucciones a leer
     @return ostream con el flujo de entrada
    */
    friend istream& operator>> (istream &in, instrucciones &instrucciones);
    /**
     @brief Sobrecarga del operador de salida
     @param os: flujo de salida
     @param instrucciones: instrucciones a imprimir
     @return ostream con el flujo de salida
    */
    friend ostream& operator<< (ostream &out, const instrucciones &instrucciones);

    
};

#endif /* INSTRUCCIONES_H */

