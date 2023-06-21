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
	int Perimetro = 2 * (a+b),area = a*b, PerimetroCamino = a+b;
	string resultado;

	string astring = to_string(a);
	string bstring = to_string(b);
	string Pstring = to_string(Perimetro);;
	string Astring = to_string(area);;
	string CaminoPerimetrostring = to_string(PerimetroCamino);

	string patronA1 = R"(a1)";
	string patronA2 = R"(a2)";
	string patronA3 = R"(a3)";
	string patronB1 = R"(b1)";
	string patronB2 = R"(b2)";
	string patronB3 = R"(b3)";
	string patronB4 = R"(b4)";
	string patronB5 = R"(b5)";
	string patronB6 = R"(b6)";

	regex regA1(patronA1);
	regex regA2(patronA2);
	regex regA3(patronA3);
	regex regB1(patronB1);
	regex regB2(patronB2);
	regex regB3(patronB3);
	regex regB4(patronB4);
	regex regB5(patronB5);
	regex regB6(patronB6);


	string A1string = Centrar(astring, 4);
	string B1string = Centrar(bstring, 4);
	string A2string = Centrar(astring, 4);
	string B2string = Centrar(bstring, 4);
	string A3string = Centrar(astring, 7);
	string B3string = Centrar(bstring, 7);
	string B4string = Centrar(CaminoPerimetrostring, 5);
	string B5string = Centrar(Pstring, 15);
	string B6string = Centrar(Astring, 17);


	while (getline(Entrada, linea))
	{
		resultado = regex_replace(linea, regA1, A1string);
		resultado = regex_replace(resultado, regA2, A2string);
		resultado = regex_replace(resultado, regA3, A3string);
		resultado = regex_replace(resultado, regB1, B1string);
		resultado = regex_replace(resultado, regB2, B2string);
		resultado = regex_replace(resultado, regB3, B3string);
		resultado = regex_replace(resultado, regB4, B4string);
		resultado = regex_replace(resultado, regB5, B5string);
		resultado = regex_replace(resultado, regB6, B6string);

		cout << resultado << endl;
	}
	Entrada.close();
}
