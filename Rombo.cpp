#include "Rombo.h"

void Rombo::leerRombo(int a, int d, int D){
    ifstream rombo;
    string texto;
    string str = R"(\a = \{a\})", str2 = R"(\{D\})", str3 = R"(\{d\})", str4 = R"([\{a\}\])", str5 = R"(\[\{\4\*a\}\])";
    string str6 = R"(\{D\*d\})", str7 = R"(\[\{D\*d\/2\}\])";
    regex patron(str), patron2(str2), patron3(str3), patron4(str4), patron5(str5), patron6(str6), patron7(str7);
    string print, reemplazo;

    rombo.open("Rombo.txt", ios::in);
    if (rombo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!rombo.eof()) {
        getline(rombo, texto);
        
        smatch matches;
        if (regex_search(texto, matches, patron)){
            print = "a = " + to_string(a);
            reemplazo = regex_replace(texto, patron, print);
            cout << reemplazo << endl;
        }
        else if (regex_search(texto, matches, patron2)) {
            reemplazo = regex_replace(texto, patron2, to_string(D));
            cout << reemplazo << endl;
        }
        else if (regex_search(texto, matches, patron3)) {
            reemplazo = regex_replace(texto, patron3, to_string(d));
            cout << reemplazo << endl;
        }else if (regex_search(texto, matches, patron4)) {
            print = " " + to_string(a) + " ";
            reemplazo = regex_replace(texto, patron4, print);
            cout << reemplazo << endl;
        }else if (regex_search(texto, matches, patron5)) {
            print = "  " + to_string(4*a) + "  ";
            reemplazo = regex_replace(texto, patron5, print);
            cout << reemplazo << endl;
        }else if (regex_search(texto, matches, patron6)) {
            print = " " + to_string(D * d) + " ";
            reemplazo = regex_replace(texto, patron6, print);
            cout << reemplazo << endl;
        }
        else if (regex_search(texto, matches, patron7)) {
            print = "  " + to_string((D * d)/2) + "  ";
            reemplazo = regex_replace(texto, patron7, print);
            cout << reemplazo << endl;
        }else {
            cout << texto << endl;
        }

    }

    rombo.close();

    /*for (int i = 0; i < texto.size(); i++) {
        if (texto[i] == 123 && texto[i + 1] == 97)
            texto[i] = a;
        if (texto[i] == 123 && texto[i + 1] == 68)
            texto[i] = D;
        if (texto[i] == 123 && texto[i + 1] == 100)
            texto[i] = d;
        if (texto[i] == 123 && texto[i + 1] == 52) {
            texto[i - 1] = 4 * a;
            for (int j = i; j < 7; j++) {
                if (texto[j] != 32)
                    texto[j] = (char)32;
            }
        }
        if (texto[i] == 123 && texto[i + 2] == 42) {
            texto[i - 1] = (char)32;
            texto[i] = D * d;
        }
        if (texto[i] == 123 && texto[i + 4] == 47) {
            texto[i] = (char)32;
            texto[i + 1] = (D * d) / 2;
            for (int j = i + 1; j < 6; j++) {
                if (texto[j] != 32)
                    texto[j] = (char)32;
            }
        }
    }*/
}
