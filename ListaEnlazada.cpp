#include "ListaEnlazada.h"
#include <iostream>
#include <fstream>

using namespace std;

ListaEnlazada::ListaEnlazada() : iniciolista(nullptr) {}

void ListaEnlazada::Probando()
{
    Nodo *actual = iniciolista->getSiguiente();
    for (size_t i = 0; i < getFilas(); i++)
    {
        cout << "[ " << actual->getValor() << " ]";
    }
}
int ListaEnlazada::getFilas()
{
    Nodo *filas = iniciolista;
    this->filas = 0;
    while (filas != nullptr)
    {
        this->filas++;
        filas = filas->getAbajo();
    }
    return this->filas;
}
int ListaEnlazada::getColumnas()
{

    Nodo *columnas = iniciolista;
    this->columnas = 0;
    while (columnas != nullptr)
    {
        this->columnas++;
        columnas = columnas->getSiguiente();
    }
    return this->columnas;
}
void ListaEnlazada::Suma(ListaEnlazada primera, ListaEnlazada segunda)
{
    primera.filas = 0;
    primera.columnas = 0;
    segunda.columnas = 0;
    segunda.filas = 0;
    if (primera.cantidadElementos() != segunda.cantidadElementos())
    {
        cout << "Elementos 1:" << primera.cantidadElementos() << "\nElementos 2:" << segunda.cantidadElementos() << endl;
        cout << "Operación No Valida Con Matrices" << std::endl;
        return;
    }
    Nodo *Lista1fil = primera.getInicioLista();
    Nodo *Lista1col = primera.getInicioLista();
    Nodo *Lista2fil = segunda.getInicioLista();
    Nodo *Lista2col = segunda.getInicioLista();

    for (size_t i = 0; i < primera.getFilas(); i++)
    {
        for (size_t j = 0; j < primera.getColumnas(); j++)
        {
            agregar((Lista1col->getValor()) + (Lista2col->getValor()), i);
            Lista1col = Lista1col->getSiguiente();
            Lista2col = Lista2col->getSiguiente();
        }
        Lista1fil = Lista1fil->getAbajo();
        Lista2fil = Lista2fil->getAbajo();
        Lista1col = Lista1fil;
        Lista2col = Lista2fil;
    }
    imprimir();
}

void ListaEnlazada::Resta(ListaEnlazada primera, ListaEnlazada segunda)
{
    primera.filas = 0;
    primera.columnas = 0;
    segunda.columnas = 0;
    segunda.filas = 0;
    if (primera.cantidadElementos() != segunda.cantidadElementos())
    {
        cout << "Elementos 1:" << primera.cantidadElementos() << "\nElementos 2:" << segunda.cantidadElementos() << endl;
        cout << "Operación No Valida Con Matrices" << std::endl;
        return;
    }
    Nodo *Lista1fil = primera.getInicioLista();
    Nodo *Lista1col = primera.getInicioLista();
    Nodo *Lista2fil = segunda.getInicioLista();
    Nodo *Lista2col = segunda.getInicioLista();

    for (size_t i = 0; i < primera.getFilas(); i++)
    {
        for (size_t j = 0; j < primera.getColumnas(); j++)
        {
            agregar((Lista1col->getValor()) - (Lista2col->getValor()), i);
            Lista1col = Lista1col->getSiguiente();
            Lista2col = Lista2col->getSiguiente();
        }
        Lista1fil = Lista1fil->getAbajo();
        Lista2fil = Lista2fil->getAbajo();
        Lista1col = Lista1fil;
        Lista2col = Lista2fil;
    }
    imprimir();
}

void ListaEnlazada::Multiplicacion(ListaEnlazada primera, ListaEnlazada segunda)
{
    primera.filas = 0;
    primera.columnas = 0;
    segunda.columnas = 0;
    segunda.filas = 0;
    if (primera.getColumnas() != segunda.getFilas() || segunda.getColumnas() != primera.getFilas())
    {
        cout << "Elementos 1:" << primera.cantidadElementos() << "\nElementos 2:" << segunda.cantidadElementos() << endl;
        cout << "Operación No Valida Con Matrices" << std::endl;
        return;
    }
    int Valor;
    Nodo *Lista1Fil = primera.getInicioLista();
    Nodo *Lista2Col = segunda.getInicioLista();
    Nodo *actual1 = primera.getInicioLista();
    Nodo *actual2 = segunda.getInicioLista();
    for (size_t i = 0; i < primera.getFilas(); i++)
    {
        for (size_t j = 0; j < segunda.getColumnas(); j++)
        {
            while (actual1 != nullptr || actual2 != nullptr)
            {

                int val1 = actual1->getValor();
                int val2 = actual2->getValor();
                cout << val2;
                Valor += val1 * val2;

                actual1 = actual1->getSiguiente();
                actual2 = actual2->getAbajo();
            }
            agregar(Valor, i);
            Valor = 0;
            Lista2Col = Lista2Col->getSiguiente();
            cout << Lista2Col->getValor();
            actual1 = Lista1Fil;
            actual2 = Lista2Col;
        }
        Lista1Fil = Lista1Fil->getAbajo();
        Lista2Col = segunda.getInicioLista();
    }
    imprimir();
}

Nodo *ListaEnlazada::getInicioLista()
{
    return this->iniciolista;
}

int ListaEnlazada::getDeterminante2()
{
    //Fila 1
    Nodo *a11 = this->iniciolista;
    Nodo *a12 = a11->getSiguiente();
    //Fila 2
    Nodo *a21 = a11->getAbajo();
    Nodo *a22 = a21->getSiguiente();

    return ((a11->getValor() * a22->getValor()) - (a12->getValor() * a21->getValor()));
}

int ListaEnlazada::getDeterminante3(Nodo *recibir)
{
    Nodo *a11;
    if (recibir != nullptr)
    {
        a11 = recibir;
    }
    else
    {
        a11 = this->iniciolista;
    }
    //Fila 1
    Nodo *a12 = a11->getSiguiente();
    Nodo *a13 = a12->getSiguiente();
    //Fila 2
    Nodo *a21 = a11->getAbajo();
    Nodo *a22 = a21->getSiguiente();
    Nodo *a23 = a22->getSiguiente();
    //Fila 3
    Nodo *a31 = a21->getAbajo();
    Nodo *a32 = a31->getSiguiente();
    Nodo *a33 = a32->getSiguiente();
    return (a11->getValor() * a22->getValor() * a33->getValor()) + (a12->getValor() * a23->getValor() * a31->getValor()) + (a13->getValor() * a21->getValor() * a32->getValor()) - (a13->getValor() * a22->getValor() * a31->getValor()) - (a12->getValor() * a21->getValor() * a33->getValor()) - (a11->getValor() * a23->getValor() * a32->getValor());
}

int ListaEnlazada::getDeterminante4(Nodo *recibir)
{
    Nodo *a11;
    if (recibir != nullptr)
    {
        a11 = recibir;
    }
    else
    {

        a11 = this->iniciolista;
    }

    //Fila 1
    Nodo *a12 = a11->getSiguiente();
    Nodo *a13 = a12->getSiguiente();
    Nodo *a14 = a13->getSiguiente();
    //Fila 2
    Nodo *a21 = a11->getAbajo();
    Nodo *a22 = a21->getSiguiente();
    Nodo *a23 = a22->getSiguiente();
    Nodo *a24 = a23->getSiguiente();
    //Fila 3
    Nodo *a31 = a21->getAbajo();
    Nodo *a32 = a31->getSiguiente();
    Nodo *a33 = a32->getSiguiente();
    Nodo *a34 = a33->getSiguiente();
    //Fila 4
    Nodo *a41 = a31->getAbajo();
    Nodo *a42 = a41->getSiguiente();
    Nodo *a43 = a42->getSiguiente();
    Nodo *a44 = a43->getSiguiente();
    Nodo *actual = a11;

    cout << a11->getValor();
    cout << a12->getValor();
    cout << a13->getValor();
    cout << a14->getValor() << std::endl;
    cout << a21->getValor();
    cout << a22->getValor();
    cout << a23->getValor();
    cout << a24->getValor() << std::endl;
    cout << a31->getValor();
    cout << a32->getValor();
    cout << a33->getValor();
    cout << a34->getValor() << std::endl;
    cout << a41->getValor();
    cout << a42->getValor();
    cout << a43->getValor();
    cout << a44->getValor() << std::endl;
    //Fila 1
    //int valor1 = getDeterminante3(a22) * a11->getValor();
    cout << "\n\n\n\n\n"
         << getDeterminante3(a22);
    //Fila 2
    a12->setAbajo(a32);
    a13->setAbajo(a33);
    a14->setAbajo(a34);
    // int valor2 = getDeterminante3(a12) * a21->getValor();
    //Fila 3
    a12->setAbajo(a22);
    a13->setAbajo(a23);
    a14->setAbajo(a24);
    //------------
    a22->setAbajo(a42);
    a23->setAbajo(a43);
    a24->setAbajo(a44);
    //int valor3 = getDeterminante3(a12) * a31->getValor();
    //Fila 4
    a12->setAbajo(a22);
    a13->setAbajo(a23);
    a14->setAbajo(a24);
    //------------
    a22->setAbajo(a32);
    a23->setAbajo(a33);
    a24->setAbajo(a34);
    //------------
    a32->setAbajo(nullptr);
    a33->setAbajo(nullptr);
    a34->setAbajo(nullptr);
    //  int valor4 = getDeterminante3(a12) * a41->getValor();
    //    return valor1 - valor2 + valor3 - valor4;
    return 1;
}

int ListaEnlazada::getDeterminante5(Nodo *recibir)
{
    //Fila 1
    Nodo *a11 = this->iniciolista;
    Nodo *a12 = a11->getSiguiente();
    Nodo *a13 = a12->getSiguiente();
    Nodo *a14 = a13->getSiguiente();
    Nodo *a15 = a14->getSiguiente();
    //Fila 2
    Nodo *a21 = a11->getAbajo();
    Nodo *a22 = a21->getSiguiente();
    Nodo *a23 = a22->getSiguiente();
    Nodo *a24 = a23->getSiguiente();
    Nodo *a25 = a24->getSiguiente();
    //Fila 3
    Nodo *a31 = a21->getAbajo();
    Nodo *a32 = a31->getSiguiente();
    Nodo *a33 = a32->getSiguiente();
    Nodo *a34 = a33->getSiguiente();
    Nodo *a35 = a34->getSiguiente();
    //Fila 4
    Nodo *a41 = a31->getAbajo();
    Nodo *a42 = a41->getSiguiente();
    Nodo *a43 = a42->getSiguiente();
    Nodo *a44 = a43->getSiguiente();
    Nodo *a45 = a44->getSiguiente();
    //Fila 5
    Nodo *a51 = a41->getAbajo();
    Nodo *a52 = a51->getSiguiente();
    Nodo *a53 = a52->getSiguiente();
    Nodo *a54 = a53->getSiguiente();
    Nodo *a55 = a54->getSiguiente();
}
void ListaEnlazada::imprimirDeterminante(int numero)
{
    string NomArch;
    cout << "Ingrese Nombre De Archivo De Texto" << endl;
    cin >> NomArch;

    ofstream myfile;
    myfile.open(NomArch);

    myfile << "Determinante De La Matriz Es: " << numero;
    myfile.close();
}
void ListaEnlazada::Determinante()
{
    cantidadElementos();
    if (filas == columnas)
    {
        switch (filas)
        {
        case 1:
            cout << "Determinante es: " << iniciolista->getValor() << std::endl;
            break;
        case 2:
            cout << "Determinante es: " << getDeterminante2() << std::endl;
            imprimirDeterminante(getDeterminante2());
            break;
        case 3:
            cout << "Determinante es: " << getDeterminante3(nullptr) << std::endl;
            imprimirDeterminante(getDeterminante3(0));
            break;
        case 4:
            cout << "Determinante es: " << getDeterminante4(nullptr) << std::endl;
            imprimirDeterminante(getDeterminante4(0));
            break;
        case 5:
            cout << "Determinante es: " << getDeterminante4(nullptr) << std::endl;
            imprimirDeterminante(getDeterminante5(0));
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
        return;
    }
    Nodo *actual = iniciolista;
    Nodo *actual1 = nullptr;

    while (cantFila != 0)
    {
        if (actual->getAbajo() == 0)
        {
            actual->setAbajo(nuevo);
            return;
        }
        actual1 = actual;
        actual = actual->getAbajo();
        cantFila--;
    }
    while (actual != nullptr)
    {
        if (actual1 == 0)
        {
            if (actual->getSiguiente() == 0)
            {
                actual->setSiguiente(nuevo);
                return;
            }
            actual = actual->getSiguiente();
        }
        else
        {
            if (actual->getSiguiente() == 0)
            {
                actual1->getSiguiente()->setAbajo(nuevo);
                actual->setSiguiente(nuevo);
                return;
            }
            actual1 = actual1->getSiguiente();
            actual = actual->getSiguiente();
        }
    }
}

void ListaEnlazada::imprimir()
{
    cantidadElementos();
    Nodo *fila = iniciolista;
    Nodo *columna = iniciolista;
    string NomArch;
    cout << "Ingrese Nombre De Archivo De Texto" << endl;
    cin >> NomArch;

    ofstream myfile;
    myfile.open(NomArch);
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            cout << "[" << columna->getValor() << "]" << std::endl;
            myfile << columna->getValor() << " ";
            columna = columna->getSiguiente();
        }
        myfile << " \n";
        fila = fila->getAbajo();
        columna = fila;
    }
    myfile.close();
}

int ListaEnlazada::cantidadElementos()
{
    Nodo *filas = iniciolista;
    this->filas = 0;
    while (filas != nullptr)
    {
        this->filas++;
        filas = filas->getAbajo();
    }
    Nodo *columnas = iniciolista;
    this->columnas = 0;
    while (columnas != nullptr)
    {
        this->columnas++;
        columnas = columnas->getSiguiente();
    }
    return this->filas + this->columnas;
}