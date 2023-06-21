#include "Rectangulo.h"

string center3(int valor) {
	string mensaje;
	if (to_string(valor).size() == 1)
		mensaje = " " + to_string(valor) + " ";
	else if (to_string(valor).size() == 2)
		mensaje = " " + to_string(valor);
	else if (to_string(valor).size() == 3)
		mensaje = to_string(valor);
	return mensaje;
}

string center5(int valor) {
	string mensaje;
	if (to_string(valor).size() == 1)
		mensaje = "  " + to_string(valor) + "  ";
	else if (to_string(valor).size() == 2)
		mensaje = "  " + to_string(valor) + " ";
	else if (to_string(valor).size() == 3)
		mensaje = " " + to_string(valor) + " ";
	else if (to_string(valor).size() == 4)
		mensaje = " " + to_string(valor);
	else if (to_string(valor).size() == 5)
		mensaje = to_string(valor);
	return mensaje;
}

string center7(int valor) {
	string mensaje;
	if (to_string(valor).size() == 1)
		mensaje = "   " + to_string(valor) + "   ";
	else if (to_string(valor).size() == 2)
		mensaje = "   " + to_string(valor) + "  ";
	else if (to_string(valor).size() == 3)
		mensaje = "  " + to_string(valor) + "  ";
	else if (to_string(valor).size() == 4)
		mensaje = "  " + to_string(valor) + " ";
	else if (to_string(valor).size() == 5)
		mensaje = " " + to_string(valor) + " ";
	else if (to_string(valor).size() == 6)
		mensaje = " " + to_string(valor);
	else if (to_string(valor).size() == 7)
		mensaje = to_string(valor);
	return mensaje;
}

void Rectangulo::leerRectangulo(int a, int b){
    ifstream rectangulo("Rectangulo.txt", ios::in);

	string texto, print, reemplazo;
	string str = R"(\{a\})", str2 = R"(\{b\})", str3 = R"(\{b\+a\})", str4 = R"(\{2\*b\+a\})", str5 = R"(\{b\*a\})";
	regex patron(str), patron2(str2), patron3(str3), patron4(str4), patron5(str5);

    if (!rectangulo) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

	while (getline(rectangulo, texto)){
		smatch matches;
		if (regex_search(texto, matches, patron2)) {//{b}
			print = center3(b);
			reemplazo = regex_replace(texto, patron2, print);
			if (regex_search(texto, matches, patron)) {//{a}
				print = center3(a);
				reemplazo = regex_replace(reemplazo, patron, print);
			}
			if (regex_search(texto, matches, patron4)) {//{2*(b+a)}
				print = center7(2 * (b + a));
				reemplazo = regex_replace(reemplazo, patron4, print);
			}
			cout << reemplazo << endl;
		}

		else if (regex_search(texto, matches, patron)) {//{a}
			print = center3(a);
			reemplazo = regex_replace(texto, patron, print);
			cout << reemplazo << endl;
		}else if (regex_search(texto, matches, patron3)) {//{b+a}
			print = center5(b+a);
			reemplazo = regex_replace(texto, patron3, print);
			cout << reemplazo << endl;
		}else if (regex_search(texto, matches, patron5)) {//{b*a}
			print = center5(b * a);
			reemplazo = regex_replace(texto, patron5, print);
			cout << reemplazo << endl;
		}else {
			cout << texto << endl;
		}
	}

	rectangulo.close();
}
