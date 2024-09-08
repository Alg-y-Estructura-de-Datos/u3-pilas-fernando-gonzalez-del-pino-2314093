#include <iostream>
#include "Pila/Pila.h"
using namespace std;

/*Escriba un programa que introduzca una palabra y utilice una pila para imprimir la misma
palabra invertida.*/

int main() {
    Pila<char> pila;
    char palabra;

    cout << "\nIngrese una palabra o frase (termine con un punto): " << endl;

    do {
        cin.get(palabra);
        if (palabra != '.') {
            pila.push(palabra);
        }
    } while (palabra != '.');

    cout << "\nPalabra o frase invertida: ";

    while (pila.esVacia() == false) {
        cout << pila.pop();
    }

    cout << endl;

    return 0;
}
