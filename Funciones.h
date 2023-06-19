#pragma once
#include <iostream>
#include <string>
using namespace std;

void lectura(string figura, char* argv[]) {
    if (figura== "triangulo"){
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int c = atoi(argv[4]);
        int h = atoi(argv[5]);
    }
    else if (figura == "paralelogramo") {
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int h = atoi(argv[4]);
    }else if (figura== "rectangulo"){
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
    }else if (figura == "cuadrado") {
        int a = atoi(argv[2]);
    }else if (figura == "rombo") {
        int a = atoi(argv[2]);
        int d = atoi(argv[3]);
        int D = atoi(argv[4]);
    }else if (figura == "cometa") {
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int d = atoi(argv[4]);
        int D = atoi(argv[5]);
    }else if (figura== "trapecio"){
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int c = atoi(argv[4]);
        int B = atoi(argv[5]);
        int h = atoi(argv[6]);
    }else if(figura == "circulo") {
        int r = atoi(argv[2]);
    }
}