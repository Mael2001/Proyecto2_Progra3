#include "ListaEnlazada.h"
#include <iostream>
#include <fstream>

using namespace std;

ListaEnlazada::ListaEnlazada() : iniciolista(nullptr), primera(NULL), segunda(0) {}
ListaEnlazada::ListaEnlazada(ListaEnlazada primera, ListaEnlazada segunda)
{
    this->primera = &primera;
    this->segunda = &segunda;
}

void ListaEnlazada::Resta()
{
    if (primera->cantidadElementos() != segunda->cantidadElementos())
    {
        cout << "Operación No Valida Con Matrices" << std::endl;
    }
    else
    {
        Nodo *Lista1 = primera->getIncioLista();
        Nodo *Lista2 = segunda->getIncioLista();
    }
}

void ListaEnlazada::Suma()
{
    if (primera->cantidadElementos() != segunda->cantidadElementos())
    {
        cout << "Operación No Valida Con Matrices" << std::endl;
    }
    else
    {
        Nodo *Lista1 = primera->getIncioLista();
        Nodo *Lista2 = segunda->getIncioLista();
    }
}

void ListaEnlazada::Multiplicacion()
{
    if (primera->columnas != segunda->filas)
    {
        cout << "Operación No Valida Con Matrices" << std::endl;
    }
    else
    {
        Nodo *Lista1 = primera->getIncioLista();
        Nodo *Lista2 = segunda->getIncioLista();
    }
}

int getDeterminante2()
{
}

int getDeterminante3()
{
}

int getDeterminante4()
{
}
int getDeterminante5()
{
}
void ListaEnlazada::Determinante()
{
    if (filas == columnas)
    {
        switch (filas)
        {
        case 1:
            cout << "Determinante es: " << iniciolista->getValor() << std::endl;
            break;
        case 2:
            cout << "Determinante es: " << getDeterminante2() << std::endl;
            break;
        case 3:
            cout << "Determinante es: " << getDeterminante3() << std::endl;
            break;
        case 4:
            cout << "Determinante es: " << getDeterminante3() << std::endl;
            break;
        case 5:
            cout << "Determinante es: " << getDeterminante4() << std::endl;
            break;

        default:
            break;
        }
    }
    else
    {
        cout << "Matriz No Es Cuadrada" << std::endl;
    }
}

bool ListaEnlazada::estaVacia()
{
    return iniciolista == nullptr;
}

void ListaEnlazada::agregar(int _valor, int cantFila)
{
    Nodo *nuevo = new Nodo(_valor, nullptr, nullptr);

    if (estaVacia())
    {
        iniciolista = nuevo;
    }
    else
    {
        Nodo *actual = iniciolista;
        while (actual != nullptr)
        {
            if (nuevo->getValor() < iniciolista->getValor())
            {
                nuevo->setSiguiente(iniciolista);
                iniciolista = nuevo;
                return;
            }
            else if (actual->getSiguiente() == nullptr)
            {
                actual->setSiguiente(nuevo);
                return;
            }
            else if (nuevo->getValor() < actual->getSiguiente()->getValor())
            {
                nuevo->setSiguiente(actual->getSiguiente());
                actual->setSiguiente(nuevo);
                return;
            }
            actual = actual->getSiguiente();
        }
    }
}

void ListaEnlazada::imprimir()
{
    Nodo *actual = iniciolista;
    string NomArch;
    cout << "Ingrese Nombre De Archivo De Texto" << endl;
    cin >> NomArch;

    ofstream myfile;
    myfile.open(NomArch);
    myfile << "Writing this to a file.\n";
    do
    {
        cout << "[" << actual->getValor() << "]" << std::endl;
        myfile << actual->getValor();
        actual = actual->getSiguiente();
    } while (actual != nullptr);
    myfile.close();
}

int ListaEnlazada::cantidadElementos()
{
    Nodo *filas = iniciolista;
    while (filas != nullptr)
    {
        this->filas++;
        filas = filas->getAbajo();
    }
    Nodo *columnas = iniciolista;
    while (columnas != nullptr)
    {
        this->columnas++;
        columnas = columnas->getSiguiente();
    }
}
Nodo *ListaEnlazada::getIncioLista()
{
    return this->iniciolista;
}
