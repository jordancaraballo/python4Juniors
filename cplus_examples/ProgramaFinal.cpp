/****************************************************************
/** Programador: Jordan Alexis Caraballo Vega  
/**              Gustavo E. Torres Rodriguez     
                 Angel Crespo Delgado        
/** Proyecto Final
/**
/** Propósito: Este programa se encarga de llevar un record de informacion estipulado en un archivo.
/** Input: Se le pide al usuario que elija entre un menu determinado e ingrese la informacion necesaria.
/** Output: Todo dependera en lo que desee el usuario.

/** Funciones
    menu                - Este le permite escoger al usuario la funcion que desea realizar
    nuevaCuenta         - se crea el archivo con cada uno de los valores necesarios
        ingresarValidar_Objeto  - valida nombre, ciudad, direccion, pais
        ingresarValidar_Zip     - valida zip code
        ingresarValidar_Tel     - valida numero de telefono
        ingresarValidar_Balance - valida balance de cuenta
        ingresarValidar_Fecha   - valida fecha de ultima transaccion
    mostrarCuenta       - se solicita el nombre de la cuenta al usuario para imprimirla
    borrarCuenta        - se solicita el nombre de la cuenta al usuario para borrarla
    cambiarCuenta       - se sustituye la cuenta anterior por la nueva que ingresa el usuario
    mostrarTodasCuentas - se imprimen todas las cuentas
    si_no_Validacion    - valida si o no
    limpia_pantalla     - limpia la pantalla
/****************************************************************/
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <cstring>
using namespace std;
//*************************************************************************************************************
//                                       Estructuras Globales                                                //
//*************************************************************************************************************
const int SIZE_Nombre = 60, SIZE_Dir  = 60, SIZE_Ciudad  = 20, SIZE_Pais  = 20, // constantes de indices de arreglos
          SIZE_Zip    = 6 , SIZE_tele = 11, SIZE_Balance = 20, SIZE_Fecha = 11;

struct archivo
{
    char nombre[SIZE_Nombre];   char direccion[SIZE_Dir];
    char ciudad[SIZE_Ciudad];   char pais[SIZE_Pais];
    char zip[SIZE_Zip];         char telefono[SIZE_tele];
    char balance[SIZE_Balance]; char fechapago[SIZE_Fecha];
} persona; // estructura utilizada durante todo el programa
//*************************************************************************************************************
//                                          Prototipos                                                       //
//*************************************************************************************************************
//Principales
char menu(); // Jordan
void nuevaCuenta(); // Angel
void mostrarCuenta(archivo); // Angel
void borrarCuenta(fstream &); // Angel
void cambiarCuenta(fstream &); // Gustavo
void mostrarTodasCuentas(archivo); // Gustavo
bool salirDelPrograma(); // Jordan
//Validacion y Output: Jordan
string ingresarValidar_Objeto(string,char, char);
string ingresarValidar_Zip(string);
string ingresarValidar_Tel(string);
string ingresarValidar_Balance(string);
string ingresarValidar_Fecha(string);
char   si_no_Validacion(string linea, char &);
void   limpia_pantalla();
//*************************************************************************************************************
//                                                 Main                                                      //
//*************************************************************************************************************
int main()
{
    cout << string(60, '*') << "\n\tSaludos! Soy su editor de cuenta de banco\n";
    char solicitud;         // por si el usuario desea hacer otra solicitud
    fstream archivoCuentas; // Declarar variable de archivo

    do
    {
        cout << string(60, '*') << endl;
        char seleccion = menu(); // Mostrarle menu al usuario
        cout << string(60, '*') << endl;

        switch(seleccion) // Se accesa a las funciones necesarias
        {
            case 'A': // Ingresar una nueva cuenta
            {
                cout << "\t\tIngresar Nueva Cuenta\n";
                archivoCuentas.open ("ArchivoCuentas.txt", ios::out | ios::app | ios::binary);
                nuevaCuenta(); // se llama a la funcion para solicitir **Mejorar: output de dinero**
                archivoCuentas.write(reinterpret_cast<char *>(&persona), sizeof(persona));
                archivoCuentas.close();
                break;
            }

            case 'B': // Mostrar algun perfil de cuenta
            {
                cout << "\t\t  Mostrar Cuenta\n" << string(60, '*') << endl;
                mostrarCuenta(persona);
                break;
            }

            case 'C': // Borrar  algun perfil de cuenta
            {
                cout << "\t\t  Borrar Cuenta\n" << string(60, '*') << endl;
                //borrarCuenta(archivoCuentas);
                break;
            }

            case 'D': // Cambiar algun perfil de cuenta
            {
                cout << "\t\t  Cambiar Cuenta\n" << string(60, '*') << endl;
                cambiarCuenta(archivoCuentas);
                break;
            }

            case 'E': // Mostrar todas las cuentas
            {
                cout << "\t\tCuentas Disponibles en el Sistema:\n";
                mostrarTodasCuentas(persona);
                break;
            }

            case 'F': // Salir del programa
            {
                cout << "\t\tSaliendo del Programa..." << endl << string(60, '*') << endl;
                if (salirDelPrograma() == true) return 0;
                else break;
            }
        }

        si_no_Validacion("Desea realizar alguna otra transaccion? (Y/N): ", solicitud); // preguntar si desea realizar otra transaccion
        limpia_pantalla(); // limpia la pantalla, por seguridad
        archivoCuentas.close(); // cerrar archivo
    }
    while (solicitud != 'N'); // si el usuario no quiere otra termina el programa

    return 0;
}
//*************************************************************************************************************
//                                        Funciones Principales                                               //
//*************************************************************************************************************
char menu() //Done
{
    char utilidad;
    cout << "(A)  Ingresar una nueva cuenta      \n" << "(B)  Mostrar algun perfil de cuenta \n";
    cout << "(C)  Borrar  algun perfil de cuenta \n" << "(D)  Cambiar algun perfil de cuenta \n";
    cout << "(E)  Mostrar todas las cuentas      \n" << "(F)  Salir del Programa \n";
    cout << string(60, '*') << endl << "Seleccion: ";
    cin >> utilidad;
    utilidad = toupper(utilidad);

    while (utilidad != 'A' && utilidad != 'B' && utilidad != 'C' && utilidad != 'D' && utilidad != 'E' && utilidad != 'F')
    {
        cin.clear();  cout << "ERROR! Su seleccion no esta en el menu, vuelva a intentarlo.\nSeleccion: ";
        cin.ignore(); cin >> utilidad;
        utilidad = toupper(utilidad);
    }
    return utilidad;
}
//*************************************************************************************************************
void nuevaCuenta() // Done
{
    char solicitud;
    string NombreCompleto, Direccion, Ciudad, Pais, Zip, Telefono, Balance, FechaPago;
    do
    { //----------------------------------------------------------------------------------
        cout << string(60, '-') << endl;
        // Pedirle al usuario los valores
        NombreCompleto = ingresarValidar_Objeto  ("Entre su nombre Completo: ",'A', 'B');     // Nombre Completo
        Direccion      = ingresarValidar_Objeto  ("Entre su Direccion: ",'B','A');            // Direccion
        Ciudad         = ingresarValidar_Objeto  ("Entre su Ciudad: ",'C', 'A');              // Ciudad
        Pais           = ingresarValidar_Objeto  ("Entre su Pais: ",'C', 'A');                // Pais
        Zip            = ingresarValidar_Zip     ("Entre su Zip code: ");                     // Zip code
        Telefono       = ingresarValidar_Tel     ("Entre su Telefono (Ej: 666 666 6666): " ); // Telefono
        Balance        = ingresarValidar_Balance ("Entre su Balance: $");                     // Balance
        FechaPago      = ingresarValidar_Fecha   ("Fecha Ultima Transaccion (mm/dd/yyyy): "); // Fecha del ultimo pago

        // Ingresar los valores en el array
        strcpy(persona.nombre   , NombreCompleto.c_str());
        strcpy(persona.direccion, Direccion.c_str());
        strcpy(persona.ciudad   , Ciudad.c_str());
        strcpy(persona.pais     , Pais.c_str());
        strcpy(persona.zip      , Zip.c_str());
        strcpy(persona.telefono , Telefono.c_str());
        strcpy(persona.balance  , Balance.c_str());
        strcpy(persona.fechapago, FechaPago.c_str());
        cout << string(60, '-') << endl;
        //----------------------------------------------------------------------------------
        si_no_Validacion("Esta seguro que la informacion esta correcta? (Y/N): ", solicitud); // verificar que la info este correcta
    }
    while (solicitud == 'N');    // al decir no se repite el ciclo
}
//*************************************************************************************************************
void mostrarCuenta(archivo persona)
{
	fstream cuenta;	// Declaracion del archivo
	long numBytes,tamano,lineaNombre;
	cuenta.open("ArchivoCuentas.txt", ios::in | ios::binary | ios::app);

	string Nombre; // nombre que se buscara en el archivo
	do
	{
        Nombre = ingresarValidar_Objeto ("Entre su nombre Completo: ",'A','B');
        cuenta.seekg(0L, ios::beg);        // se comienza desde el principio del archivo
        cuenta.seekg(0L, ios::end);        // se llega al final
        numBytes    = cuenta.tellg(); // resultado de ese movimiento nos da el total de bites
        tamano      = numBytes / sizeof(persona); // cantidad de cuentas en el sistema
        lineaNombre = 0; // donde se encuentra el nombre deseado del archivo

        for (int i = 1; i <= tamano; i++)
        {
            cuenta.seekg((i) * sizeof(persona), ios::beg);
            cuenta.read(reinterpret_cast<char *>(&persona), sizeof(persona));

            if (Nombre == persona.nombre)
            {
                lineaNombre = i;
                break;
            }
        }
        if (lineaNombre == 0)
        {
            cout << "No se encontro ese nombre o el archivo esta vacio. Vuelva a intentarlo.\n";
            break;
        }
        else
        {
             // Imprimir el contenido
            cout << "Nombre: "                  << persona.nombre    << endl;
            cout << "Direccion: "               << persona.direccion << endl;
            cout << "Ciudad: "                  << persona.ciudad    << endl;
            cout << "Pais: "                    << persona.pais      << endl;
            cout << "Zip Code: "                << persona.zip       << endl;
            cout << "Numero Telefono: "         << persona.telefono  << endl;
            cout << "Balance: $"                << persona.balance   << endl;
            cout << "Fecha de su ultimo pago: " << persona.fechapago << endl;
            cout << string(60,'-') << endl;
        }
    }
    while (lineaNombre == 0);
	cuenta.close(); // cerrar archivo
}

//*************************************************************************************************************
void cambiarCuenta(fstream &archCuentas)
{
    // mismo proceso que mostrar cuenta
    archCuentas.open("ArchivoCuentas.txt", ios::in | ios::out | ios::binary); // abrir archivo
	string Nombre;
	long numBytes, tamano, lineaNombre;

	do
	{
        Nombre = ingresarValidar_Objeto ("Entre su nombre Completo: ",'A', 'B');
        archCuentas.seekg(0L, ios::beg);
        archCuentas.seekg(0L, ios::end);
        numBytes    = archCuentas.tellg();
        tamano      = numBytes / sizeof(persona);
        lineaNombre = 0;

        for (int i = 1; i <= tamano; i++)
        {
            archCuentas.seekg((i) * sizeof(persona), ios::beg);
            archCuentas.read(reinterpret_cast<char *>(&persona), sizeof(persona));

            if (Nombre == persona.nombre)
            {
                lineaNombre = i;
                break;
            }
        }

        if (lineaNombre == 0)
        {
            cout << "No se encontro ese nombre o el archivo esta vacio. Vuelva a intentarlo.\n";
            break;
        }
        else
        {
             // Imprimir el contenido
            cout << "Nombre: "                  << persona.nombre    << endl;
            cout << "Direccion: "               << persona.direccion << endl;
            cout << "Ciudad: "                  << persona.ciudad    << endl;
            cout << "Pais: "                    << persona.pais      << endl;
            cout << "Zip Code: "                << persona.zip       << endl;
            cout << "Numero Telefono: "         << persona.telefono  << endl;
            cout << "Balance: $"                << persona.balance   << endl;
            cout << "Fecha de su ultimo pago: " << persona.fechapago << endl;
            cout << string(60,'-') << endl;
        }
	}
    while (lineaNombre == 0);

	// Tomar la nueva informacion
	char solicitud;
    string NombreCompleto, Direccion, Ciudad, Pais, Zip, Telefono, Balance, FechaPago;
	do
    { //----------------------------------------------------------------------------------
        if (lineaNombre == 0) break;
        cout << string(60, '-') << endl;
        // Pedirle al usuario los valores
        NombreCompleto = ingresarValidar_Objeto ("Entre su nombre Completo: ",'A', 'A');  // Nombre Completo
        Direccion = ingresarValidar_Objeto      ("Entre su Direccion: ",'B', 'A');  // Direccion
        Ciudad = ingresarValidar_Objeto         ("Entre su Ciudad: ",'C', 'A');  // Ciudad
        Pais = ingresarValidar_Objeto           ("Entre su Pais: ",'C', 'A');  // Pais
        Zip = ingresarValidar_Zip               ("Entre su Zip code: ");  // Zip code
        Telefono  = ingresarValidar_Tel         ("Entre su Telefono (Ej: 666 666 6666): " );  // Telefono
        Balance   = ingresarValidar_Balance     ("Entre su Balance: $"); // Balance
        FechaPago = ingresarValidar_Fecha       ("Fecha Ultima Transaccion (mm/dd/yyyy): "); // Fecha del ultimo pago

        // Ingresar los valores en el array
        strcpy(persona.nombre, NombreCompleto.c_str());
        strcpy(persona.direccion, Direccion.c_str());
        strcpy(persona.ciudad, Ciudad.c_str());
        strcpy(persona.pais, Pais.c_str());
        strcpy(persona.zip, Zip.c_str());
        strcpy(persona.telefono, Telefono.c_str());
        strcpy(persona.balance, Balance.c_str());
        strcpy(persona.fechapago, FechaPago.c_str());
        cout << string(60, '-') << endl;
        //----------------------------------------------------------------------------------
        si_no_Validacion("Esta seguro que la informacion esta correcta? (Y/N): ", solicitud); // verificar que la info este correcta
    }
    while (solicitud == 'N'); // al decir no se repite el ciclo

	archCuentas.seekp((lineaNombre)* sizeof(persona), ios::beg); // se mueve a la posicion inicial del archivo
	archCuentas.write(reinterpret_cast<char *>(&persona),sizeof(persona));// se esribe encima del record actual
	archCuentas.close(); // cerrar archivo
}
//*************************************************************************************************************
void mostrarTodasCuentas(archivo persona)
{
    fstream cuentas;

    cuentas.open("ArchivoCuentas.txt", ios::in); // abrir archivo
    cuentas.read(reinterpret_cast<char *>(&persona), sizeof(persona)); // lee estrucuturas

	while (!cuentas.eof())
	{
        cout << "Nombre: "                  << persona.nombre    << endl;
        cout << "Direccion: "               << persona.direccion << endl;
        cout << "Ciudad: "                  << persona.ciudad    << endl;
        cout << "Pais: "                    << persona.pais      << endl;
        cout << "Zip Code: "                << persona.zip       << endl;
        cout << "Numero Telefono: "         << persona.telefono  << endl;
        cout << "Balance: $"                << persona.balance   << endl;
        cout << "Fecha de su ultimo pago: " << persona.fechapago << endl;

        cout << string(60,'-') << "\nPresione ENTER para continuar.\n" << string(60,'-') << endl;
        cin.get(); // para la visualizacion organizada
		cuentas.read(reinterpret_cast<char *>(&persona), sizeof(persona)); // Leer record
	}
	cout << "Archivo Terminado.\n";
    cuentas.close();
}
//*************************************************************************************************************
bool salirDelPrograma()
{
    char solicitud;
    cout << "Seguro que desea abandonar el programa? (Y/N): ";
    cin >> solicitud;
    solicitud = toupper(solicitud); // para no mortificarle la vida al usuario
    while (solicitud != 'Y' && solicitud != 'N') // validacion: si no es Y o N
    {
        cin.clear();
        cout << "ERROR! Solo puede ingresar (Y/N).Ingreselo nuevamente.\nSeguro que desea abandonar el programa? (Y/N): ";
        cin.ignore();
        cin >> solicitud;
        solicitud = toupper(solicitud);
    }
    if (solicitud == 'Y') return true;
    else return false;
}
//*************************************************************************************************************
//                                        Funciones Validacion                                               //
//*************************************************************************************************************
char si_no_Validacion(string linea, char &seleccion)
{
    cout << linea;
    cin >> seleccion;
    seleccion = toupper(seleccion); // para no mortificarle la vida al usuario
    while (seleccion != 'Y' && seleccion != 'N') // validacion: si no es Y o N
    {
        cin.clear();
        cout << "ERROR! Solo puede ingresar (Y/N).Ingreselo nuevamente.\n" << linea;
        cin.ignore(); cin >> seleccion;
        seleccion = toupper(seleccion); // para no mortificarle la vida al usuario
    }
    return seleccion;
}

string ingresarValidar_Objeto(string linea, char seleccion, char robaEspacio)
{
    string objeto;
    bool validacion;
    int espacio = 0;
    do
    {
        validacion = true; // flag de que esta correcto
        cout << linea;
        if (robaEspacio == 'B') cin.ignore();
        getline(cin, objeto);
        while (objeto.size() < 4 || objeto.size() > 20)
        {
            if ((seleccion == 'A' && objeto.size() < 60) || (seleccion == 'B' && objeto.size() < 60)) break;

            cin.clear();
            cout << "NOTA: El largo del nombre es incompatible con las exigencias.\n" << linea;
            getline(cin, objeto);
        }
        if (seleccion == 'B') return objeto; // si es direccion no se valida nada, solo el tamano
        for (int indice = 0; indice < objeto.size(); indice++) // la cantidad de items que tiene
            {if (!isalpha(objeto[indice]) && !isspace(objeto[indice]) && objeto[indice] != '.')   validacion = false;
             if (isspace(objeto[indice])) espacio++; // verificar si no hay al menos un espacio
            } // verifica si es letra o espacio
        if (seleccion == 'A' && espacio == 0 )
        {
            validacion = false;
            cout << "Debe tener al menos un apellido separado por espacio.\n";
        }
        if (validacion == false) cout << "Encontramos un error ortografico. Vuelva a ingresarlo.\n";
    }
    while (validacion == false);
    return objeto;
}
//*************************************************************************************************************
string ingresarValidar_Zip(string linea)
{
    string numero;
    bool validacion;
    do
    {
        validacion = true; // flag de que esta correcto
        cout << linea;
        getline(cin, numero);
        if (numero.size() != 5) validacion = false; // si el numero no es igual a la cantidad permitida
        for (int indice = 0; indice < numero.size(); indice++) // la cantidad de items que tiene
        {
            if (!isdigit(numero[indice]))   validacion = false;
        } // verifica si es letra o espacio
        if (validacion == false) cout << "Encontramos un error en su entrada. Vuelva a ingresarlo.\n";
    }
    while (validacion == false);
    return numero;
}
//*************************************************************************************************************
string ingresarValidar_Tel(string linea)
{
    string numero;
    bool validacion, space;

    do
    {
        validacion = true; // flag de que esta correcto
        cout << linea; // se coloca por espacios porque es mas facil para el usuario
        getline(cin, numero);
        while (numero.size() < 12)
        {
            cin.clear();
            cout << "NOTA: Le faltan valores. Vuelva a ingresar su telefono.\n" << linea;
            getline(cin, numero);
        }

        for (int indice = 0; indice < numero.size(); indice++) // la cantidad de items que tiene
        {
            if (!isdigit(numero[indice]) && (!isspace(numero[indice])) && numero[indice] != '-')   validacion = false; // verifica si es letra o espacio
        }
        if (((!isspace(numero[3])) || (!isspace(numero[7]))) && (numero[3] != '-' || numero[7] != '-')) validacion = false; // Si no tiene al menos un espacio en la posicion 3
        if (validacion == false) cout << "Encontramos un error en su entrada.\nEl debe estar separado por espacios. Vuelva a ingresarlo.\n";

        numero.replace(3,1, "-"); // se le coloca el guion
        numero.replace(7,1, "-");
    }
    while (validacion == false);
    return numero;
}
//*************************************************************************************************************
string ingresarValidar_Balance(string linea)
{
    string balance;
    cout << linea;
    getline(cin, balance);
    double balanceDouble;
    balanceDouble = atof(balance.c_str());

    while ((balanceDouble+1) / (balanceDouble+1) != 1 || balanceDouble < 0) // validacion: que no sea menor que 0
        {
            cin.clear();
            cout << "ERROR! La cuenta solo puede tener ingresos de $0.00 o mas. Vuelva a intentarlo.\n" << linea;
            cin.ignore();
            getline(cin, balance);
            balanceDouble = atof(balance.c_str());
        }

    balance = static_cast<ostringstream*>( &(ostringstream() << balanceDouble) )->str();
    return balance;
}
//*************************************************************************************************************
string ingresarValidar_Fecha(string linea)
{
    bool validacion;
    string fecha;
    int dia, mes, ano;

    do
    {
        validacion = true;
        cout << linea;
        getline(cin, fecha);
        while (fecha.size() < 10)
        {
            cin.clear();
            cout << "NOTA: Le faltan valores. Vuelva a ingresar su fecha.\n" << linea;
            getline(cin, fecha);
        }
        // convertir substring en entero con el dia, mes y el ano
        mes = atoi(fecha.substr(0,2).c_str());
        dia = atoi(fecha.substr(3,5).c_str());
        ano = atoi(fecha.substr(6).c_str());

        for (int indice = 0; indice < fecha.size(); indice++)
        {
            if (!isdigit(fecha[indice]) && (!(fecha[indice] == '/')))  validacion = false; // si no es entero o '/'
        }
        // Fechas validas con respecto a los maximos permitidos
        if (dia > 31 || mes > 12 || ano > 2015 || fecha[2] != '/' || fecha[5] != '/')
        {
            validacion = false; cout << "NOTA: Encontramos un error. ";
        }
        // Fechas validas con respectop a meses menores que 31
        else if ((mes == 4 && dia > 30) || (mes == 6 && dia > 30) || (mes == 9 && dia > 30) || (mes == 11 && dia > 30) || (mes == 2 && dia > 28))
        {
            validacion = false; cout << "NOTA: El mes no concuerda con su numero de dias. ";
        }
        if (validacion == false) cout << "Vuelva a ingresar su fecha.\n"; // en caso de ser falso
    }
    while (validacion == false);
    return fecha;
}
//*************************************************************************************************************
void limpia_pantalla()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}
//*************************************************************************************************************
