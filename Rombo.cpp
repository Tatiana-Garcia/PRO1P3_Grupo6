#include "Rombo.h"

void Rombo::leerRombo(int a, int d, int D){
    ifstream rombo;
    string texto;

    rombo.open("Rombo.txt", ios::in);
    if (rombo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!rombo.eof()) {
        getline(rombo, texto);
        for (int i = 0; i < texto.size(); i++){
            if (texto[i]==123 && texto[i+1]==97)
                texto[i] = a;
            if (texto[i] == 123 && texto[i + 1] == 68)
                texto[i] = D;
            if (texto[i] == 123 && texto[i + 1] == 100)
                texto[i] = d;
        }
        cout << texto << endl;
    }
}
