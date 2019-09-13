#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Nodo.h"

class ListaEnlazada
{
private:
    Nodo *iniciolista;
    int cantidadElementos();
    bool estaVacia(void);
    int filas{0}, columnas{0};
    void imprimirDeterminante(int);
    void linkear();
    int getDeterminante2();
    int getDeterminante3(Nodo*);
    int getDeterminante4(Nodo*);
    int getDeterminante5(Nodo*);

public:
    ListaEnlazada();
    Nodo *getInicioLista();
    void agregar(int, int);
    void imprimir(void);
    void Suma(ListaEnlazada, ListaEnlazada);
    void Resta(ListaEnlazada, ListaEnlazada);
    void Multiplicacion(ListaEnlazada, ListaEnlazada);
    void Determinante();
    int getFilas();
    int getColumnas();
};

#endif
