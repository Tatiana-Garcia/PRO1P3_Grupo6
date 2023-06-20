#pragma once
#include <iostream>
#include <string>
#include "Circulo.h"
#include "Cometa.h"
#include "Cuadrado.h"
#include "Paralelogramo.h"
#include "Rectangulo.h"
#include "Rombo.h"
#include "Trapecio.h"
#include "Triangulo.h"
#include <fstream>
using namespace std;

void Menu() {
    ifstream menu;
    string texto;

    menu.open("Menu.txt", ios::in);
    if (menu.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!menu.eof()) {
        getline(menu, texto);
        cout << texto << endl;
    }
}
void lectura(string figura, char* argv[]) {
    if (figura== "triangulo"){
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int c = atoi(argv[4]);
        int h = atoi(argv[5]);
        Triangulo::leerTriangulo(a, b, c, h);
    }
    else if (figura == "paralelogramo") {
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int h = atoi(argv[4]);
        Paralelogramo::leerParalelogramo(a, b, h);

    }else if (figura== "rectangulo"){
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        Rectangulo::leerRectangulo(a,b);

    }else if (figura == "cuadrado") {
        int a = atoi(argv[2]);
        Cuadrado::leerCuadrado(a);

    }else if (figura == "rombo") {
        int a = atoi(argv[2]);
        int d = atoi(argv[3]);
        int D = atoi(argv[4]);
        Rombo::leerRombo(a, d, D); 

    }else if (figura == "cometa") {
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int d = atoi(argv[4]);
        int D = atoi(argv[5]);
        Cometa::leerCometa(a,b, d, D);

    }else if (figura== "trapecio"){
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int c = atoi(argv[4]);
        int B = atoi(argv[5]);
        int h = atoi(argv[6]);  
        Trapecio::leerTrapecio(a, b, c, B, h);

    }else if(figura == "circulo") {
        int r = atoi(argv[2]);
        Circulo::leerCirculo(r);
    }else {
        //hay que poner el menu
        Menu();
    }
}
