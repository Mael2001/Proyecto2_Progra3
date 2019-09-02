#include "ListaEnlazada.h"
#include <iostream>

using std::cout;

ListaEnlazada::ListaEnlazada() : iniciolista(nullptr), primera(NULL), segunda(0) {}
ListaEnlazada::ListaEnlazada(ListaEnlazada primera, ListaEnlazada segunda)
{
    this->primera = &primera;
    this->segunda = &segunda;
}
bool ListaEnlazada::estaVacia()
{
    return iniciolista == nullptr;
}

void ListaEnlazada::agregar(int _valor)
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
    while (actual != nullptr)
    {
        cout << "[" << actual->getValor() << "]" << std::endl;
        actual = actual->getSiguiente();
    }
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
