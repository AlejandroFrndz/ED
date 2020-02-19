/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tipos_ingredientes.cpp
 * Author: alejandro
 *
 * Created on 27 de octubre de 2019, 17:20
 */

#include "ingredientes.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "pair.h"

using namespace std;

/*
 * 
 */
vector<float> medias(ingredientes conjunto){
    vector<float> media = {0,0,0,0,0};
    for (int i = 0; i < conjunto.size(); i++){
        media[0] += conjunto[i].getCalorias();
        media[1] += conjunto[i].getHc();
        media[2] += conjunto[i].getProteinas();
        media[3] += conjunto[i].getGrasas();
        media[4] += conjunto[i].getFibra();
    }
    
    for (int i = 0; i < 5; i++)
        media[i] = (media[i]*1.0)/conjunto.size();
    
    return media;
}

vector <float> varianzas(ingredientes conjunto, vector<float> medias){
    vector<float> varianza = {0,0,0,0,0};
    
    for (int i = 0; i < conjunto.size(); i++){
        varianza[0] += pow(conjunto[i].getCalorias()-medias[0], 2);
        varianza[1] += pow(conjunto[i].getHc()-medias[1], 2);
        varianza[2] += pow(conjunto[i].getProteinas()-medias[2], 2);
        varianza[3] += pow(conjunto[i].getGrasas()-medias[3], 2);
        varianza[4] += pow(conjunto[i].getFibra()-medias[4], 2);
    }
    for (int i = 0; i < 5; i++){
        varianza[i] = (varianza[i]*1.0)/conjunto.size();
        varianza[i] = sqrt(varianza[i]);
    }
    return varianza;
}

par< vector<float>,vector <string>> minimos(ingredientes conjunto){
    par<vector<float>,vector<string>> resultado;
    vector<float> minimos = {conjunto[0].getCalorias(),conjunto[0].getHc(),conjunto[0].getProteinas(),conjunto[0].getGrasas(),conjunto[0].getFibra()};
    vector<string> nombres = {conjunto[0].getNombre(),conjunto[0].getNombre(),conjunto[0].getNombre(),conjunto[0].getNombre(),conjunto[0].getNombre()};
    
    for (int i = 0; i < conjunto.size(); i++){
        if (conjunto[i].getCalorias() < minimos[0] ){
            minimos[0] = conjunto[i].getCalorias();
            nombres[0] = conjunto[i].getNombre();
        }
            
        if (conjunto[i].getHc() < minimos[1] ){
            minimos[1] = conjunto[i].getHc();
            nombres[1] = conjunto[i].getNombre();
        }
            
        if (conjunto[i].getProteinas() < minimos[2] ){
            minimos[2] = conjunto[i].getProteinas();
            nombres[2] = conjunto[i].getNombre();
        }
            
        if (conjunto[i].getGrasas() < minimos[3] ){
            minimos[3] = conjunto[i].getGrasas();
            nombres[3] = conjunto[i].getNombre();
        }
           
        if (conjunto[4].getFibra() < minimos[0] ){
            minimos[4] = conjunto[i].getFibra();
            nombres[4] = conjunto[i].getNombre();
        }
    }
    
    resultado.first = minimos;
    resultado.second = nombres;
    return resultado;
}

par< vector<float>,vector <string>> maximos(ingredientes conjunto){
    par<vector<float>,vector<string>> resultado;
    vector<float> maximos = {0,0,0,0,0};
    vector<string> nombres = {conjunto[0].getNombre(),conjunto[0].getNombre(),conjunto[0].getNombre(),conjunto[0].getNombre(),conjunto[0].getNombre()};
    
    for (int i = 0; i < conjunto.size(); i++){
        if (conjunto[i].getCalorias() > maximos[0] ){
            maximos[0] = conjunto[i].getCalorias();
            nombres[0] = conjunto[i].getNombre();
        }
            
        if (conjunto[i].getHc() > maximos[1] ){
            maximos[1] = conjunto[i].getHc();
            nombres[1] = conjunto[i].getNombre();
        }
            
        if (conjunto[i].getProteinas() > maximos[2] ){
            maximos[2] = conjunto[i].getProteinas();
            nombres[2] = conjunto[i].getNombre();
        }
            
        if (conjunto[i].getGrasas() > maximos[3] ){
            maximos[3] = conjunto[i].getGrasas();
            nombres[3] = conjunto[i].getNombre();
        }
           
        if (conjunto[4].getFibra() > maximos[0] ){
            maximos[4] = conjunto[i].getFibra();
            nombres[4] = conjunto[i].getNombre();
        }
    }
    resultado.first = maximos;
    resultado.second = nombres;
    return resultado;
}

void imprimirEstadisticas(ingredientes reducido, string tipo){
   
   cout << "\nEstadistica________________________" << endl;
   cout << "Tipo de Alimento " << tipo << endl;
   cout << "Promedio +-Desviacion" << endl;
   cout << "Calorias         Hidratos de Carb         Proteinas         Grasas         Fibra" << endl;
   vector <float> media = medias(reducido);
   vector <float> varianza = varianzas(reducido, media);
   
   for (int i = 0; i < 5; i++)
    cout << media[i] << " +-" << varianza[i] << "       ";
   
   cout << "\n\nMaximos valores" << endl;
   cout << "Calorias         Hidratos de Carb         Proteinas         Grasas         Fibra" << endl;
   
   par< vector<float>,vector <string>> maximo = maximos(reducido);
   
   for (int i = 0; i < 5; i++)
    cout << maximo.first[i] << " " << maximo.second[i] << " ";
   
   
   cout << "\n\nMinimos valores" << endl;
   cout << "Calorias         Hidratos de Carb         Proteinas         Grasas         Fibra" << endl;
   par< vector<float>,vector <string>> minimo = minimos(reducido);
   for (int i = 0; i < 5; i++)
    cout << minimo.first[i] << " " << minimo.second[i] << " ";
}

int main(int argc, char** argv) {

    if(argc != 3){
        cout << "Pásame como argumento el archivo que contiene los ingredientes y el tipo de ingrediente sobre el que quieres trabajar" << endl;
        exit(-1);
    }
    
    string tipo = argv[2];
    
    if(tipo != "Aceite" && tipo != "Azucar" && tipo != "Bebida" && tipo != "Carne" && tipo != "Cereal" && tipo != "Crustaceo" && tipo != "Especias-Condimento" && tipo != "Fruta" && tipo != "Frutos Secos" && tipo != "Huevo" && tipo != "Leche-Derivados" && tipo != "Legumbres" && tipo != "Molusco" && tipo != "Pescado" && tipo != "Procesado" && tipo != "Semillas" && tipo != "Verdura"){
        cout << tipo << " no es un tipo de ingrediente válido";
        exit(-1);
    }
    
    string f = argv[1];
    ifstream file(f);
    
    if(!file){
        cout << "Error al abrir el archivo " << f << endl;
        exit(-1);
    }
    
    ingredientes all;
    string linea;
    getline(file,linea);
    
    file.seekg(0);
    file >> all;
    
   VD<string> tipos=all.getTipos();
   cout<<"Los tipos de alimentos son:"<<endl;
   for (int i=0;i<tipos.size(); ++i){
      cout<<tipos[i]<<endl;
   }
   
   cout << endl;
   
   ingredientes reducido = all.getIngredienteTipo(tipo);
   
   
   cout << "Los ingredientes de tipo " << tipo << " son:" << endl << linea << endl << reducido;
   
   imprimirEstadisticas(reducido,tipo);
   
   
}

