#pragma once
class Funciones{
public:
	void lectura(string figura, char* argv[]) {
        switch (figura) {
        case "triangulo": {
            int a = atoi(argv[2]);
            int b = atoi(argv[3]);
            int c = atoi(argv[4]);
            int h = atoi(argv[5]);
            break;
        }//triangulo
        case "paralelogramo": {
            int a = atoi(argv[2]);
            int b = atoi(argv[3]);
            int h = atoi(argv[4]);
            break;
        }//paralelogramo
        case "rectangulo": {
            int a = atoi(argv[2]);
            int b = atoi(argv[3]);
            break;
        }
        case "cuadrado": {
            int a = atoi(argv[2]);
            break;
        }//cuadrado
        case "rombo": {
            int a = atoi(argv[2]);
            int d = atoi(argv[3]);
            int D = atoi(argv[4]);
            break;
        }
        case "cometa": {
            int a = atoi(argv[2]);
            int b = atoi(argv[3]);
            int d = atoi(argv[4]);
            int D = atoi(argv[5]);
            break;
        }
        case "trapecio": {
            int a = atoi(argv[2]);
            int b = atoi(argv[3]);
            int c = atoi(argv[4]);
            int B = atoi(argv[5]);
            int h = atoi(argv[6]);
            break;
        }
        case "circulo": {
            int r = atoi(argv[2]);
            break;
        }
        }
	}
};

