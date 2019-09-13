#include "Nodo.h"
#include "ListaEnlazada.h"
#include <iostream>
#include <fstream>
#include "string.h"
using namespace std;


ListaEnlazada lista1;
ListaEnlazada lista2;
ListaEnlazada lista3;



int main()
{
    int opcion;
    do
    {
        cout << "***** PROGRAMA DE MATRICES *****" << endl;
        cout << "1.Suma \n2.Resta \n3.Multiplicación \n4.Determinante \n5.Salir" << endl;
        cout << "Eliga una opción: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "\033[2J\033[1;1H";
            cout << "Suma De Matrices" << endl;
            lista1.CreadorLista();
            lista2.CreadorLista();
            lista3.Suma(lista1, lista2);
            cout << "Matrices creadas exitosamente" << endl;
            break;
        case 2:
            cout << "\033[2J\033[1;1H";
            cout << "Resta De Matrices" << endl;
            lista1.CreadorLista();
            lista2.CreadorLista();
            lista3.Resta(lista1, lista2);
            cout << "Matrices creadas exitosamente" << endl;
            break;
        case 3:
            cout << "\033[2J\033[1;1H";
            cout << "Multiplicación De Matrices" << endl;
            lista1.CreadorLista();
            lista2.CreadorLista();
            lista3.Multiplicacion(lista1, lista2);
            cout << "Matrices creadas exitosamente" << endl;
            break;
        case 4:
            cout << "\033[2J\033[1;1H";
            cout << "Determinante De Matriz" << endl;
            lista3.CreadorLista();
            lista3.Determinante();
            break;
        case 5:
            cout << "\033[2J\033[1;1H";
            cout << "***** FIN DEL PROGRAMA *****" << endl;
            break;
        default:
            cout << "\033[2J\033[1;1H";
            cout << "Eliga una opción del rango del 1-5";
            break;
        };
    } while (opcion != 5);
    return 0;
}