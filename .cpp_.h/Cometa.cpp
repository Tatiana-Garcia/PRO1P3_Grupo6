#include "Cometa.h"
string cometa_valid(int a, int variable)
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
void Cometa::Dibujar(int a, int b, int d, int D)
{
    int area = 2 * (a + b), suma = (a + b), mult = (D * d), perimetro = mult / 2; 
    string value_a = cometa_valid(a, 1), value_b = cometa_valid(b, 1), 
        value_d = cometa_valid(d, 1), value_D = cometa_valid(D,1),
        value = cometa_valid(suma,2), value2 = cometa_valid(mult, 2), 
        value3 = cometa_valid(area,2), value4 = cometa_valid(perimetro, 2);

    string str = R"([\[\]])", str2 = R"( \{a\+b\} )", str3 = R"(\(\{D\*d\}\))", 
        str4 = R"(\{2\*a\+b\})", str5 = R"(\{D\*d\/2\})";

    regex patron(str), val(str2), val2(str3),patron2(str4), patron3(str5); 

    string str_a = R"(\{a\})", str_b = R"(\{b\})", str_D = R"(\{D\})", str_d = R"(\{d\})";  
    regex patron_a(str_a), patron_b(str_b), patron_D(str_D), patron_d(str_d); 
    
    string linea; 

    ifstream Entrada("Cometa.txt", ios::in);
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
                    values = regex_replace(cadena, patron_D, value_D); 
                    cadena = regex_replace(values, patron_d, value_d);; 
                    cout << cadena << endl;  
                }
                else if (regex_search(linea, matches, patron_b))   
                {
                    string values = regex_replace(llaves, patron_b, value_b); 
                    string cadena = regex_replace(values,val,value);
                    values = regex_replace(cadena, val2, value2); 
                    cout << values << endl;     
                }
                else if (regex_search(linea, matches, patron_D)) 
                {
                    string values = regex_replace(llaves, patron_D, value_D); 
                    cout << values << endl; 
                }
                else if (regex_search(linea, matches, patron_d)) 
                {
                    string values = regex_replace(llaves, patron_d, value_d); 
                    cout << values << endl;
                }
                else if (regex_search(linea, matches, patron2)) 
                {
                    
                    string values = regex_replace(llaves, patron2, value3); 
                    string cadena = regex_replace(values, patron3, value4);
                    cout << cadena << endl;
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
