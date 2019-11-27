/****************************************************************
/** Programador: Jordan Alexis Caraballo Vega    
/** 
/** Programa # 5
/**
/** Propósito: Este programa se encarga de validar que un password cumpla con ciertos requisitos.
/** Input: El usuario ingresa el password.
/** Output: Se indica si el password es valido
/**
/** Descripción de las variables
    solicitud    - verifica si el usuario desea verificar otra contrasena
    contrasena   - variable de tipo string que toma la contrasena
    tamano       - tamano de contrasena
    verificacion - toma el resultado de la funcion validacion para verificar
 /** Descripción de las funciones
    validacion   - se encarga de verificar que la contrasena cumpla con los parametros
/**************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

//Prototipos
bool validacion(string, int);

//####################################################################################
int main()
{
    char solicitud; // variable que se utiliza al final para verificar si desea otra contrasena
    // se solicita la contrasena al usuario
    do
    {
    string contrasena;
    cout << string(60, '*') << "\n    Verificador de contrasenas segun nuestras exigencias\n" << string(60, '*') << endl;
    cout << "Ingrese su contrasena: ";
    cin  >> contrasena;

    int  tamano       = contrasena.size(); // tamano de la contrasena
    bool verificacion = validacion(contrasena, tamano); // llama a la funcion para validar

    // si es falso se continua repitiendo hasta tener la contrasena valida
    while (verificacion == false)
    {
        cout << "Ingrese su contrasena: ";
        cin  >> contrasena;
        tamano       = contrasena.size();
        verificacion = validacion(contrasena, tamano);
    }
    cout << "Contrasena valida.\n";

    // En caso de querer ingresar otro
    cout << "Desea verificar alguna otra contrasena? (Y/N): ";
    cin >> solicitud;
    solicitud = toupper(solicitud); // para no mortificarle la vida al usuario
    while (solicitud != 'Y' && solicitud != 'N') // validacion: si no es Y o N
    {
        cin.clear();
        cout << "ERROR! Solo puede ingresar (Y/N).Ingreselo nuevamente.\nDesea verificar alguna otra contrasena? (Y/N): ";
        cin.ignore();
        cin >> solicitud;
    }

    }
    while (solicitud != 'N'); // si el usuario no quiere otra termina el programa

    return 0;
}
//####################################################################################
bool validacion(string contrasena, int index)
{
    if (index < 6) // valida su tamano
    {
        cout << "Su contrasena debe tener al menos 6 caracteres.\n";
        return false;
    }

    bool mayuscula = false, minuscula = false, digito = false; // flags para tener un valor inicial

    // ciclo para verificar cada valor de la contrasena
    for (int indice = 0; indice < index; indice++)
    {
        if (isupper(contrasena[indice]))   mayuscula = true; // verifica si es mayuscula
        if (islower(contrasena[indice]))   minuscula = true; // verifica si es minuscula
        if (isdigit(contrasena[indice]))   digito    = true; // verifica si es digito
    }

    if (mayuscula == false && minuscula == false && digito == false) //si falla en todas
        cout << "La contrasena debe tener al menos un digito, una letra mayuscula y una minuscula.\n";
    else if (mayuscula == false && minuscula == false)              //si falla en mayuscula y minuscula
        cout << "La contrasena debe tener al menos una letra mayuscula y una minuscula.\n";
    else if (mayuscula == false && digito == false)                 //si falla en mayuscula digito
        cout << "La contrasena debe tener al menos un digito y una letra mayuscula.\n";
    else if (minuscula == false && digito == false)                 //si falla en minuscula digito
        cout << "La contrasena debe tener al menos un digito y una letra minuscula.\n";
    else if (mayuscula == false)                                    //si falla en mayuscula
        cout << "La contrasena debe tener al menos una letra mayuscula.\n";
    else if (minuscula == false)                                    //si falla en minuscula
        cout << "La contrasena debe tener al menos una letra minuscula.\n";
    else if (digito == false)                                       // si falla en digito
        cout << "La contrasena debe tener al menos un digito.\n";

    // Nota: En caso de no fallar rapidamente se hacen un poco mas de verificaciones, pero el display se vera mejor.

    cout << string(60, '-') << endl;

    if (mayuscula == false || minuscula == false || digito == false)  return false;
    else return true;

}
