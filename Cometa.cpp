#include "Cometa.h"

void Cometa::leerCometa(int a, int b, int d, int D)
{
    string linea;
    ifstream Entrada("Cometa.txt", ios::in);
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
