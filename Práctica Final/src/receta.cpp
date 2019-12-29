/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   receta.cpp
 * Author: alejandro
 * 
 * Created on 15 de noviembre de 2019, 11:45
 */

#include "receta.h"
#include "ingredientes.h"
#include <fstream>
#include "color.h"
#include "arbolbinario.h"
receta::receta(){
    code = "N";
    plato = 0;
    nombre = "Undefined";
    calorias = hc = grasas = proteinas = fibra = 0;
}

ostream & operator<<(ostream& os, const receta& receta){
    os << BOLD(FBLU("CODE: ")) << receta.code << " " << BOLD(FBLU("RECETA: ")) << receta.nombre << " " << BOLD(FBLU("PLATO: ")) << receta.plato << endl << endl;
    
    os << UNDL(BOLD("Ingredientes:")) << endl << endl;
    receta::const_iterator it = receta.cbegin();
    
    int cnt = 1;
    for(it; it != receta.cend() && cnt < receta.ings.size(); ++it,cnt++)
        os << "\t" << (*it).first << " " << (*it).second << endl;
    
    os << "\t" << (*it).first << " " << (*it).second << endl << endl;
    
    os << UNDL(BOLD("Información Nutricional:")) << endl << endl;
    
    os << "\tCalorias:" << receta.getCalorias() << endl;
    os << "\tHidratos de Carbono:" << receta.getHidratos() << endl;
    os << "\tGrasas:" << receta.getGrasas() << endl;
    os << "\tProteinas:" << receta.getProteinas() << endl;
    os << "\tFibra:" << receta.getFibra() << endl << endl;
    
    os << UNDL(BOLD("Pasos a seguir:")) << endl << endl;
    
    os << receta.inst;
    
    return os;
}
istream& operator>>(istream& in, receta& receta){
    string linea,sub_cadena;
    int contador = 0, punto1 =0, punto2, pos_espacio;
    
    receta.ings.clear();
   
    pair<string,unsigned int> ingrediente;
    bool seguir  = true;
    
    getline(in, linea);
    
    if(linea.size() > 0){
        for (int i = 0; i < linea.size(); i++){

            if(linea[i] == ';'){
                punto2 = i;
                sub_cadena = linea.substr(punto1,punto2-punto1);

                if(contador > 2){
                    for (int j = sub_cadena.size()-1; j >= 0 && seguir; j--){
                        if(sub_cadena[j] == ' '){
                            seguir = false;
                            pos_espacio = j;
                        }
                    }

                    seguir = true;
                    ingrediente.second = atoi(sub_cadena.substr(pos_espacio,sub_cadena.length()-pos_espacio).c_str());
                    ingrediente.first = sub_cadena.substr(0,pos_espacio);
                    receta.ings.push_back(ingrediente);
                }

                else if(contador == 0){
                    receta.code = sub_cadena; 
                }

                else if(contador == 1){
                    receta.plato = atoi(sub_cadena.c_str());
                }

                else if(contador == 2){
                    receta.nombre = sub_cadena;
                }
                punto1 = i+1;
                contador++;
            }
        }
        sub_cadena = linea.substr(punto1,linea.size()-punto1);
        for (int j = sub_cadena.size()-1; j >= 0 && seguir; j--){
            if(sub_cadena[j] == ' '){
                seguir = false;
                pos_espacio = j;
            }
        }

       // sub_cadena = linea.substr(punto1,linea.size()-punto1);

        ingrediente.second = atoi(sub_cadena.substr(pos_espacio,sub_cadena.length()-pos_espacio).c_str());
        ingrediente.first = sub_cadena.substr(0,pos_espacio);
        receta.ings.push_back(ingrediente);   
    }
    
    receta.calcularNutrientes(instrucciones::ings);
    
    ifstream f(receta::ruta_instrucciones + receta.getCode() + "m.txt");
    
    f >> receta.inst;
    
    return in;
}

void receta::calcularNutrientes(const ingredientes &lista){
    receta::iterator it;
    ingrediente ing;
    for (it = this->begin(); it != this->end(); ++it){
        ing = lista.get((*it).first);
        this->calorias += (ing.getCalorias()/100)*((*it).second);
        this->hc += (ing.getHc()/100)*((*it).second);
        this->grasas += (ing.getGrasas()/100)*((*it).second);
        this->proteinas += (ing.getProteinas()/100)*((*it).second);
        this->fibra += (ing.getFibra()/100)*((*it).second);
    }
}


void receta::fusionar(receta& r1, receta& r2){
    hc = r1.getHidratos() +r2.getHidratos();
    grasas = r1.getGrasas() +r2.getGrasas();
    fibra = r1.getFibra() +r2.getFibra();
    proteinas = r1.getProteinas() +r2.getProteinas();
    calorias = r1.getCalorias() +r2.getCalorias(); 
    nombre = "Fusion " + r1.getNombre() + " y " + r2.getNombre();
    code = "F_"+r1.getCode()+"_"+r2.getCode();
    
    if(r1.getPlato() <= r2.getPlato())
        plato = r1.getPlato();
    else
        plato = r2.getPlato();
            
    list<pair<string,unsigned int>> lista = r1.getIngredientes();
    list<pair<string,unsigned int>> lista2 = r2.getIngredientes();
    
    list<pair<string,unsigned int>>::const_iterator it;
    list<pair<string,unsigned int>>::iterator it2;
    bool insertar = true;
    
    ings.assign(lista.begin(),lista.end());
    for(it = lista2.begin(); it != lista2.end(); ++it ){
        for (it2 = ings.begin(); it2 != ings.end() && insertar; ++it2){
            if( (*it).first == (*it2).first ){
                (*it2).second += (*it).second;
                insertar = false;
            }
        }
        if(insertar)
            ings.push_back((*it));
        insertar = true;
    }
    
    ArbolBinario<string> arbol("Acompañar");
    arbol.Insertar_Hi(arbol.getRaiz(), r1.getInstrucciones().getDatos());
    arbol.Insertar_Hd(arbol.getRaiz(),r2.getInstrucciones().getDatos());
    
    this->setInstrucciones(arbol);
}