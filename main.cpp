#include "Nodo.h"
#include "ListaEnlazada.h"
#include <iostream>
#include <fstream>

using namespace std;

int num{0};
string nombreArch;

ListaEnlazada lista1;
ListaEnlazada lista2;
ListaEnlazada lista3(lista1, lista2);

std::ostream &operator<<(ostream &out, string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            int ia = str[i] - '0';
            cout << ia;
            if (num == 1)
            {
                lista1.agregar(ia);
            }
            else
            {
                lista2.agregar(ia);
            }
        }
        cout << " ";
    }
    cout << endl;
}

void CreadorLista(int _num)
{
    num = _num;
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
            cout << line;
        }
    }
    read.close();
}

int main()
{
    int opcion;
    do
    {
        cout << "\033[2J\033[1;1H";
        cout << "***** PROGRAMA DE MATRICES *****" << endl;
        cout << "1.Suma \n2.Resta \n3.Multiplicación \n4.Determinante \n5.Salir" << endl;
        cout << "Eliga una opción: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "\033[2J\033[1;1H";
            cout << "Suma De Matrices" << endl;
            CreadorLista(1);
            CreadorLista(2);
            lista1.imprimir();
            cout << "Matrices creadas exitosamente" << endl;
            break;
        case 2:
            cout << "\033[2J\033[1;1H";
            cout << "Resta De Matrices" << endl;
            CreadorLista(1);
            CreadorLista(2);
            cout << "Matrices creadas exitosamente" << endl;
            break;
        case 3:
            cout << "\033[2J\033[1;1H";
            cout << "Multiplicación De Matrices" << endl;
            CreadorLista(1);
            CreadorLista(2);
            cout << "Matrices creadas exitosamente" << endl;
            break;
        case 4:
            cout << "\033[2J\033[1;1H";
            cout << "Determinante De Matriz" << endl;
            CreadorLista(1);
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
void CosasExtra()
{

    /*char a[80];
    while (!read.eof())
    {
        read >> a;
        cout << a;
    }*/

    /* for (int i = 0; i < str.length(); i++)
    {
        out << str[i];
        if (str[i] != ' ' )
        {
            int ia = str[i]-'0';
            cout<<ia;
        }
    }*/
}