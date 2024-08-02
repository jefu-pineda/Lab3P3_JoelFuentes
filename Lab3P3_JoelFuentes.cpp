
#include <iostream>

using namespace std;

//metodos ejercicio 1
void generarTrianguloDePascal(int filas, int* array, int contadorFilas = 1) {
    int* copy = new int[filas];
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


//menu principal
void menu() {
    bool bandera = true;
    do {
        cout << "----- Menu -----" << endl;
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
            break;
        case 3:
            break;
        }
    } while (bandera);
}
int main()
{
    cout << "Buenas Tardes :)" << endl;
    menu();
}


