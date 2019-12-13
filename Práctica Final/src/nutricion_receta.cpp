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

void calcular_dieta(recetas & rec, int calorias_max, recetas & dieta){
    int num_recetas = rec.size();
    float matriz[num_recetas+1][calorias_max+1];
    
    string code;
    receta receta_actual;
    float razon;
    int calorias;
    
    for(int j = 0; j < calorias_max+1;j++)
        matriz[0][j] = 0;
    
    for(int i = 1; i < num_recetas+1; i++){
        code = "R" + to_string(i);
        receta_actual = rec[code];
        razon = receta_actual.getProteinas()/receta_actual.getHidratos();
        calorias = (int) receta_actual.getCalorias();
        for(int j = 0; j < calorias_max+1;j++){
            if(j < calorias)
                matriz[i][j] = matriz[i-1][j];
            else{
                if(matriz[i-1][j] > (razon+matriz[i-1][j-calorias]))
                    matriz[i][j] = matriz[i-1][j];
                else
                    matriz[i][j] = razon+matriz[i-1][j-calorias];
            }
        }
    }
    
    int k = calorias_max;
    pair<string,receta> par;
    
    for(int i = num_recetas; i > 0; i--){
        if(matriz[i][k] != matriz[i-1][k]){
            code = "R" + to_string(i);
            receta_actual = rec[code];
            calorias = (int) receta_actual.getCalorias();
            k -= calorias;
            par.first = code;
            par.second = receta_actual;
            dieta.add(par);
        }
    }
}

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
    
    recetas rec,dieta;
    ingredientes ings;
    
    r >> rec;
    i >> ings;
    
    rec.calcularNutrientes(ings);
    
    recetas::const_iterator it = rec.cbegin();
    
    for(it; it != rec.cend(); ++it){
        cout << "Valores Nutricionales de la receta " << (*it) << " son:" << "\n Calorias: " << (*it).getCalorias() << " Fibra: " << (*it).getFibra() << " Proteinas: " << (*it).getProteinas() << " Hidratos: " << (*it).getHidratos() << " Grasas: " << (*it).getGrasas() << endl << endl;
    }
    
    calcular_dieta(rec,calorias_max,dieta);
    
    it = dieta.cbegin();
    float calorias_totales = 0, proteinas_totales = 0;
    
    cout << "Las recetas escogidas son:\n";
    
    for(it; it != dieta.cend(); ++it){
        cout << (*it) << endl;
        calorias_totales += (*it).getCalorias();
        proteinas_totales += (*it).getProteinas();
    }
    
    cout << "\nCalorias Totales:  " << calorias_totales << " Proteinas Totales:   " << proteinas_totales;
}