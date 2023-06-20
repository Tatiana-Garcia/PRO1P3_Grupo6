#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Funciones.h"
using namespace std; 

int main(int argc, char* argv[]){
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string figura = (argc<=1)? "que-so" :argv[1];
    lectura(figura, argv);  
}