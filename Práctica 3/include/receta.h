
/*
 TDA Recetas
 * Especificación--> Colección de objetos de tipo ingrediente, en el que se guarda informacion sobre su valor nutricional
 * Funcion de Abstraccion--> f(r)= r.code;r.plato;r.nombre;(r.ings[0].first,r.ings[0].second),.., (r.ings[size-1].first,r.ings[size-1].second);r.calorias;r.hc;r.grasas;r.proteinas;r.fibra
 * Invariante de la Representacion-->
 */
#ifndef RECETA_H
#define RECETA_H

#include <string>
#include <list>
#include <iostream>
#include "ingredientes.h"

using namespace std;

class receta {
private:
    string code;
    unsigned int plato;
    string nombre;
    list<pair<string,unsigned int>> ings;
    float calorias, hc, grasas, proteinas, fibra;
    
public:
    receta();
    
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
    /**
    @brief devuelve el comienzo de la lista de ingredientes
    @return iterator que apunta al comienzo de la lista
    */
    iterator begin() {iterator i; i.it = ings.begin(); return i;}
    /**
    @brief devuelve el final de la lista de ingredientes
    @return iterator que apunta al comienzo de lista
    */
    iterator end() {iterator i; i.it = ings.end(); return i;}
    /**
    @brief devuelve el comienzo de la lista de ingredientes
    @return const_iterator que apunta al comienzo de la lista
    */
    const_iterator cbegin() const {const_iterator i; i.it = ings.begin(); return i;}
    /**
    @brief devuelve el final de la lista de ingredientes
    @return const_iterator que apunta al comienzo de lista
    */
    const_iterator cend() const {const_iterator i; i.it = ings.end(); return i;}
    /**
    @brief consultor del tamaño de la lista de ingredientes
    @return valor entero del número de ingredientes
    */
    int ningredientes() const {return ings.size();}
    /**
    @brief consultor del nombre de la receta
    @return string con el nombre de la receta
    */
    string getNombre() const {return nombre;}
    /**
    @brief consultor del código de la receta
    @return string con el código de la receta
    */
    string getCode() const {return code;}
    /**
    @brief consultor de la cantidad de calorias
    @return float del numero de calorias
    */
    float getCalorias() const {return calorias;}
    /**
    @brief consultor de la cantidad de fibra
    @return float del numero de fibra
    */
    float getFibra() const {return fibra;}
    /**
    @brief consultor de la cantidad de proteinas
    @return float del numero de proteinas
    */
    float getProteinas() const {return proteinas;}
    /**
    @brief consultor de la cantidad de grasas
    @return float del numero de grasas
    */
    float getGrasas() const {return grasas;}
    /**
    @brief consultor de la cantidad de hidratos
    @return float del numero de hidrratos
    */
    float getHidratos() const {return hc;}
    /**
    @brief sobrecarga del operador !=
    @param receta: primera receta a comparar
    @param other: segunda receta a comparar
    @return true si sus códigos son distintos, false si sus códigos son iguales
    */
    bool operator !=(const receta & other) const {return code != other.code;}
    /**
    @brief calcula la cantidad de nutrientes de una receta
    @param lista: lista con información de cada ingrediente
    */
    void calcularNutrientes(const ingredientes &lista);
    /**
    * @brief operador de salida
    * @param os:flujo de salida
    * @param receta:objeto de tipo receta del que se mostrará el contenido
    * @return referencia al flujo de salida
    */
    friend ostream & operator<<(ostream& os, const receta& receta);
    /**
    * @brief operador de entrada
    * @param in:flujo de entrada
    * @param receta:objeto de tipo receta en el que se depositaran los ingredientes leidos. 
    * @return referencia al flujo de entrada
    */ 
    friend istream& operator>>(istream& in, receta& receta);
};

#endif /* RECETA_H */

