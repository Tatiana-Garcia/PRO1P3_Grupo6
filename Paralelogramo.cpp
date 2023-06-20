#include "Paralelogramo.h"

void Paralelogramo::leerParalelogramo(int a, int b, int h)
{
    string linea, print = "a = "+to_string(a);
    ifstream Entrada("paralelogramo_01.txt", ios::in);
    if (!Entrada) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    while (Entrada.is_open())
    {
        while (!Entrada.eof()) {
            getline(Entrada, linea);
            regex patron("{aaa}");
            string resultado = regex_replace(linea, patron, print);
            cout << resultado << endl;
        }
        Entrada.close();
    }
}
