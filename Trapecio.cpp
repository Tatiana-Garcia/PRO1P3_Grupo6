#include "Trapecio.h"

void Trapecio::leerTrapecio(int a, int b, int c, int B, int h)
{
    string linea;
    ifstream Entrada("Trapecio.txt", ios::in);
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
