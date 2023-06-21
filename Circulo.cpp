#include "Circulo.h"

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

void Circulo::leerCirculo(int r)
{

	string linea;
	ifstream Entrada("Circulo.txt", ios::in);
	if (!Entrada) {
		cerr << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}
	double Perimetro = 2 * PI * r, area = PI * pow(r, 2),PerimetroCamino=PI*r;
	string resultado;

	stringstream ssPerimetro, ssArea, ssCaminoPerimetro;
	ssPerimetro << fixed << setprecision(4) << Perimetro;
	ssArea << fixed << setprecision(4) << area;
	ssCaminoPerimetro << fixed << setprecision(4) << PerimetroCamino;

	string rstring = to_string(r);
	string Pstring = ssPerimetro.str();
	string Astring = ssArea.str();
	string CaminoPerimetro = ssCaminoPerimetro.str();

	string Pfinal = Centrar(Pstring, 17);
	string Afinal = Centrar(Astring, 15);


	string patronA = R"(A1)";
	string patronB = R"(B1)";
	string patronC = R"(C1)";
	string patronD = R"(D1)";
	//string patronE = R"(E1)";
	string patron2 = R"(N)";
	string patron3 = R"(M)";

	regex regA(patronA);
	regex regB(patronB);
	regex regC(patronC);
	regex regD(patronD);
	//regex regE(patronE);
	regex reg2(patron2);
	regex reg3(patron3);
	smatch matches;

	string BFstring = Centrar(rstring, 5);
	string AFstring = Centrar(rstring, 4);
	string CFstring = Centrar(rstring, 6);
	string DFstring = Centrar(CaminoPerimetro, 9);
	//string EFstring = Centrar(rstring, 3);

	while (getline(Entrada, linea))
	{
		resultado = regex_replace(linea, regA, AFstring);
		resultado = regex_replace(resultado, regB, BFstring);
		resultado = regex_replace(resultado, regC, CFstring);
		resultado = regex_replace(resultado, regD, DFstring);
		//resultado = regex_replace(resultado, regE, EFstring);
		resultado = regex_replace(resultado, reg2, Pfinal);
		resultado = regex_replace(resultado, reg3, Afinal);
		cout << resultado << endl;
	}
	Entrada.close();
}