#include "Cuadrado.h"

void Cuadrado::leerCuadrado(int a)
{
    string linea;
    ifstream Entrada("Cuadrado.txt", ios::in);
    if (!Entrada) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    while (Entrada.is_open())
    {
        while (!Entrada.eof()) {
            getline(Entrada, linea);
            cout << linea << endl; 
        }
        Entrada.close();
    }
}

void Cuadrado::Dibujar()
{
    
}
