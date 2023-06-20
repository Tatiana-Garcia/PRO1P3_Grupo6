#include "Cuadrado.h"

void Cuadrado::leerCuadrado(int a)
{
    int area = a*a, perimetro = 4*a; 
    string str5 = R"(\|       4\*a       \|      a\*a      \|)";
    string str = R"(\[a = \{a\}\])", 
        str2 = R"(\|    4\*\(\[\{a\}\]\)    \| \[\{a\}\] \^ \[\{2\}\] \|)", 
        str3 = R"(\|     \[\{4\*a\}\]     \|    \[\{a\*a\}\]    \|)", 
        str4 = R"([\{\}])";
    regex patron(str), patron2(str2), patron3(str3), patron4(str4), patron5(str5); 
    string linea, print =" a = "+ to_string(a)+" ";
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
                
                string print2 = "|    4*( "+to_string(a) + " )    |    "+to_string(a) + " ^ 2    |";
                string llaves = regex_replace(linea, patron2, print2);
                cout << llaves << endl; 

            }
            else if (regex_search(linea, matches, patron3)) { //linea para modificar desarrollo de area y perimetro con llaves de cuadrado 

                string print3 = "|       "+to_string(perimetro) + "      |     "+to_string(area) + "    |";
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
