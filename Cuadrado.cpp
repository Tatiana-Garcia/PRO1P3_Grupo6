#include "Cuadrado.h"

void Cuadrado::leerCuadrado(int a)
{
    string str = R"(\[a = \{a\}\])", str2 = R"([\[\]])", str3 = R"( a )", str4 = R"([\{\}])";
    regex patron(str), patron2(str2), patron3(str3), patron4(str4);  
    string linea, print =" a = "+ to_string(a)+" ", print2 = " ";
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
                string llaves = regex_replace(linea, patron2, print2); 
                string llaves2 = regex_replace(llaves, patron4, print2);
                string cadena = R"(\{a\})";
                regex letras(cadena); 
                string resultado = regex_replace(llaves2, letras, to_string(a)); 
                cout << resultado << endl;
            }//faltara un if para las multiplicaciones
            else {
                cout << linea << endl;
            }
            
        }
        Entrada.close();
    }
}
/*
            else if (regex_search(linea, matches, patron3)) {
                string ptr = R"(\|      4 \* a      \|     a \^ 2     \|)";
                string printing = "|     4 * "+ to_string(a) + "     |    "+ to_string(a) +" ^ 2    |";
                regex newlinea(ptr);
                string linea1 = regex_replace(linea, newlinea, printing);  
                cout << linea1 << endl; 
            }*/
void Cuadrado::Dibujar()
{
    
}
