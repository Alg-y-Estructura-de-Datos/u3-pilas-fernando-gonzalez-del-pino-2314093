#include <iostream>
#include "Pila/Pila.h"
using namespace std;

/*Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una pila y pedir también un número entero "n". Luego crear una función que
reciba una pila y un número entero “n”, si el "n" se encuentra en una de las posiciones de la
pila, devuelve la suma de los números en cada una de las posiciones de la pila hasta llegar a
"n" (sin incluir a n), si el número "n" no se encuentra en la pila, la función devuelve la suma de
todos los elementos de la pila. Imprimir primero la pila antes de sumar sus elementos*/

int suma(Pila<int> pila, int n) {
    Pila<int> aux;
    int suma = 0;
    bool encontrado = false;

    while (!pila.esVacia()) {
        int valor = pila.pop();
        if (valor == n) {
            encontrado = true;
            aux.push(valor);
            break;
        } else {
            suma += valor;
            aux.push(valor);
        }
    }
    while (!aux.esVacia()) {
        pila.push(aux.pop());
    }

    if (!encontrado) {
        int suma = 0;
        while (!pila.esVacia()) {
            int valor = pila.pop();
            suma += valor;
            aux.push(valor);
        }
        while (!aux.esVacia()) {
            pila.push(aux.pop());
        }
        return suma;
    }

    return suma;
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
    cout << "\nIngrese un numero entero n: " << endl;
    cin >> n;

    cout << "\nLa suma de los elementos de la pila hasta el primer " << n << " es: " << suma(pila, n) << endl;


    return 0;
}