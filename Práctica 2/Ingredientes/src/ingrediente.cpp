/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ingrediente.cpp
 * Author: alejandro
 * 
 * Created on 20 de octubre de 2019, 12:03
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ingrediente.cpp
 * Author: alejandro
 * 
 * Created on 17 de octubre de 2019, 18:53
 */

#include <string>
#include <fstream>
#include "ingrediente.h"

using namespace std;

string To_String(Tipo tipo){
    string type;
    switch (tipo){
        case Tipo::ACEITE:
            type = "Aceite";
            break;
        case Tipo::AZUCAR:
            type = "Azucar";
            break;
        case Tipo::BEBIDA:
            type = "Bebida";
            break;
        case Tipo::CARNE:
            type = "Carne";
            break;
        case Tipo::CEREAL:
            type = "Cereal";
            break;
        case Tipo::CRUSTACEO:
            type = "Crustaceo";
            break;
        case Tipo::ESPECIASCONDIMENTO:
            type = "Especias-Condimento";
            break;
        case Tipo::FRUTA:
            type = "Fruta";
            break;
        case Tipo::FRUTOSSECOS:
            type = "Frutos Secos";
            break;
        case Tipo::HUEVO:
            type = "Huevo";
            break;
        case Tipo::LECHEDERIVADOS:
            type = "Leche-Derivados";
            break;
        case Tipo::LEGUMBRE:
            type = "Legumbre";
            break;
        case Tipo::MOLUSCO:
            type = "Molusco";
            break;
        case Tipo::PESCADO:
            type = "Pescado";
            break;
        case Tipo::PROCESADO:
            type = "Procesado";
            break;
        case Tipo::SEMILLAS:
            type = "Semillas";
            break;
        case Tipo::VERDURA:
            type = "Verdura";
            break;
        case Tipo::NULO:
            type = "Nulo";
    }

    return type;

}

Tipo To_Tipo(string tipo){

    if(tipo == "Aceite")
        return Tipo::ACEITE;
    if(tipo == "Azucar")
        return Tipo::AZUCAR; 
    if(tipo == "Bebida")
        return Tipo::BEBIDA;
    if(tipo == "Carne")
        return Tipo::CARNE;
    if(tipo == "Cereal")
        return Tipo::CEREAL;
    if(tipo == "Crustaceo")
        return Tipo::CRUSTACEO;
    if(tipo == "Especias-Condimento")
        return Tipo::ESPECIASCONDIMENTO;
    if(tipo == "Fruta")
        return Tipo::FRUTA;
    if(tipo == "Frutos Secos")
        return Tipo::FRUTOSSECOS;
    if(tipo == "Huevo")
        return Tipo::HUEVO;
    if(tipo == "Leche-Derivados")
        return Tipo::LECHEDERIVADOS;
    if(tipo == "Legumbre")
        return Tipo::LEGUMBRE;
    if(tipo == "Molusco")
        return Tipo::MOLUSCO;
    if(tipo == "Pescado")
        return Tipo::PESCADO;
    if(tipo == "Procesado")
        return Tipo::PROCESADO;
    if(tipo == "Semillas")
        return Tipo::SEMILLAS;
    if(tipo == "Verdura")
        return Tipo::VERDURA;
    if(tipo == "Nulo")
        return Tipo::NULO;
}

ingrediente::ingrediente(){
    nombre = "Nulo";
    calorias = 0;
    hidratos = 0;
    proteinas = 0;
    grasas = 0;
    fibra = 0;
    tipo = Tipo::NULO;
}

string ingrediente::getTipo() const{
    return To_String(tipo);
}

void ingrediente::setIngrediente(string nom, float cal, float hid, float prot, float gra, float fib, string tip){
    nombre = nom;
    calorias = cal;
    hidratos = hid;
    proteinas = prot;
    grasas = gra;
    fibra = fib;
    tipo = To_Tipo(tip);
}

istream& operator>>(istream& in, ingrediente& ingrediente){
    string linea;
    string sub_cadena;
    string nombre;
    string tipo;
    float num_calorias,
	  hidratos, 
	  proteinas, 
	  grasas, 
	  fibra;

    getline(in, linea);
    
    int punto1=0, punto2, contador = 0, value[5], j=0;
    
    for (int i = 0; i < linea.size(); i++){
        if(linea[i] == ';'){
            punto2 = i;
            sub_cadena = linea.substr(punto1,punto2-punto1);
            if (contador > 0){
                value[j] = atoi(sub_cadena.c_str()); //convierte la subcadena a entero
                j++;
                
            }
            else{
                if(contador == 0)
                    nombre = sub_cadena;
            }
            punto1 = i+1;
            contador++;
            }
        }
    
    sub_cadena = linea.substr(punto1,nombre.size()-punto1);
    tipo = sub_cadena;


    ingrediente.setIngrediente(nombre,value[0],value[1],value[2],value[3],value[4],tipo);
    
    return in;
}

ostream& operator<<(ostream& out, ingrediente& ing){
    
    out<< ing.getNombre() << ";"<< ing.getCalorias() << ";" << ing.getHc() << ";" << ing.getProteinas() << ";" << ing.getGrasas() << ";" << ing.getFibra() << ";" << ing.getTipo()<< endl;
    return out;
}

