#include "Trapecio.h"

string validar3(int valor) {
    string mensaje;
    if (to_string(valor).size() == 1)
        mensaje = " " + to_string(valor) + " ";
    else if (to_string(valor).size() == 2)
        mensaje = " " + to_string(valor);
    else if (to_string(valor).size() == 3)
        mensaje = to_string(valor);
    return mensaje;
}

string validar5(int valor) {
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

string validar9(int valor) {
    string mensaje;
    if (to_string(valor).size() == 1)
        mensaje = "    " + to_string(valor) + "    ";
    else if (to_string(valor).size() == 2)
        mensaje = "    " + to_string(valor) + "   ";
    else if (to_string(valor).size() == 3)
        mensaje = "   " + to_string(valor) + "   ";
    else if (to_string(valor).size() == 4)
        mensaje = "   " + to_string(valor) + "  ";
    else if (to_string(valor).size() == 5)
        mensaje = "  " + to_string(valor) + "  ";
    else if (to_string(valor).size() == 6)
        mensaje = "  " + to_string(valor) + " ";
    else if (to_string(valor).size() == 7)
        mensaje = " " + to_string(valor) + " ";
    else if (to_string(valor).size() == 8)
        mensaje = " " + to_string(valor);
    else if (to_string(valor).size() == 9)
        mensaje = to_string(valor);
    return mensaje;
}

/*string centrar11(int valor) {
    if (to_string(valor).size() == 1)
        return "     " + to_string(valor) + "     ";
    else if (to_string(valor).size() == 2)
        return "     " + to_string(valor) + "    ";
    else if (to_string(valor).size() == 3)
        return "    " + to_string(valor) + "    ";
    else if (to_string(valor).size() == 4)
        return "    " + to_string(valor) + "   ";
    else if (to_string(valor).size() == 5)
        return "   " + to_string(valor) + "   ";
    else if (to_string(valor).size() == 6)
        return "   " + to_string(valor) + "  ";
    else if (to_string(valor).size() == 7)
        return "  " + to_string(valor) + "  ";
    else if (to_string(valor).size() == 8)
        return "  " + to_string(valor) + " ";
    else if (to_string(valor).size() == 9)
        return " " + to_string(valor) + " ";
    else if (to_string(valor).size() == 10)
        return " " + to_string(valor);
    else if (to_string(valor).size() == 11)
        return to_string(valor);
}*/

void Trapecio::leerTrapecio(int a, int b, int c, int B, int h) {
    ifstream trapecio;
    string texto, print, reemplazo;
    string str = R"(\{a\})", str2 = R"(\{b\})", str3 = R"(\{c\})", str4 = R"(\{h\})", str5 = R"(\{B\})";
    string str6 = R"(\{B\+b\+a\+c\})", str7 = R"(\{B\+b\})", str8 = R"(\{B\+b\+h\/2\})";
    regex patron(str), patron2(str2), patron3(str3), patron4(str4), patron5(str5), patron6(str6), patron7(str7), patron8(str8);

    trapecio.open("Trapecio.txt", ios::in);
    if (trapecio.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!trapecio.eof()) {
        getline(trapecio, texto);

        smatch matches;
        if (regex_search(texto, matches, patron)) {//{a}
            print = validar3(a);
            reemplazo = regex_replace(texto, patron, print);
            if (regex_search(texto, matches, patron2)) {//{b}
                print = validar3(b);
                reemplazo = regex_replace(reemplazo, patron2, print);
            }
            if (regex_search(texto, matches, patron3)) {//{c}
                print = validar3(c);
                reemplazo = regex_replace(reemplazo, patron3, print);
            }
            if (regex_search(texto, matches, patron4)) {//{h}
                print = validar3(h);
                reemplazo = regex_replace(reemplazo, patron4, print);
            }
            if (regex_search(texto, matches, patron5)) {//{B}
                print = validar3(B);
                reemplazo = regex_replace(reemplazo, patron5, print);
            }
            cout << reemplazo << endl;
        }

        /*else if (regex_search(texto, matches, patron2)) {//{b}
            print = validar3(b);
            reemplazo = regex_replace(texto, patron2, print);
        }else if (regex_search(texto, matches, patron4)) {//{h}
            print = validar3(h);
            reemplazo = regex_replace(texto, patron4, print);
        }*/

        else if (regex_search(texto, matches, patron5)) {//{B}
            print = validar3(B);
            reemplazo = regex_replace(texto, patron5, print);
            if (regex_search(texto, matches, patron6)) {//{B+b+a+c}
                print = validar9(B + b + a + c);
                reemplazo = regex_replace(reemplazo, patron6, print);
            }
            if (regex_search(texto, matches, patron2)) {//{b}
                print = validar3(b);
                reemplazo = regex_replace(reemplazo, patron2, print);
            }
            if (regex_search(texto, matches, patron4)) {//{h}
                print = validar3(h);
                reemplazo = regex_replace(reemplazo, patron4, print);
            }
            cout << reemplazo << endl;
        }

        else if (regex_search(texto, matches, patron7)) {//{B+b}
            print = validar5(B + b);
            reemplazo = regex_replace(texto, patron7, print);
            if (regex_search(texto, matches, patron4)) {//{h}
                print = validar3(h);
                reemplazo = regex_replace(reemplazo, patron4, print);
            }
            cout << reemplazo << endl;
        }

        else if (regex_search(texto, matches, patron8)) {//{B+b+h/2}
            print = validar9((B + b + h) / 2);
            reemplazo = regex_replace(texto, patron8, print);
            cout << reemplazo << endl;
        }

        else {
            cout << texto << endl;
        }
    }

    trapecio.close();
}