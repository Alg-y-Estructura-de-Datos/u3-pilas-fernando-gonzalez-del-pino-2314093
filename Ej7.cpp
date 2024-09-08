#include <iostream>
#include "Pila/Pila.h"
using namespace std;

/*Escribe un programa en C++ que simule la funcionalidad de "deshacer" de un editor de texto
utilizando una pila. Cada vez que el usuario realiza una acción (por ejemplo, escribir una
palabra, borrar una palabra), se debe apilar esta acción. Cuando el usuario decide "deshacer"
una acción, se debe desapilar y mostrar cuál fue la última acción realizada*/

void realizarAccion(Pila<string> &acciones, Pila<string> &texto, string accion, string palabra) {
    string accionCompleta = accion + " " + palabra;
    acciones.push(accionCompleta);
    texto.push(palabra);
}

void deshacerAccion(Pila<string> &acciones, Pila<string> &texto) {
    if(!acciones.esVacia()) {
        string ultimaAccion = acciones.pop();
        texto.pop();
        cout << "\nDeshaciendo accion: " << ultimaAccion << endl;
    } else {
        cout << "\nNo hay acciones para deshacer" << endl;
    }
}

int main() {
    Pila<string> acciones;
    Pila<string> texto;
    string accion, palabra;
    int opcion;
    do {
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Realizar accion\n";
        cout << "2. Deshacer ultima accion\n";
        cout << "3. Mostrar texto\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese la accion (escribir/borrar): ";
            cin >> accion;
            cout << "Ingrese la palabra: ";
            cin >> palabra;
            realizarAccion(acciones, texto, accion, palabra);
            break;
            case 2:
                deshacerAccion(acciones, texto);
            break;
            case 3:
                cout << "\nTexto actual: " << endl;
                while (texto.esVacia() == 0) {
                    cout << texto.pop() << endl;
                }
            break;
            case 4:
                cout << "Saliendo...\n";
            break;
            default:
                cout << "Opcion no valida\n";
        }
    } while(opcion != 4);

    return 0;
}
