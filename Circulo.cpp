#include "Circulo.h"

void Circulo::leerCirculo(int r)
{
    string linea;
    ifstream Entrada("Circulo.txt", ios::in);
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
