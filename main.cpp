#include <iostream>
#include "ProgramacionDinamica.h"
using namespace std;
int main() {
    int op;
    do {
        cout << "\n=== Actividad 8 - PROGRAMACION DINAMICA ===\nNombre: Esteban Villagarcia\n\n1. Escaleras\n2. Cambio minimo\n0. Salir\nOpcion: ";
        if (!(cin >> op)) { cout << "Entrada invalida.\n"; return 1; }
        cout << endl;
        switch (op) {
            case 1: escaleras(); break;
            case 2: cambioMinimo(); break;
            case 0: cout << "Hasta luego.\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (op != 0);
    return 0;
}
