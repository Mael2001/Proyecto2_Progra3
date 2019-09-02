#include "Nodo.h"

Nodo::Nodo() : valor(-1), siguiente(nullptr), abajo(nullptr) {}
Nodo::Nodo(int _valor, Nodo *_siguiente, Nodo *_abajo)
{
    setValor(_valor);
    setAbajo(_abajo);
    setSiguiente(_siguiente);
}
Nodo::~Nodo() {}

void Nodo::setValor(int _valor)
{
    this->valor = _valor;
}

int Nodo::getValor()
{
    return valor;
}

void Nodo::setSiguiente(Nodo *_siguiente)
{
    this->siguiente = _siguiente;
}

Nodo *Nodo::getSiguiente(void)
{
    return this->siguiente;
}
void Nodo::setAbajo(Nodo *_abajo)
{
    this->abajo = _abajo;
}
Nodo *Nodo::getAbajo(void)
{
    return this->abajo;
}