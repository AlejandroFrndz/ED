/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ingrediente.h
 * Author: alejandro
 *
 * Created on 17 de octubre de 2019, 18:53
 */

/*
 TDA Ingrediente
 * Especificacion--> Información nutricional de un alimento
 * Funcion de Abastraccion--> f(r) = r.nombre;r.calorias;r.hidratos;r.proteinas;r.grasas;r.fibra;r.tipo
 * Invariante de la Representación--> r.calorias >= 0, r.hidratos >= 0, r.proteinas >= 0, r.fibra >= 0
    r.tipo c {Aceite, Azucar, Bebida, Carne, Cereal, Crustaceo, Especias-Condimento, Fruta, Frutos Secos, Huevo, Leche-Derivados, Legumbres,
              Molusco, Pescado, Procesado, Semillas, Verdura}
 */


#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include <string>
#include "tipo_ingrediente.h"

using namespace std;

class ingrediente{
    private:
        string nombre;
        float calorias;
        float hidratos;
        float proteinas;
        float grasas;
        float fibra;
        Tipo tipo;

    public:
        /**
          @brief Construye un ingrediente con todos los valores a 0, con el nombre "Nulo" y de tipo "nulo"
        */
        ingrediente();
        /**
          @brief Devuelve el nombre del ingrediente
          @return string con el nombre del elemento
        */
        string getNombre() const{return nombre;}
        /**
          @brief Devuelve el numero de calorias del ingrediente cada 100 gramos
          @return float con el numero de calorias
        */
        float getCalorias() const{return calorias;}
        /**
          @brief Devuelve el numero de hidratos del ingrediente cada 100 gramos
          @return float con el numero de hidratos
        */
        float getHc() const{return hidratos;};
        /**
          @brief Devuelve el numero de proteinas del ingrediente cada 100 gramos
          @return float con el numero de proteinas
        */
        float getProteinas() const{return proteinas;}
        /**
          @brief Devuelve el numero de grasas del ingrediente cada 100 gramos
          @return float con el numero de grasas
        */
        float getGrasas() const{return grasas;}
        /**
          @brief Devuelve el numero de fibra del ingrediente cada 100 gramos
          @return float con la cantidad de fibra
        */
        float getFibra() const{return fibra;}
        /**
          @brief Devuelve el tipo de ingrediente
          @return string con el tipo del ingrediente
        */
        string getTipo() const;
        /**
          @brief Establece los atributos del ingrediente
          @param nom: nombre del alimento
          @param cal: numero de calorias del alimento
          @param hid: numero de hidratos de carbono del alimento
          @param prot: numero de proteinas del alimento
          @param gra: cantidad de grasas del alimento
          @param fib: cantidad de fibra del alimento
          @param tip: tipo del alimento
        */
        void setIngrediente(string nom, float cal, float hid, float prot, float gra, float fib, string tip);
};

/**
 @brief Sobrecarga de operador para leer un ingrediente desde un archivo
 @param in: elemento leido desde el archivo
 @param ingrediente: ingrediente a establecer
 @return referencia al flujo de entrada
*/
istream& operator>>(istream& in, ingrediente& ingrediente);

/**
 @brief Sobrecarga de operador para imprimir por pantalla un ingrediente
 @param out:
 @param ingrediente: ingrediente a imprimir
 @return referencia al flujo de salida
*/
ostream& operator<<(ostream& out, ingrediente& ing);

/**
 @brief convierte una variable del tipo Tipo en un string
 @param tipo: tipo a convertir
 @return tipo pasado como argumento convertido a string
*/
string To_String(Tipo tipo);

/**
 @brief convierte un string en una variable de tipo Tipo
 @param tipo: string a convertir
 @return tipo pasado como argumento convertido a la enumeracion Tipo
*/
Tipo To_Tipo(string tipo);

#endif //INGREDIENTE_H

