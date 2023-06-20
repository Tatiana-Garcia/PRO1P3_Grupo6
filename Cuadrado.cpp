#include "Cuadrado.h"

void Cuadrado::leerCuadrado(int a)
{
    string linea, print = to_string(a); cout << a<<endl; 
    ifstream Entrada("Cuadrado.txt", ios::in);
    if (!Entrada) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    while (Entrada.is_open())
    {
        while (!Entrada.eof()) {
            getline(Entrada, linea);
            regex patron("\\[a = a]");
            string resultado = regex_replace(linea,patron,print);
            cout << resultado << endl; 
        }
        Entrada.close();
    }
}

void Cuadrado::Dibujar()
{
    
}
