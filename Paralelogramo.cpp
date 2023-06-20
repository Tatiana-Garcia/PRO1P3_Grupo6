#include "Paralelogramo.h"

void Paralelogramo::leerParalelogramo(int a, int b, int h)
{
    string linea;
    ifstream Entrada("Paralelogramo.txt", ios::in);
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
