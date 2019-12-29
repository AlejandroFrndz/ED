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
    /**
     @brief Devuelve el numero de ingredientes
     @return int con el numero de ingredientes
    */
    int ningredientes() const {return ings.size();}
    /**
     @brief Devuelve el nombre de la receta
     @return string con el nombre de la receta
    */
    string getNombre() const {return nombre;}
    /**
     @brief Devuelve el codigo de la receta
     @return string con el codigo de la receta
    */
    string getCode() const {return code;}
    /**
     @brief Devuelve el numero de calorias de la receta de la receta
     @return int con el numero de calorias de la receta de la receta
    */
    float getCalorias() const {return calorias;}
    /**
     @brief Devuelve la cantidad de fibra de la receta de la receta
     @return int con la cantidad de fibra de la receta de la receta
    */
    float getFibra() const {return fibra;}
    /**
     @brief Devuelve la cantidad de proteinas de la receta de la receta
     @return int con la cantidad de proteinas de la receta de la receta
    */
    float getProteinas() const {return proteinas;}
    /**
     @brief Devuelve la cantidad de grasas de la receta de la receta
     @return int con la cantidad de grasas de la receta de la receta
    */
    float getGrasas() const {return grasas;}
    /**
     @brief Devuelve la cantidad de hidratos de la receta de la receta
     @return int con la cantidad de hidratos de la receta de la receta
    */
    float getHidratos() const {return hc;}
    /**
     @brief Devuelve las instrucciones de la receta de la receta
     @return objeto instrucciones con las instrucciones de la receta
    */
    instrucciones getInstrucciones(){return inst;}
    /**
     @brief Devuelve el numero del plato segun si es entrante, principal o postre
     @return int con el numero del plato 
    */
    unsigned int getPlato() const {return plato;}
    /**
     @brief Devuelve los ingredientes de la receta de la receta
     @return list<pair<string,unsigned int>> con los ingredientes y sus cantidades
    */
    list<pair<string, unsigned int>> getIngredientes(){return ings;} 
    /**
     @brief Asigna al arbol binario de inst el pasado como parametro
     @param arbol: arbol que se quiere asignar
    */
    void setInstrucciones(ArbolBinario<string> arbol){inst.setDatos(arbol);}
    /**
     @brief fusiona las dos recetas pasadas como parametro
     @param r1: primera receta a fusionar
     @param r2: segunda receta a fusionar
    */
    void fusionar( receta &r1,  receta &r2);
    
    bool operator !=(const receta & other) const {return code != other.code;}
    /**
     @brief Calcula los nutrientes de la receta
     @param lista: conjunto con la informacion sobre todos los ingredientes
    */
    void calcularNutrientes(const ingredientes &lista);
    /**
     @brief Sobrecarga del operador de salida
     @param os: flujo de salida
     @param receta: receta a imprimir
     @return ostream con el flujo de salida
    */
    friend ostream & operator<<(ostream& os, const receta& receta);
    /**
     @brief Sobrecarga del operador de entrada
     @param os: flujo de entrada
     @param receta: receta a leer
     @return ostream con el flujo de entrada
    */
    friend istream& operator>>(istream& in, receta& receta);
};

#endif /* RECETA_H */

