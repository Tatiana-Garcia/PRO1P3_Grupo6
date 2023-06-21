#include "Triangulo.h"
string triangulo_valid(int a, int variable)
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
            c5 = to_string(a) ;
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
    if (variable ==2)
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
void Triangulo::leerTriangulo(int a, int b, int c, int h)
{
    int mult = (b * h), area = mult / 2, perimetro = a+b+c; 
    string value_a = triangulo_valid(a, 1), value_b = triangulo_valid(b, 1),
        value_c = triangulo_valid(c, 1), value_h = triangulo_valid(h, 1),
        value = triangulo_valid(mult, 3),
        value2 = triangulo_valid(perimetro, 2), value3 = triangulo_valid(area, 2);

    string str = R"([\[\]])", str2 = R"(\{a\+b\+c\})", str3 = R"(\{b\*h\})",
        str4 = R"(\{b\*h\/2\})";

    regex patron(str), val(str2), val2(str4), patron2(str3);

    string str_a = R"(\{a\})", str_b = R"(\{b\})", str_c = R"(\{c\})", str_h = R"(\{h\})"; 
    regex patron_a(str_a), patron_b(str_b), patron_c(str_c), patron_h(str_h); 

    string linea;
    ifstream Entrada("Triangulo.txt", ios::in);
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
                    values = regex_replace(cadena, patron_c, value_c);
                    cout << values << endl; 
                }
                else if (regex_search(linea, matches, patron_b)) 
                {
                    string values = regex_replace(llaves, patron_b, value_b);
                    cout << values << endl; 

                }
                else if (regex_search(linea, matches, patron_c))
                {
                    string values = regex_replace(llaves, patron_c, value_c);
                    cout << values << endl; 
                }
                else if (regex_search(linea, matches, patron_h))
                {
                    string values = regex_replace(llaves, patron_h, value_h); 
                    cout << values << endl; 
                }
                else if (regex_search(llaves, matches, val))
                {
                    string values = regex_replace(llaves, val, value2);
                    cout << values << endl;
                }
                else if (regex_search(llaves, matches, val2))
                {
                    string values = regex_replace(llaves, val2, value3);
                    cout << values << endl;
                }
                else {
                    cout << llaves << endl;
                }
            }
            else if (regex_search(linea, matches, patron_b))
            {
                string values = regex_replace(linea, patron_b, value_b);
                string cadena = regex_replace(values, patron_h, value_h);  
                cout << cadena << endl; 
            }
            else if (regex_search(linea, matches, patron2))
            {
                string values = regex_replace(linea, patron2, value);
                cout << values << endl; 
            }
            else {
                cout << linea << endl;
            }
        }
        Entrada.close();
    }
}
