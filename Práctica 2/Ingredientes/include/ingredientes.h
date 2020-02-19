/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ingredientes.h
 * Author: alejandro
 *
 * Created on 20 de octubre de 2019, 13:01
 */

/*
 TDA Ingredientes
 * Especificación--> Colección de objetos de tipo Ingrediente que mantienen un doble orden, por nombre y por tipo(a igualdad de tipo, por nombre)
 * Funcion de Abstraccion--> f(r)= datos[0] <= datos[1] <= --- <= datos[n] && indice[0] < indice[1] < ... < indice[n] 
 * Invariante de la Representacion--> indice.size == datos.size, datos[i] <= datos[i+1], indice[i] < indice[i+1]
 */

#include "ingrediente.h"
#include "VD.h"
#include "pair.h"

#ifndef INGREDIENTES_H
#define INGREDIENTES_H

class ingredientes {
private:
    VD<int> indice;
    VD<ingrediente> datos;
    /**
    @brief Busqueda binaria del ingrediente dentro del vector de datos
    @param inicio: posicion del vector que se toma como inicio de la busqueda
    @param fin: posicion del vector que se toma como fin de la busqueda
    @param ing: ingrediente que se quiere buscar
    @return  false,inicio si no se encuentra el ingrediente, true,pos si se halla el ingrediente    
    */
    par<bool,int> BBinaria_d(int inicio, int fin, const ingrediente& ing) const;
    /**
    @brief Busqueda binaria del ingrediente dentro del vector de indices
    @param inicio: posicion de inicio de busqueda
    @param fin: posicion de final de busqueda
    @param ing: ingrediente que se quiere buscar
    @return  false,inicio si no se encuentra el ingrediente, true,pos si se halla el ingrediente    
    */
    par<bool,int> BBinaria_i(int inicio, int fin, const ingrediente& ing) const;
    /**
    @brief Busqueda binaria por nombre de ingrediente dentro del vector de datos
    @param inicio: posicion de inicio de busqueda
    @param fin: posicion del vector que se toma como fin de la busqueda
    @param ing: ingrediente que se quiere buscar
    @return  false,inicio si no se encuentra el ingrediente, true,pos si se halla el ingrediente    
    */
    par<bool,int> BBinaria_nombre(int inicio, int fin, string n) const;
    /**
    @brief Busqueda binaria por tipo dentro del vector de indice
    @param inicio:posicion de inicio de busqueda
    @param fin: posicion del vector que se toma como fin de la busqueda
    @param ing: ingrediente que se quiere buscar
    @return  false,inicio si no se encuentra el ingrediente, true,pos si se halla el ingrediente    
    */
    par<bool,int> BBinaria_tipo(int inicio, int fin, string tipo) const;
    /**
    @brief busqueda binaria del ingrediente dentro del vector de datos
    @param ing: ingrediente a buscar
    @return false,inicio si no se encuentra el ingrediente, true,pos si se halla el ingrediente
    */
    par<bool,int> esta_d(const ingrediente& ing) const;
    /**
    @brief busqueda binaria del ingrediente dentro del vector de indices
    @param ing: ingrediente a buscar
    @return false,inicio si no se encuentra el ingrediente, true,pos si se halla el ingrediente
    */
    par<bool,int> esta_i(const ingrediente& ing) const;
    
    
public:
    /**
    @brief operador de consulta constante del vector de datos
    @param i: posicion del vector a la que se quiere acceder
    @return ingrediente en la posicion i del vector datos
    */
    const ingrediente& operator[] (int i) const {return datos[i];}
    /**
    @brief operador de consulta del vector de datos
    @param i: posicion del vector a la que se quiere acceder
    @return ingrediente en la posicion i del vector datos
    */
    ingrediente& operator[] (int i) {return datos[i];}
    /**
    @brief inserta un ingrediente en el objeto de tipo ingredientes
    @param ing: ingrediente a insertar
    */
    void Insertar(const ingrediente& ing);
    /**
     @brief elimina el ingrediente que tiene como nombre el pasado como argumento. Si el ingrediente no se encuentra, no hace nada
     @param nombre_ingrediente: nombre del ingrediente que se desea eliminar
     */
    void borrar(const string nombre_ingrediente);
    /**
    @brief consultor del tamaño del vector datos
    @return tamaño del vector datos
    */
    int size() const;
    /**
    @brief imprime todos los ingredientes de un mismo tipo
    @param out: operador de salida
    */
    void ImprimirPorTipo(ostream& out);
    /**
    @brief busca el ingrediente por el nombre
    @param n: nombre del ingrediente a buscar
    @return ingrediente buscado
    */
    ingrediente get(string n) const;
    /**
    @brief almacena los tipos de ingredientesen tipos_ingredientes.txt
    @return vector dinamico de los tipos de ingredientes
    */
    VD<string> getTipos() const;
    /**
    @brief busca los ingredientes de un mismo tipo
    @param tipo: tipo de ingrediente a buscar
    @return dato de tipo ingredientes con todos los ingredientes de un mismo tipo
    */
    ingredientes getIngredienteTipo(string tipo) const;
};

/**
 * @brief operador de entrada
 * @param in:flujo de entrada
 * @param ingredientes:objeto de tipo ingredientes en el que se depositaran los ingredientes leidos. Es modificado
 * @return referencia al flujo de entrada
 */
istream& operator>>(istream& in, ingredientes& ingredientes);
/**
 * @brief operador de salida
 * @param out:flujo de salida
 * @param ingredientes:objeto de tipo ingredientes del que se mostrará el contenido
 * @return referencia al flujo de salida
 */
ostream& operator<<(ostream& out, ingredientes& ingredientes);

#endif /* INGREDIENTES_H */

