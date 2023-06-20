#include "Cuadrado.h"

string validacion(int a, int variable)
{
    int cont = 0;
    int value = a; 
    while (value != 0) { 
        value /= 10; 
        cont++; 
    } 
    int x = cont;
    string s = "", p = "";

    for (size_t i = 0; i < x; i++)
    {
        if (x == 1)
        {
            s = "   " + to_string(a) + "   ";
            p = " " + to_string(a) + " ";
        }
        else if (x == 2) {
            s = "   " + to_string(a) + "  ";
            p = " " + to_string(a) ;
        }
        else if (x == 3) {
            s = "  " + to_string(a) + "  ";
            p =  to_string(a) ;
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
void Cuadrado::leerCuadrado(int a)
{
    int area = a*a, perimetro = 4*a; 
    string value = validacion(a, 1), value2 = validacion(area,2), value3 = validacion(perimetro,2);

    string str5 = R"(\|       4\*a       \|      a\*a      \|)";
    string str = R"(\[a = \{a\}\])", 
        str2 = R"(\|    4\*\(\[\{a\}\]\)    \| \[\{a\}\] \^ \[\{2\}\] \|)", 
        str3 = R"(\|     \[\{4\*a\}\]     \|    \[\{a\*a\}\]    \|)", 
        str4 = R"([\{\}])";
    regex patron(str), patron2(str2), patron3(str3), patron4(str4), patron5(str5); 

    string linea, print =" a = "+ value +" ";
    ifstream Entrada("Cuadrado.txt", ios::in);
    if (!Entrada) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    while (Entrada.is_open())
    {
        while (!Entrada.eof()) {
            getline(Entrada, linea);
            smatch matches;
            if (regex_search(linea,matches,patron))
            {
                string resultado = regex_replace(linea, patron, print); 
                cout << resultado << endl; 
            }
            else if (regex_search(linea, matches, patron2)) { //linea para modificar desarrollo de area y perimetro con llaves de cuadrado 
                
                string print2 = "|     4*("+ value + ")     |    "+value + " ^ 2    |";
                string llaves = regex_replace(linea, patron2, print2);
                cout << llaves << endl; 

            }
            else if (regex_search(linea, matches, patron3)) { //linea para modificar desarrollo de area y perimetro con llaves de cuadrado 

                string print3 = "|     "+value2+"     |    " + value3 + "    |";
                string llaves = regex_replace(linea, patron3, print3);
                cout << llaves << endl;

            }//faltara un if para las multiplicaciones
            else {
                cout << linea << endl;
            }
            
        }
        Entrada.close();
    }
}
void Cuadrado::Dibujar()
{
    
}

