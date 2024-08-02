
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//metodos ejercicio 1
void generarTrianguloDePascal(int filas, int* array, int contadorFilas = 1) {
    int* copy = new int[filas];//se crea una copia del array para operar con esta y asi no alterar el array original
    if (contadorFilas == filas) {
        delete[] array;
        delete[] copy;
        return;
    }
    else {
        array[0] = 1;
        array[contadorFilas-1] = 1;
        for (int i = 0; i < filas; i++)
        {
            copy[i] = array[i];
        }

        for (int i = 1; i < contadorFilas-1; i++)
        {
            array[i] = copy[i - 1] + copy[i];
        }
        array[contadorFilas - 1] = 1;
        for (int i = 0; i < contadorFilas; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        generarTrianguloDePascal(filas, array, ++contadorFilas);
    }
}

void trianguloPascal() {
    cout << "---Triangulo de Pascal---" << endl;
    cout << "Ingrese la cantidad de filas a generar: ";
    int filas; cin >> filas;
    int* array = new int[filas];
    generarTrianguloDePascal(filas, array);
}

//metodos ejercicio 2
int* generarPuntos(int* array, int tamanno) {
    for (int i = 0; i < tamanno; i++)
    {
        array[i] = rand() % 20 + 1;
    }
    return array;
}

void imprimirArray(int* array, int tamanno) {
    cout << "[ ";
    for (int i = 0; i < tamanno; i++)
    {
        cout << array[i] << " ";
    }
    cout << " ]";
}

int generarEcuacion(int x1, int y1, int x2, int y2) {
    return (y2 - y1) / (x2 - x1);
}

void rectaPorDosPuntos() {
    cout << "----Generar Ecuacion----" << endl;
    cout << "Ingrese la cantidad de puntos a generar: ";
    int cantidad; cin >> cantidad;
    int* puntosX = new int[cantidad];
    int* puntosY = new int[cantidad];
    puntosX = generarPuntos(puntosX, cantidad);
    puntosY = generarPuntos(puntosY, cantidad);
    cout << "Puntos en X generados: ";
    imprimirArray(puntosX, cantidad);
    cout << endl;
    cout << "Puntos en Y generados: ";
    imprimirArray(puntosY, cantidad);

    cout << "\nIngrese la posicion del punto #1: ";
    int punto1; cin >> punto1;
    cout << endl;
    if (punto1 > cantidad) {
        cout << "Punto 1 no es valido..." << endl;
        return;
    }
    else {
        cout << "Ingrese la posicion punto #2: ";
        int punto2; cin >> punto2;
        if (punto2 > cantidad) {
            cout << "Punto 2 no es valido..." << endl;
            return;
        }
        else {
            cout << "P1(" << puntosX[punto1 - 1] << "," << puntosY[punto1 - 1] << ")" << endl;
            cout << "P2(" << puntosX[punto2 - 1] << "," << puntosY[punto2 - 1] << ")" << endl;
            int ecuacion = generarEcuacion(puntosX[punto1 - 1], puntosY[punto1 - 1], puntosX[punto2 - 1], puntosY[punto2 - 1]);
            cout << "La ecuacion de la recta que pasa por los 2 puntos es: " << ecuacion;
        }
    }
}

void operacionesDeNumeros() {
    bool bandera = true;
    do {
        cout << "---Operaciones con Numeros---" << endl;
        cout << "1) Ecuacion de la recta" << endl;
        cout << "2) Suma de Vectores y Norma";
        cout << "0) Salir" << endl;
        cout << "Ingrese su opcion: ";
        int opcion; cin >> opcion;
        switch (opcion) {
        case 1:
            rectaPorDosPuntos();
            break;
        case 2:
            break;
        case 0:
            cout << "Volviendo..." << endl;
            bandera = false;
            break;
        default:
            break;
        }
    } while (bandera);
}

//menu principal
void menu() {
    bool bandera = true;
    do {
        cout << "\n----- Menu -----" << endl;
        cout << "1) Triangulo de Pascal" << endl;
        cout << "2) Operaciones con Numeros" << endl;
        cout << "0) Salir" << endl;
        cout << "Ingrese su opcion: ";
        int opcion; cin >> opcion;
        switch (opcion) {
        case 1:
            trianguloPascal();
            break;
        case 2:
            rectaPorDosPuntos();
            break;
        case 3:
            break;
        }
    } while (bandera);
}
int main()
{
    srand(time(NULL));
    cout << "Buenas Tardes :)" << endl;
    menu();
}


