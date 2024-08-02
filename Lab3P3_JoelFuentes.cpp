
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

//metodos ejercicio 1
void generarTrianguloDePascal(int filas, int* array, int contadorFilas = 1) {
    int* copy = new int[filas];//se crea una copia del array para operar con esta y asi no alterar el array original
    if (contadorFilas == filas+1) {
        delete[] array;
        delete[] copy;//en el case base se libera la memoria
        return;
    }
    else {
        array[0] = 1;
        for (int i = 0; i < filas; i++)
        {
            copy[i] = array[i];
        }

        for (int i = 1; i < contadorFilas; i++)
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

void trianguloPascal() {//ejercicio 1
    cout << "---Triangulo de Pascal---" << endl;
    cout << "Ingrese la cantidad de filas a generar: ";
    int filas; cin >> filas;
    int* array = new int[filas];
    generarTrianguloDePascal(filas, array);
}

//metodos ejercicio 2
int* generarPuntos(int* array, int tamanno) {//genera los puntos usando rand
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

//metodos ejercicio 2 submenu 1
double generarEcuacion(double x1, double x2, double y1, double y2) {//formula para generar la pendiente
    if (y2 - y1 == 0) {
        cout << "Division sobre 0 :/" << endl;
    }
    else {
        return ((y2 - y1) / (x2 - x1));
    }
}

void rectaPorDosPuntos() {//submenu opcion 1
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
    if (punto1 > cantidad || punto1 < 1) {
        cout << "Punto 1 no es valido..." << endl;
        return;
    }
    else {
        cout << "Ingrese la posicion punto #2: ";
        int punto2; cin >> punto2;
        if (punto2 > cantidad || punto2 < 1) {
            cout << "Punto 2 no es valido..." << endl;
            return;
        }
        else {
            cout << "P1(" << puntosX[punto1 - 1] << "," << puntosY[punto1 - 1] << ")" << endl;
            cout << "P2(" << puntosX[punto2 - 1] << "," << puntosY[punto2 - 1] << ")" << endl;
            double ecuacion = generarEcuacion(puntosX[punto1 - 1], puntosX[punto2 - 1], puntosY[punto1 - 1], puntosY[punto2 - 1]);
            cout << "La ecuacion de la recta que pasa por los 2 puntos es: " << ecuacion;
            delete[] puntosX;
            delete[] puntosY;
        }
    }
}

//metodos ejercicio 2 opcion 2
int* sumarVectores(int* vector1, int* vector2, int tamanno) {
    int* suma = new int[tamanno];
    for (int i = 0; i < tamanno; i++)
    {
        suma[i] = vector1[i] + vector2[i];
    }
    return suma;
}

double calcularNorma(int* vector, int tamanno) {
    int norma = 0;
    for (int i = 0; i < tamanno; i++)
    {
        norma += vector[i] ^ 2;
    }
    norma = sqrt(norma);
    return norma;
}

void vectores() {
    cout << "----Sumar Vectores----" << endl;
    cout << "Ingrese en que dimension de Rn esta el vector: ";
    int cantidad; cin >> cantidad;
    int* vector1 = new int[cantidad];
    int* vector2 = new int[cantidad];
    vector1 = generarPuntos(vector1, cantidad);
    vector2 = generarPuntos(vector2, cantidad);
    cout << "Vector 1: ";
    imprimirArray(vector1, cantidad);
    cout << endl;
    cout << "Vector 2: ";
    imprimirArray(vector2, cantidad);

    int* vectorSuma = new int[cantidad];
    vectorSuma = sumarVectores(vector1, vector2, cantidad);
    cout << endl;
    cout << "La suma de los vectores da el vector: ";
    imprimirArray(vectorSuma, cantidad);
    cout << endl;
    double norma = calcularNorma(vectorSuma, cantidad);
    cout << "La norma del vector suma es: " << norma;

    delete[] vector1;
    delete[] vector2;
    delete[] vectorSuma;
}
void operacionesDeNumeros() {
    bool bandera = true;
    do {
        cout << "\n---Operaciones con Numeros---" << endl;
        cout << "1) Ecuacion de la recta" << endl;
        cout << "2) Suma de Vectores y Norma" << endl;
        cout << "0) Volver" << endl;
        cout << "Ingrese su opcion: ";
        int opcion; cin >> opcion;
        switch (opcion) {
        case 1:
            rectaPorDosPuntos();
            break;
        case 2:
            vectores();
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
            operacionesDeNumeros();
            break;
        case 0:
            bandera = false;
            break;
        }
    } while (bandera);
    cout << "\nGracias por probar el programa :)";
}

int main()
{
    srand(time(NULL));
    cout << "Buenas Tardes :)" << endl;
    menu();
    cout << "DaZu the goat" << endl;
}


