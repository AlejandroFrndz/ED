
/*
 TDA Recetas
 * Especificación--> Colección de objetos de tipo receta
 * Funcion de Abstraccion--> f(r)= r.datos[0],r.datos[1],  ..... , r.datos[size-1]
 * Invariante de la Representacion--> el código de cada receta es único, por lo que dos recetas no pueden tener el mismo código
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
    /**
    @brief devuelve el comienzo del map de recetas
    @return iterator que apunta al comienzo del map
    */
    iterator begin() {iterator i; i.it = datos.begin(); return i;}
    /**
    @brief devuelve el final del map de recetas
    @return iterator que apunta al final del map
    */
    iterator end() {iterator i; i.it = datos.end(); return i;}
    /**
    @brief devuelve el comienzo del map de recetas
    @return const_iterator que apunta al comienzo del map
    */
    const_iterator cbegin() const {const_iterator i; i.it = datos.begin(); return i;}
    /**
    @brief devuelve el final del map de recetas
    @return const_iterator que apunta al final del map
    */
    const_iterator cend() const {const_iterator i; i.it = datos.end(); return i;}
    /**
    @brief devuelve el número de recetas
    @return long unsigned int con el tamaño del vector datos
    */
    long unsigned int size() const {return datos.size();}
    /**
    @brief consultor del map de recetas
    @param code: código de la receta
    @return referencia de la receta consultada
    */
    receta& operator[](string code) {return datos[code];}
    /**
    @brief borra la receta con el código indicado
    @param code: código de la receta a borrar
    */
    void borrar(string code) {datos.erase(code);}
    /**
    @brief calcula la cantidad de nutrientes de todas las recetas
    @param lista: lista con información de cada ingrediente
    */
    void calcularNutrientes(const ingredientes &lista);
    /**
    @brief añade una receta a el map de recetas
    @return iterator que apunta al final del map
    */
    void add(const pair<string,receta>& par) {datos.insert(par);}
    /**
    * @brief operador de salida
    * @param os:flujo de salida
    * @param recetas:objeto de tipo recetas del que se mostrará el contenido
    * @return referencia al flujo de salida
    */
    friend ostream& operator<<(ostream& os, const recetas& recetas);
    /**
    * @brief operador de entrada
    * @param in:flujo de entrada
    * @param receta:objeto de tipo recetas en el que se depositaran las recetas leidas. 
    * @return referencia al flujo de entrada
    */
    friend istream& operator>>(istream& in, recetas& recetas);


};

#endif /* RECETAS_H */

