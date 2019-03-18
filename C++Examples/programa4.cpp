/****************************************************************
/** Programador: Jordan Alexis Caraballo Vega    
/** Programa # 4
/**
/** Propósito: Este programa se encarga de evaluar un examen proveniente de un archivo.
/** Input: Se accesa a los archivos.
/** Output: Se calcula el total de incorrectas, se imprime un desgloce, se clasifica segun su porcentaje.
/**
/** Descripción de las variables
    tamano                         - cantidad de preguntas
    total@                         - indices para los arrays
    incorrectas                    - contestaciones incorrectas del estudiante
    contestacionesCorrectas        - char array con la lista de contestaciones correctas
    contestacionesEstudiantes      - char array multidimensional con la lista de contestaciones de los estudiantes
 /** Descripción de las funciones
    solicitudEnteros               - pide al usuario entero y valida segun la necesidad
    abrirArchivo                   - abre de forma general el archivo y devuelve char array
    analizar_imprimir              - compara el array de contestaciones con el de estudiantes e imprime

Posibles implementaciones: No se pudo realizar una funcion que permitiera procesar el char array multidimensional.
Apendice funcion: "abrirArchivoContestacionesEst()" (parte de abajo del archivo). Logra crear el archivo
multidimensional, pero accesar a el termino siendo imposible. Devolvia valores incorrectos.
/**************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//Prototipos
int  solicitudEnteros  (string);                         // funcion general para solicitar informacion
char abrirArchivo      (int , char [], string);          // funcion general para abrir archivos
void analizar_imprimir (int, int, char [], char [][20]); // funcion para analizar e imprimir resultados

int main()
{
    //#############################################################################

    cout << string(80, '*') << "\n\t\t  El siguiente programa evaluara su examen\n" << string(80, '*') << endl;
    // Informacion Referente Al Examen
    //Se intento pedirle al usuario la cantidad de preguntas pero produce problemas en los arrays. Debe ser constante.
    //int tamano = solicitudEnteros("Ingrese la cantidad de preguntas que contiene el examen: "); // cantidad de preguntas que tiene
    const int tamano = 20;
    char contestacionesCorrectas[tamano]; // array de contestaciones correctas
    contestacionesCorrectas[tamano] = abrirArchivo(tamano, contestacionesCorrectas, "Contestaciones Correctas");

    //*********************************************************************************//
    //                      Array Multidimesional de Estudiantes                       //
    //*********************************************************************************//

    int cantExamenes = solicitudEnteros("Ingrese la cantidad de examenes a corregir: "); // cantidad de examenes a corregir
    cout << "\n**  Analisis de Archivos de Estudiantes  **\n";

    //Ciclo para cada estudiante
    char contestacionesEstudiantes[cantExamenes][tamano]; // array multidimensional
    for (int estudiante=0; estudiante < cantExamenes; estudiante++)
    {
        ifstream contestacionesEst;
        string archivoEst;
        char contestacionEst;
        do
        {
            cout << "Ingrese Archivo de Contestaciones del Estudiante " << estudiante+1 << ": ";
            cin >> archivoEst;
            contestacionesEst.open(archivoEst.c_str());
            if (contestacionesEst.fail()) cout << "ERROR! No se pudo abrir el archivo. Intentelo nuevamente.\n";
        }
        while(contestacionesEst.fail());

        // Se produce array multidimensional
        int contadorContestaciones = 0;
        while (contestacionesEst >> contestacionEst)
        {
            contestacionesEstudiantes[estudiante][contadorContestaciones] = contestacionEst;
            contadorContestaciones++; //total de valores en el archivo, indice
        }

        contestacionesEst.close();
    }
    // Analizar resultados e imprimir
    analizar_imprimir(tamano, cantExamenes, contestacionesCorrectas, contestacionesEstudiantes);

    return 0;
}
//*********************************************************************************
//                               Area de Funciones
//*********************************************************************************
int solicitudEnteros(string objeto)
{
    int entero;
    cout << objeto;
    cin >> entero;
    while ((abs(entero) / static_cast<int>(entero)) != 1) // validacion: que no sea decimal o menor que 1
    {
        cin.clear();
        cout << "ERROR! La cantidad solo puede ser un entero. Vuelva a intentarlo.\n" << objeto;
        cin.ignore();
        cin >> entero;
    }
    return entero;
}
//#############################################################################
char abrirArchivo(int cantidadP, char listaContestaciones[], string objeto)
{
    ifstream contestaciones;
    string archivo;
    char contestacion;
    int total = 0;

    do // abre archivo y lo valida
    {
        cout << "Ingrese el Nombre del Archivo de " << objeto << ": ";
        cin >> archivo;
        cout << "\n**  Abriendo Archivo de " << objeto << "...  **\n";
        contestaciones.open(archivo.c_str());
        if (contestaciones.fail()) cout << "ERROR! No se pudo abrir el archivo. Intentelo nuevamente.\n\n";
    }
    while(contestaciones.fail());

    while (contestaciones >> contestacion)
    {
        listaContestaciones[total] = contestacion;
        total++; //total de valores en el archivo, indice
    }

    contestaciones.close();
    return listaContestaciones[cantidadP];
}
//#############################################################################
void analizar_imprimir(int cantidadPreguntas, int cantidadExamenes, char arrayCont[], char arrayContEst[][20])
{
    for (int estudiante=0; estudiante < cantidadExamenes; estudiante++)
    {
       //Tabular Resultados
        int incorrectas = 0; // cantidad total de contestaciones incorrectas (contador aditivo)
        cout << string(60, '-') << endl;
        cout << "Tabulacion de Resultados Estudiante " << estudiante + 1 << endl;
        cout << "Pregunta    "  << "Correcta    "      << "Estudiante\n";

        //Ciclo para cada pregunta
        for (int pregunta=0; pregunta < cantidadPreguntas; pregunta++)
        {
            if (arrayCont[pregunta] != arrayContEst[estudiante][pregunta])
            {
                cout << "   " << pregunta+1 << "\t\t" << arrayCont[pregunta] << "\t    " << arrayContEst[estudiante][pregunta] << endl;
                incorrectas++;
            }
        }
    //#############################################################################
        cout << "   " << "*" << "\t\t"  << "*" << "\t    " << "*" << endl;
        cout << "El estudiante obtuvo " << incorrectas     << " contestaciones incorrectas.\n";
        double porciento = ((static_cast<double>(cantidadPreguntas) - incorrectas) / cantidadPreguntas) * 100.0; // calcular porcentaje
        cout << "Esto para un "   << porciento << "%. ";
        if (porciento >= 70) cout << "El estudiante paso el examen.\n";
        else cout << "El estudiante no paso el examen.\n";
        cout << string(60, '-')   << endl;
    //#############################################################################
    }
}
//#####################################################################################
// No se esta utilizando
char abrirArchivoContestacionesEst(int tamano, int cantEst, char listaContestaciones[][20])
{
    //char listaContestaciones[cantEst][tamano];

    for (int i=0; i < cantEst; i++)
    {
        ifstream contestacionesEst;
        string archivo;
        char contestacionEst;
        do
        {
            cout << "Ingrese Nombre del Archivo de Contestaciones del estudiante " << i+1 << ": ";
            cin >> archivo;
            contestacionesEst.open(archivo.c_str());
            if (contestacionesEst.fail()) cout << "ERROR! No se pudo abrir el archivo. Intentelo nuevamente.\n";
        }
        while(contestacionesEst.fail());

        //***
        int total = 0;
        while (contestacionesEst >> contestacionEst)
        {
            listaContestaciones[i][total] = contestacionEst;
            total++; //total de valores en el archivo, indice
        }
    }
    return listaContestaciones[cantEst][tamano];
}

