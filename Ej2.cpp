#include <iostream>
#include "Pila/Pila.h"
using namespace std;

/*Escribir una función Reemplazar que tenga como argumentos una pila con tipo de elemento
int y dos valores int: viejo y nuevo de forma que, si el primer valor (viejo) aparece en algún
lugar de la pila, sea reemplazado por el segundo (nuevo)..*/

void Reemplazar(Pila<int> &pila, int viejo, int nuevo) {
    Pila<int> aux;

    while(!pila.esVacia()) {
        int valor = pila.pop();
        if (valor == viejo) {
            aux.push(nuevo);
        } else {
            aux.push(valor);
        }
    }

    while(!aux.esVacia()) {
        pila.push(aux.pop());
    }
}

void mostrarPila(Pila<int> &pila) {
    Pila<int> aux;
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        aux.push(valor);
    }
    cout << endl;

    //restaurando la pila original
    while(!aux.esVacia()) {
        pila.push(aux.pop());
    }
}

int main() {
    Pila<int> pila;
    int tamanio, viejo, nuevo, valor;

    cout << "\nIngrese la cantidad de elementos de la pila: " << endl;
    cin >> tamanio;

    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el valor " << i + 1 << ": " << endl;
        cin >> valor;
        pila.push(valor);
    }

    cout << "\nPila original: " << endl;
    mostrarPila(pila);

    cout << "Ingrese el valor a reemplazar: " << endl;
    cin >> viejo;
    cout << "Ingrese el nuevo valor: " << endl;
    cin >> nuevo;

    Reemplazar(pila, viejo, nuevo);
    cout << "\nPila con reemplazo: " << endl;
    mostrarPila(pila);


    return 0;
}
