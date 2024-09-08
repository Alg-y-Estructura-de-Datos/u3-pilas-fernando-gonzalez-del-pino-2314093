#include <iostream>
#include "Pila/Pila.h"
using namespace std;

/*Implementa un programa en C++ que utilice una pila para simular el movimiento de una
persona en un edificio. Cada vez que la persona entra en un área del edificio (por ejemplo,
"Recepción", "Sala de Reuniones", "Oficina"), se debe apilar el nombre del área. Cuando la
persona sale del área, se debe desapilar el nombre. Al final del día, el programa debe mostrar
el recorrido de la persona en orden inverso al que lo hizo (último lugar visitado al primero).*/

void desplazamiento(Pila<string> &pila, const string movimiento, const string area) {
    if (movimiento == "entra") {
        pila.push(area);
    } else if (movimiento == "sale") {
        if (!pila.esVacia()) {
            pila.pop();
        }
    } else {
        cout << "No se puede salir de un área si no se ha ingresado previamente." << endl;
    }
}

void mostrarRecorridoInverso(Pila<string> &pila) {
    cout << "\nRecorrido inverso: " << endl;
    while (!pila.esVacia()) {
        cout << pila.pop() << endl;
    }
}

int main() {
    Pila<string> pila;
    string movimiento, area;
    char continuar;

    do {
        cout << "\nIngrese el movimiento (entra/sale): ";
        cin >> movimiento;
        if (movimiento == "entra") {
            cout << "Ingrese el area: ";
            cin.ignore();
            getline(cin, area);
        } else {
            area = "";
        }
        desplazamiento(pila, movimiento, area);

        cout << "Desea continuar? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    mostrarRecorridoInverso(pila);

    return 0;
}
