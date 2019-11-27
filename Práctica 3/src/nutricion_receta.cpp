/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "recetas.h"
#include "ingredientes.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
    if(argc != 4){
        cout << "Ejecucción: ./nutricion_receta {archivo con las recetas} {archivo con los ingredientes} {calorías máximas}";
        exit(-1);
    }
    
    ifstream r(argv[1]);
    ifstream i(argv[2]);
    int calorias_max = stoi(argv[3]);
    
    if(!r){
        cout << "No se pudo abrir el archivo de las recetas " << argv[1];
        exit(-1);
    }
    
    if(!i){
        cout << "No se pudo abrir el archivo de los ingredientes " << argv[2];
        exit(-1);
    }
    
    recetas rec;
    ingredientes ings;
    
    r >> rec;
    i >> ings;
    
    rec.calcularNutrientes(ings);
    
    recetas::const_iterator it = rec.cbegin();
    
    for(it; it != rec.cend(); ++it){
        cout << (*it) << "\n Calorias: " << (*it).getCalorias() << " Fibra: " << (*it).getFibra() << " Proteinas: " << (*it).getProteinas() << " Hidratos: " << (*it).getHidratos() << " Grasas: " << (*it).getGrasas() << endl << endl;
    }
}