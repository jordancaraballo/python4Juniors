#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Prototipos
const int fila = 6, columna = 5;
int solicitudEnteros(string);
int CalcularTotalFila(int [][columna], int);
int CalcularTotalColumna(int [][columna], int);


int main()
{
    int octavitas[fila][columna] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30}};

    // Total de la fila
    int filaUsuario = solicitudEnteros("Ingrese la fila de la cual desea el total: ");
    int totalFila   = CalcularTotalFila(octavitas,filaUsuario);

    //Total de la columna
    int columnaUsuario = solicitudEnteros("Ingrese la columna de la cual desea el total: ");
    int totalColumna   = CalcularTotalColumna(octavitas,columnaUsuario);

    return 0;
}
//*****************************************************************************
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
//*****************************************************************************
int CalcularTotalFila(int arr[][columna], int fila)
{
    int total = 0;
    for (int valor = 0; valor < columna; valor++)
        total += arr[fila-1][valor];

    return total;
}
//*****************************************************************************
int CalcularTotalColumna(int arr[][columna], int columna)
{
    int total = 0;
    for (int valor = 0; valor < fila; valor++)
        total += arr[valor][columna-1];

    return total;
}






