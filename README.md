# Actividad 8 - Programación Dinámica

Dos problemas en C++: conteo de formas de subir escaleras y cambio mínimo de monedas ilimitadas.

## Como commpilar:

```bash
g++ -std=c++17 main.cpp ProgramacionDinamica.cpp -o actividad7
```

## Ejecutar

```bash
./actividad7
```

En Windows, ejecutar `actividad7.exe`. El menú permite ingresar datos y muestra la tabla DP.

## Pruebas sugeridas

- Escaleras: 0 → 1; 4 → 5; 6 → 13; 7 → 21.
- Monedas 1, 4, 6 y monto 8 → 2 monedas (4+4).
- Monedas 1, 3, 4 y monto 6 → 2 monedas (3+3).
- Monedas 4, 6 y monto 7 → no existe solución.

Nota: el conteo de escaleras admite N de 0 a 92 para evitar desbordamiento de `unsigned long long`. El monto está limitado a 100000 para evitar consumos excesivos de memoria y salida.
