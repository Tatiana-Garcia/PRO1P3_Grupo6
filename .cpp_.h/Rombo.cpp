#include "Rombo.h"

string centrar3(int valor) {
    string mensaje;
    if (to_string(valor).size() == 1)
        mensaje = " " + to_string(valor) + " ";
    else if (to_string(valor).size() == 2)
        mensaje = " " + to_string(valor);
    else if (to_string(valor).size() == 3)
        mensaje = to_string(valor);
    return mensaje;
}

string centrar5(int valor) {
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

string centrar7(int valor) {
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

void Rombo::Dibujar(int a, int d, int D){
    ifstream rombo;
    string texto, print, reemplazo;
    string str = R"(\{a\})", str2 = R"(\{D\})", str3 = R"(\{d\})", str4 = R"(\{4\*a\})";
    string str5 = R"(\{D\*d\})", str6 = R"(\{D\*d\/2\})";
    regex patron(str), patron2(str2), patron3(str3), patron4(str4), patron5(str5), patron6(str6);

    rombo.open("Rombo.txt", ios::in);
    if (rombo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!rombo.eof()) {
        getline(rombo, texto);
        
        smatch matches;
        if (regex_search(texto, matches, patron)){
            print = centrar3(a);
            reemplazo = regex_replace(texto, patron, print);
            cout << reemplazo << endl;
        }
        else if (regex_search(texto, matches, patron2)) {
            print = centrar3(D);
            reemplazo = regex_replace(texto, patron2, print);
            if (regex_search(texto, matches, patron3)) {
                print = centrar3(d);
                reemplazo = regex_replace(reemplazo, patron3, print);
            }
            cout << reemplazo << endl;
        }else if (regex_search(texto, matches, patron4)) {
            print = centrar5(4 * a);
            reemplazo = regex_replace(texto, patron4, print);
            cout << reemplazo << endl;
        }else if (regex_search(texto, matches, patron5)) {
            print = centrar5(D * d);
            reemplazo = regex_replace(texto, patron5, print);
            cout << reemplazo << endl;
        }else if (regex_search(texto, matches, patron6)) {
            print = centrar7((D * d) / 2);
            reemplazo = regex_replace(texto, patron6, print);
            cout << reemplazo << endl;
        }else {
            cout << texto << endl;
        }
    }

    rombo.close();
}