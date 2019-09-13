#include "ListaEnlazada.h"
#include <iostream>
#include <fstream>

using namespace std;

int cantFila{0};
string numero{" "};
int num{0};
string nombreArch;

ListaEnlazada::ListaEnlazada() : iniciolista(nullptr) {}

void ListaEnlazada::CreadorLista()
{
    cout << "Ingrese el nombre del archivo donde esta la matriz:\n";
    cin >> nombreArch;
    ifstream read(nombreArch.c_str());
    if (!read.is_open())
    {
        cout << "No se pudo abrir el Archivo: " << nombreArch << endl;
        return;
    }
    else
    {
        cout << "Su Matriz es:" << endl;
        string line;
        while (getline(read, line))
        {
            int pos{0};
            int ia{0};
            while (pos != line.length())
            {
                while (line[pos] != ' ')
                {
                    numero.append(string(1, line[pos]));
                    if (line[pos + 1] == ' ')
                    {
                        ia = atoi(numero.c_str());
                        cout << ia << " ";
                        numero = " ";
                    }
                    pos++;
                }
                pos++;
            }
            cantFila++;
            cout << endl;
        }
        cantFila = 0;
        if (invalida())
        {
            cout << "Esta Lista tiene un formato invalido" << endl;
        }
    }
    read.close();
}

bool ListaEnlazada::invalida()
{
    Nodo *fila = iniciolista;
    Nodo *columna = iniciolista;
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t i = 0; i < columnas; i++)
        {
            columna = columna->getSiguiente();
            if (columna == nullptr)
            {
                return true;
            }
        }
        fila = fila->getAbajo();
        columna = fila;
    }
    return false;
}
void ListaEnlazada::Probando()
{
    Nodo *col = iniciolista;
    Nodo *fil = iniciolista;
    while (col != nullptr)
    {
        while (fil != nullptr)
        {
            cout << fil->getValor();
            fil = fil->getAbajo();
        }
        cout << endl;
        col = col->getSiguiente();
        fil = col;
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
    if (primera.getColumnas() != segunda.getFilas())
    {
        cout << "Elementos 1:" << primera.cantidadElementos() << "\nElementos 2:" << segunda.cantidadElementos() << endl;
        cout << "Operación No Valida Con Matrices" << std::endl;
        return;
    }
    int Valor{0};
    Nodo *Lista1Fil = primera.getInicioLista();
    Nodo *Lista2Col = segunda.getInicioLista();
    Nodo *actual1 = primera.getInicioLista();
    Nodo *actual2 = segunda.getInicioLista();
    for (size_t i = 0; i < 2; i++)
    {
        Lista2Col = segunda.getInicioLista();
        for (size_t j = 0; j < 2; j++)
        {
            while (actual1 != nullptr || actual2 != nullptr)
            {

                int val1 = actual1->getValor();
                int val2 = actual2->getValor();
                Valor += val1 * val2;

                actual1 = actual1->getSiguiente();
                actual2 = actual2->getAbajo();
            }
            agregar(Valor, i);
            Valor = 0;
            Lista2Col = Lista2Col->getSiguiente();
            if (Lista2Col == nullptr)
            {
                break;
            }

            actual1 = Lista1Fil;
            actual2 = Lista2Col;
        }
        Lista1Fil = Lista1Fil->getAbajo();
        Lista2Col = segunda.getInicioLista();
        actual1 = Lista1Fil;
        actual2 = Lista2Col;
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

    //Fila 1
    int valor1 = getDeterminante3(a22) * a11->getValor();
    //Fila 2
    a12->setAbajo(a32);
    a13->setAbajo(a33);
    a14->setAbajo(a34);
    int valor2 = getDeterminante3(a12) * a21->getValor();
    //Fila 3
    a12->setAbajo(a22);
    a13->setAbajo(a23);
    a14->setAbajo(a24);
    //------------
    a22->setAbajo(a42);
    a23->setAbajo(a43);
    a24->setAbajo(a44);
    int valor3 = getDeterminante3(a12) * a31->getValor();
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
    int valor4 = getDeterminante3(a12) * a41->getValor();
    return valor1 - valor2 + valor3 - valor4;
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

    //Fila 1
    int valor1 = getDeterminante3(a22) * a11->getValor();
    //Fila 2
    a12->setAbajo(a32);
    a13->setAbajo(a33);
    a14->setAbajo(a34);
    int valor2 = getDeterminante3(a12) * a21->getValor();
    //Fila 3
    a12->setAbajo(a22);
    a13->setAbajo(a23);
    a14->setAbajo(a24);
    //------------
    a22->setAbajo(a42);
    a23->setAbajo(a43);
    a24->setAbajo(a44);
    int valor3 = getDeterminante3(a12) * a31->getValor();
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
    int valor4 = getDeterminante3(a12) * a41->getValor();
    //Fila 5
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
    return valor1 - valor2 + valor3 - valor4;
}
int ListaEnlazada::getDeterminante6(Nodo *as) {}
int ListaEnlazada::getDeterminante7(Nodo *) {}
int ListaEnlazada::getDeterminante8(Nodo *) {}
int ListaEnlazada::getDeterminante9(Nodo *) {}
int ListaEnlazada::getDeterminante10(Nodo *) {}
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
    int val{0};
    cantidadElementos();
    if (filas == columnas)
    {
        switch (filas)
        {
        case 1:
            cout << "Determinante es: " << iniciolista->getValor() << std::endl;
            break;
        case 2:
            val = getDeterminante2();
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
            break;
        case 3:
            val = getDeterminante3(nullptr);
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
            break;
        case 4:
            val = getDeterminante4(nullptr);
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
            break;
        case 5:
            val = getDeterminante5(nullptr);
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
            break;
        case 6:
            val = getDeterminante6(nullptr);
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
            break;
        case 7:
            val = getDeterminante7(nullptr);
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
            break;
        case 8:
            val = getDeterminante8(nullptr);
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
            break;
        case 9:
            val = getDeterminante9(nullptr);
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
            break;
        case 10:
            val = getDeterminante10(nullptr);
            cout << "Determinante es: " << val << std::endl;
            imprimirDeterminante(val);
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