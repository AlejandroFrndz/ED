/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ingredientes.cpp
 * Author: alejandro
 * 
 * Created on 20 de octubre de 2019, 13:01
 */

#include "ingredientes.h"
#include <fstream>

par<bool,int> ingredientes::esta_d(const ingrediente& ing) const{
    
    return BBinaria_d(0,datos.size(), ing);
}

par<bool,int> ingredientes::esta_i(const ingrediente& ing) const{
    return BBinaria_i(0,indice.size(), ing);
}

par<bool,int> ingredientes::BBinaria_i(int inicio, int fin, const ingrediente& ing) const{
        par<bool,int> devolucion;
    
    if(inicio < fin){
        int mitad = (inicio+fin)/2;
        if(datos[indice[mitad]].getNombre() == ing.getNombre() && datos[indice[mitad]].getTipo() == ing.getTipo()){
            devolucion.first = true;
            devolucion.second = mitad;
            return devolucion;
        }
        
        else{
            if(datos[indice[mitad]].getTipo() < ing.getTipo())
                return BBinaria_i(mitad+1, fin, ing);
            else
                return BBinaria_i(inicio, mitad, ing);
        }
    }
    
    else{
        devolucion.first = false;
        devolucion.second = inicio;
        return devolucion;
    }

}

par<bool,int> ingredientes::BBinaria_d(int inicio, int fin,const ingrediente& ing) const{
    par<bool,int> devolucion;
    
    if(inicio < fin){
        int mitad = (inicio+fin)/2;
        if(datos[mitad].getNombre() == ing.getNombre() && datos[mitad].getTipo() == ing.getTipo()){
            devolucion.first = true;
            devolucion.second = mitad;
            return devolucion;
        }
        
        else{
            if(datos[mitad].getNombre() < ing.getNombre())
                return BBinaria_d(mitad+1, fin, ing);
            else
                return BBinaria_d(inicio, mitad, ing);
        }
    }
    
    else{
        devolucion.first = false;
        devolucion.second = inicio;
        return devolucion;
    }
}

par<bool,int> ingredientes::BBinaria_nombre(int inicio, int fin, string n) const{
    par<bool,int> devolucion;
    
    if(inicio < fin){
        int mitad = (inicio+fin)/2;
        if(datos[mitad].getNombre() == n){
            devolucion.first = true;
            devolucion.second = mitad;
            return devolucion;
        }
        
        else{
            if(datos[mitad].getNombre() < n)
                return BBinaria_nombre(mitad+1, fin, n);
            else
                return BBinaria_nombre(inicio, mitad, n);
        }
    }
    
    else{
        devolucion.first = false;
        devolucion.second = inicio;
        return devolucion;
    }
}

par<bool,int> ingredientes::BBinaria_tipo(int inicio, int fin, string tipo) const{
        par<bool,int> devolucion;
    
    if(inicio < fin){
        int mitad = (inicio+fin)/2;
        if(datos[indice[mitad]].getTipo() == tipo){
            devolucion.first = true;
            devolucion.second = mitad;
            while(devolucion.second >= 0 && datos[indice[devolucion.second]].getTipo() == tipo)
                devolucion.second--;
            
            devolucion.second++;
            return devolucion;
        }
        
        else{
            if(datos[indice[mitad]].getTipo() < tipo)
                return BBinaria_tipo(mitad+1, fin, tipo);
            else
                return BBinaria_tipo(inicio, mitad, tipo);
        }
    }
    
    else{
        devolucion.first = false;
        devolucion.second = inicio;
        return devolucion;
    }

}

void ingredientes::Insertar(const ingrediente& ing){
    par<bool,int> posd = esta_d(ing);
    par<bool,int> posi = esta_i(ing);
    
    if(!posd.first){
        for(int i = 0; i < indice.size(); i++){
            if(indice[i] >= posd.second)
                indice[i]++;
        }

        datos.Insert(ing, posd.second);
        
        int cnt = posi.second;
        bool seguir = true;
        
        if(datos.size() > 1){
            while(cnt < indice.size() && datos[indice[cnt]].getTipo() == ing.getTipo() && seguir){
                if(datos[indice[cnt]].getNombre() > ing.getNombre())
                    seguir = false;
                else{
                    cnt++;
                }
            }
        }
        
        indice.Insert(posd.second, cnt);
    }
    else{
        datos[posd.second] = ing;
    }
}

void ingredientes::borrar(const string nombre_ingrediente){
    ingrediente ing = this->get(nombre_ingrediente);
    par<bool,int> posd = esta_d(ing);
    par<bool,int> posi = esta_i(ing);
    
    if(posd.first){
        for(int i = 0; i < indice.size(); i++){
            if(indice[i] >= posd.second)
                indice[i]--;
        }

        datos.Erase(posd.second);
        
        int cnt = posi.second;
        bool seguir = true;
        
        if(datos.size() > 1){
            while(cnt < indice.size() && datos[indice[cnt]].getTipo() == ing.getTipo() && seguir){
                if(datos[indice[cnt]].getNombre() == ing.getNombre())
                    seguir = false;
                else{
                    cnt++;
                }
            }
        }
        
        indice.Erase(cnt);
    }
}

int ingredientes::size() const{
    return datos.size();
}

void ingredientes::ImprimirPorTipo(ostream& out){
    for(int i = 0; i < indice.size(); i++)
        out << datos[indice[i]];
}

ingrediente ingredientes::get(string n) const{
    par<bool,int> pos = BBinaria_nombre(0,datos.size(),n);
    
    ingrediente ing;
    
    if(pos.first){
        ing = datos[pos.second];
        return ing;
    }
    
    else
        return ing;
}

VD<string> ingredientes::getTipos() const{
    VD<string> vec;
    string tipo, archivo = "./datos/tipos_ingredientes.txt";
    int i = 0;
    
    ifstream in(archivo);
    
    while(in >> tipo){
        vec.Insert(tipo,i);
        i++;
    }
    
    in.close();
    
    return vec;
}

ingredientes ingredientes::getIngredienteTipo(string tipo) const{
    par<bool,int> pos = BBinaria_tipo(0, indice.size(), tipo);
    int cnt = pos.second;
    ingredientes devolucion;
    
    if(pos.first){
        while(cnt < indice.size() && datos[indice[cnt]].getTipo() == tipo){
            devolucion.Insertar(datos[indice[cnt]]);
            cnt++;
        }
    }
    
    return devolucion;
}

istream& operator>>(istream& in, ingredientes& ingredientes){
    string linea;
    
    getline(in, linea);
    
    ingrediente i;
    
    in >> i;
    
    while(! i.getNombre().empty()){
        ingredientes.Insertar(i);
        in >> i;
    }
    
    return in;
}

ostream& operator<<(ostream& out, ingredientes& ingredientes){
    for(int i = 0; i < ingredientes.size(); i++)
        out << ingredientes[i];
    
    return out;
}