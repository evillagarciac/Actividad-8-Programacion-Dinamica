
#include <iostream>
#include <vector>
using namespace std;

// problema 1: formas de subir escaleras
void escaleras() {
    int escalones;

    cout << "Numero de escalones (0 a 92): ";
    cin >> escalones;

    // verificamos que el numero sea valido
    if (cin.fail() || escalones < 0 || escalones > 92) {
        cout << "Numero de escalones invalido.\n";
        return;
    }

    // guardamos las formas de llegar a cada escalon
    vector<unsigned long long> formas(escalones + 1, 0);

    // casos base
    formas[0] = 1;

    if (escalones >= 1) {
        formas[1] = 1;
    }

    // cada escalon depende de los dos anteriores
    for (int i = 2; i <= escalones; i++) {
        formas[i] = formas[i - 1] + formas[i - 2];
    }

    // mostramos la tabla dp
    cout << "\nEscalon: ";
    for (int i = 0; i <= escalones; i++) {
        cout << i << " ";
    }

    cout << "\nFormas:   ";
    for (int i = 0; i <= escalones; i++) {
        cout << formas[i] << " ";
    }

    cout << "\n\nTotal: " << formas[escalones] << " formas.\n";
}


// problema 2: cambio minimo de monedas
void cambioMinimo() {
    int cantidad, monto;

    cout << "Cantidad de denominaciones: ";
    cin >> cantidad;

    // verificamos la cantidad de monedas
    if (cin.fail() || cantidad <= 0 || cantidad > 10000) {
        cout << "Cantidad invalida.\n";
        return;
    }

    vector<int> monedas(cantidad);

    // ingresamos las denominaciones
    for (int i = 0; i < cantidad; i++) {
        cout << "Moneda " << i + 1 << ": ";
        cin >> monedas[i];

        if (cin.fail() || monedas[i] <= 0) {
            cout << "Moneda invalida.\n";
            return;
        }
    }

    cout << "Monto objetivo (0 a 100000): ";
    cin >> monto;

    if (cin.fail() || monto < 0 || monto > 100000) {
        cout << "Monto invalido.\n";
        return;
    }

    // usamos este valor para los montos imposibles
    const int infinito = 1000000;

    // minimo guarda la menor cantidad de monedas
    // ultimaMoneda guarda la moneda que usamos
    vector<int> minimo(monto + 1, infinito);
    vector<int> ultimaMoneda(monto + 1, -1);

    // para formar cero no necesitamos monedas
    minimo[0] = 0;

    // calculamos el minimo para cada monto
    for (int i = 1; i <= monto; i++) {

        // probamos cada denominacion
        for (int j = 0; j < cantidad; j++) {
            int moneda = monedas[j];

            // comprobamos si podemos usar esta moneda
            if (moneda <= i && minimo[i - moneda] != infinito) {

                int nuevaCantidad = minimo[i - moneda] + 1;

                // guardamos la mejor opcion
                if (nuevaCantidad < minimo[i]) {
                    minimo[i] = nuevaCantidad;
                    ultimaMoneda[i] = moneda;
                }
            }
        }
    }

    // mostramos la tabla dp
    cout << "\nMonto: ";
    for (int i = 0; i <= monto; i++) {
        cout << i << " ";
    }

    cout << "\nDP:    ";
    for (int i = 0; i <= monto; i++) {
        if (minimo[i] == infinito) {
            cout << "INF ";
        } else {
            cout << minimo[i] << " ";
        }
    }

    cout << "\n";

    // comprobamos si existe una solucion
    if (minimo[monto] == infinito) {
        cout << "\nNo existe una combinacion exacta.\n";
        return;
    }

    cout << "\nMinimo de monedas: " << minimo[monto];
    cout << "\nCombinacion: ";

    // recuperamos las monedas utilizadas
    int restante = monto;

    while (restante > 0) {
        int moneda = ultimaMoneda[restante];

        cout << moneda;
        restante = restante - moneda;

        if (restante > 0) {
            cout << " + ";
        }
    }
    if (monto == 0) {
        cout << "ninguna";
    }
    cout << "\n";
}
