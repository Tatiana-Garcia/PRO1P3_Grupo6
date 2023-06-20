#include <iostream>
#include <stdlib.h>
#include "Funciones.h"
using namespace std; 

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "spanish");
    string figura = argv[1];   
    lectura(figura, argv);  
}