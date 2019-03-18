/****************************************************************
/** Programador: Jordan Alexis Caraballo Vega   
                 Gustavo Torres Rodriguez       
/** Trabajo en grupo # 7
/**
/** Propósito: Este programa se encarga de imprimir los datos de un archivo dando pausa al pasar 24 lineas.
/** Input: Se accesa al archivo.
/** Output: Se imprimen las lineas.
/**
/** Descripción de las variables
    archivo   - este almacena el archivo
    solicitud - se le pide al usuario el nombre del archivo
    total     - contador aditivo para controlar el output
 /** Descripción de las funciones
    imprimir  - recibe e imprime el archivo segun las lineas deseadas
/**************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototipo
void imprimir(ifstream &);

int main()
{
    cout << string(60, '*') << "\nSaludos! Imprimire su archivo de texto.\n" << string(60, '*') << endl;

    // Declaracion de variables
    ifstream archivo;
    string   solicitud;

    // Declarar, validar y abrir archivo
    do
    {
        cout << "Ingrese el nombre de su archivo: ";
        getline(cin, solicitud);
        archivo.open(solicitud.c_str());
        if (archivo.fail()) cout << "ERROR! No se pudo abrir el archivo. Intentelo nuevamente.\n";
    }
    while(archivo.fail());

    // Imprimir
    imprimir(archivo);
    archivo.close(); // cerrar el archivo

    return 0;
}
//***************************************************************************************************
void imprimir(ifstream &archivo)
{
    string dato; // linea en el texto
    int total = 0; // contador aditivo
    getline(archivo, dato, '\n'); // toma linea del texto


    while (!(archivo.fail()))
    {
        cout << dato << endl; // imprime la linea
        total++; // contador aditivo

        if (total == 24)
        {
            cout << "\nPresione ENTER para continuar\n";
            cin.get(); // hacer la pausa
            total = 0; // para renovar la busqueda
        }
        getline(archivo, dato, '\n'); // renovar la nueva linea
    }
}
//***************************************************************************************************
