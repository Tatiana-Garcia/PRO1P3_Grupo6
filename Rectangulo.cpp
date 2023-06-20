#include "Rectangulo.h"

void Rectangulo::leerRectangulo(int a, int b)
{
    string linea;
    ifstream Entrada("Rectangulo.txt", ios::in);
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
