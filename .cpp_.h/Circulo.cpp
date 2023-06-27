#include "Circulo.h"
string circulo_valid(int a, int variable)
{
	int cont = 0;
	int value = (int)a;
	while (value != 0) {
		value /= 10;
		cont++;
	}
	int x = cont;
	string s = "", p = "", c5 = "";

	for (size_t i = 0; i < x; i++)
	{
		if (x == 1)
		{
			s = "   " + to_string(a) + "   ";
			p = " " + to_string(a) + " ";
			c5 = "  " + to_string(a) + "  ";
		}
		else if (x == 2) {
			s = "   " + to_string(a) + "  ";
			p = " " + to_string(a);
			c5 = "  " + to_string(a) + " ";
		}
		else if (x == 3) {
			s = "  " + to_string(a) + "  ";
			p = to_string(a);
			c5 = " " + to_string(a) + " ";
		}
		else if (x == 4) {
			s = "  " + to_string(a) + " ";
			c5 = " " + to_string(a);
		}
		else if (x == 5) {
			s = " " + to_string(a) + " ";
			c5 = to_string(a);
		}
		else if (x == 6) {
			s = to_string(a) + " ";
		}
		else if (x == 7) {
			s = to_string(a);
		}
		else {
			s = " !Valid";
			break;
		}

	}
	if (variable == 2)
	{
		return s;
	}
	else if (variable == 1) {
		return p;
	}
	else {
		return c5;
	}
}
void Circulo::Dibujar(int r){
	int mult = round(3.14 * r), perimetro = round(r*3.14*2), area = round(3.14*r*r);
	string value_r = circulo_valid(r, 1), 
		value = circulo_valid(mult, 3), value2 = circulo_valid(perimetro, 2),
		value3 = circulo_valid(area, 2);

	string str = R"([\[\]])", 
		str2 = R"(\{r\*p\})", str3 = R"(\{p\*r\*r\})",
		str4 = R"(\{2\*p\*r\})", str5 = R"(\{D\*d\/2\})";

	regex patron(str), val(str2), val2(str3), patron2(str4), patron3(str5);

	string str_r = R"(\{r\})";
	regex patron_r(str_r);

	string str_pi = R"(\{p\})"; 
	regex patron_pi(str_pi); 

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
			smatch matches;
			if (regex_search(linea, matches, patron_r))
			{
				string values = regex_replace(linea, patron_r, value_r);
				cout << values << endl;
			}
			else if (regex_search(linea, matches, val)) {
				string values = regex_replace(linea, val, value); 
				cout << values << endl;
			}
			else if (regex_search(linea, matches, patron2)) {
				string values = regex_replace(linea, patron2, value2);
				cout << values << endl;
			}
			else if (regex_search(linea, matches, val2)) {
				string values = regex_replace(linea, val2, value3);
				cout << values << endl;
			}
			else {
				cout << linea << endl;
			}
		}
		Entrada.close();
	}
}