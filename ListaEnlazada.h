#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Nodo.h"

class ListaEnlazada
{
private:
    Nodo *iniciolista;
    int cantidadElementos();
    bool estaVacia(void);
    ListaEnlazada* primera;
    ListaEnlazada* segunda;
    int filas{0}, columnas{0};

public:
    ListaEnlazada();
    ListaEnlazada(ListaEnlazada,ListaEnlazada);
    Nodo* getIncioLista();
    void agregar(int nodo);
    void imprimir(void);
    void Suma();
    void Resta();
    void Multiplicacion();
    void Determinante();
};

#endif
