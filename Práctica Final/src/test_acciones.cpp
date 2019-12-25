/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test_acciones.cpp
 * Author: francisco
 *
 * Created on 13 de diciembre de 2019, 12:31
 */

#include <cstdlib>
#include <iostream>
#include <acciones.h>
#include <fstream>
using namespace std;

/*
 * 
 */
int main() {
    acciones conjunto;
    ifstream f("datos/accion.txt");
    f>>conjunto;
    /*pair<string,unsigned char> p("coger", '1');
    pair<string,unsigned char> p2("cocer", '1');
    conjunto.insert(p);
    conjunto.insert(p2);*/
    
    cout << conjunto;
    
    cout << "La ariedad del primer elemento es " << conjunto.ariedad("cocer");
    
    return 0;
}

