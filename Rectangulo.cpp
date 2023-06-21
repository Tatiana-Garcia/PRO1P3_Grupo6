#include "Rectangulo.h"
static void setespacio(int cantidad, string& texto) {
	for (size_t i = 0; i < cantidad; i++)
	{
		texto += " ";
	}
}


static string Centrar(string perimetro, int original) {
	string temp = "";
	int length = perimetro.length();
	int espaciado = original - length;

	if (espaciado % 2 == 0)
	{
		int derecho = espaciado / 2;
		setespacio(derecho, temp);
		temp += perimetro;
		setespacio(derecho, temp);
	}
	else {
		if (espaciado < 4) {
			int derecho = espaciado / 2;
			setespacio(derecho, temp);
			temp += perimetro;
			setespacio(derecho + 1, temp);
			return temp;
		}
		int derecho = espaciado / 2;
		setespacio(derecho, temp);
		temp += perimetro;
		setespacio(derecho + 1, temp);
	}
	return temp;
}

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
