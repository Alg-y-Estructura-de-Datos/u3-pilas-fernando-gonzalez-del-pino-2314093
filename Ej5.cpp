#include <iostream>
#include "Pila/Pila.h"
using namespace std;

/*Crear un programa e implementar una función que reciba una pila de números enteros y
dado un número “n” por el usuario devuelva una nueva pila con la suma de cada uno de los
elementos de la pila original más el n dado por el usuario. Los elementos en la nueva pila
deben tener el orden que tenían en la pila original, y la pila original debe quedar en el mismo
estado a la inicial, mostrar por pantalla ambas pilas.
Por ejemplo, se tiene la pila de enteros [ 1, 2, 3, 6, 2] (tope es el número 2), y la función
sumarNro recibe como parámetros la pila y n=1 (devuelve la suma entre el número 1 y el
número recibido en cada posición de la pila original), la pila resultante debe ser [ 2, 3, 4, 7, 3]
(el tope es el número 3)*/

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

void suma(Pila<int> pila, int n) {
    Pila<int> aux;
    Pila<int> resultado;

    //desapilar los elementos para mantener el orden
    while (!pila.esVacia()) {
        int valor = pila.pop();
        aux.push(valor);
    }

    //crea la nueva pila con los valores sumados y restaura la pila original
    while (!aux.esVacia()) {
        int valor = aux.pop();
        resultado.push(valor + n);
        pila.push(valor);
    }

    cout << "\nResultado: " << endl;
    mostrarPila(resultado);
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

    cout << "Ingrese un numero entero: " << endl;
    cin >> n;

    cout << "\nPila original: " << endl;
    mostrarPila(pila);

    suma(pila, n);

    return 0;
}
