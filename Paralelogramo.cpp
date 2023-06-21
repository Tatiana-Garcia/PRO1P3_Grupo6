#include "Paralelogramo.h"
string paralelogramo_valid(int a, int variable)
{
    int cont = 0;
    int value = a;
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
        }
        else if (x == 2) {
            s = "   " + to_string(a) + "  ";
            p = " " + to_string(a);
        }
        else if (x == 3) {
            s = "  " + to_string(a) + "  ";
            p = to_string(a);
        }
        else if (x == 4) {
            s = "  " + to_string(a) + " ";
        }
        else if (x == 5) {
            s = " " + to_string(a) + " ";
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

    return (variable == 2) ? s : p;
}
void Paralelogramo::leerParalelogramo(int a, int b, int h)
{
    int perimetro = 2 * (a + b), suma = (a + b), area = (b * h);
    string value_a = paralelogramo_valid(a, 1), value_b = paralelogramo_valid(b, 1),
        value_h = paralelogramo_valid(h, 1),value = paralelogramo_valid(suma, 2), 
        value2 = paralelogramo_valid(perimetro, 2), value3 = paralelogramo_valid(area, 2);

    string str = R"([\[\]])", str2 = R"(\{2\*a\+b\})", str3 = R"( \{b\*h\} )", str4 = R"( \{a\+b\} )";

    regex patron(str), val2(str2), val3(str3), patron2(str4);  

    string str_a = R"(\{a\})", str_b = R"(\{b\})", str_h = R"(\{h\})";
    regex patron_a(str_a), patron_b(str_b), patron_h(str_h);

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
            smatch matches;
            if (regex_search(linea, matches, patron))
            {
                string llaves = regex_replace(linea, patron, " ");

                if (regex_search(linea, matches, patron_a)) ///linea de formulas editar 
                {
                    string values = regex_replace(llaves, patron_a, value_a);
                    string cadena = regex_replace(values, patron_b, value_b);
                    cout << cadena << endl;  
                }
                else if (regex_search(linea, matches, patron_b))
                {
                    string values = regex_replace(llaves, patron_b, value_b);
                    string cadena = regex_replace(values, patron_h, value_h);
                    values = regex_replace(cadena, val3, value3); 
                    cout << values << endl; 
                    
                }
                else if (regex_search(linea, matches, patron_h))
                {
                    string values = regex_replace(llaves, patron_h, value_h);
                    cout << values << endl;
                }
                else if (regex_search(llaves, matches, patron2)) 
                {
                    string values = regex_replace(llaves, patron2, value); 
                    cout << values << endl;
                }
                else if (regex_search(llaves, matches, val2))
                {
                    string values = regex_replace(llaves, val2, value2); 
                    cout << values << endl;
                }
                else {
                    cout << llaves << endl;
                }
            }
            else {
                cout << linea << endl;
            }
        }
        Entrada.close();
    }
}
