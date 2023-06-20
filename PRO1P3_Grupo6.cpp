#include <iostream>
#include <stdlib.h>
#include "Funciones.h"
using namespace std; 

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "spanish");
    string figura = (argc<1)?argv[1]:"que-so";
    lectura(figura, argv);  
}