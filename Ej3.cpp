#include <iostream>
#include "Pila/Pila.h"
using namespace std;

/*Crear una función que reciba una pila por referencia y un número. La función debe sacar la
primera ocurrencia de dicho valor de la pila sino se repite el valor en la pila, de lo contrario
debe eliminar todos los valores repetidos a excepción de la primera ocurrencia. Si el valor no
se encuentra en la pila muestra un mensaje indicando que no pertenece a la pila. Imprimir la
pila al final para verificar si hubo o no modificaciones.*/

void repetidos(Pila<int> &pila, int n) {
    Pila<int> aux;
    bool encontrado = false;
    int contador = 0;

    while (!pila.esVacia()) {
        int valor = pila.pop();
        if (valor == n) {
            if (!encontrado) {
                encontrado = true;
                aux.push(valor);
            }
            contador++;
        }
        if (valor != n) {
            aux.push(valor);
        }
    }

    while (!aux.esVacia()) {
        int auxValor = aux.pop();
        if (encontrado && contador == 1 && auxValor == n) {

        } else {
            pila.push(auxValor);
        }
    }

    if (contador == 0) {
        cout << "El valor no pertenece a la pila." << endl;
    }
}

void mostrarPila(Pila<int> &pila) {
    Pila<int> aux;
    while(!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        aux.push(valor);
    }
    cout << endl;

    while(!aux.esVacia()) {
        pila.push(aux.pop());
    }
}

int main() {
    Pila<int> pila;
    int tamanio, valor, n;

    cout << "\nIngrese la cantidad de elementos de la pila: " << endl;
    cin >> tamanio;

    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el valor " << i + 1 << ": " << endl;
        cin >> valor;
        pila.push(valor);
    }

    cout << "\nPila original: " << endl;
    mostrarPila(pila);

    cout << "Ingrese la ocurrencia: " << endl;
    cin >> valor;

    repetidos(pila, valor);

    cout << "\nPila modificada: " << endl;
    mostrarPila(pila);

    return 0;
}
