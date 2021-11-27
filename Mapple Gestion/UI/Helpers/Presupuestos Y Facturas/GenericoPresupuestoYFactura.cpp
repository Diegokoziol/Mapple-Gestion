#include "GenericoPresupuestoYFactura.h"
#include <iomanip>
#include <iostream>
using namespace std;

void TitulosColumnas(const int* anchos)
{
    cout << setw(anchos[0]) << " CÓDIGO" << '|';
    cout << setw(anchos[1]) << " DESCRIPCIÓN" << '|';
    cout << setw(anchos[2]) << " CANTIDAD" << '|';
    cout << setw(anchos[3]) << " PRECIO UNITARIO" << '|';
    cout << setw(anchos[4]) << " TOTAL" << '|' << endl;

    for(int i=0; i<100; i++) cout << "~";
    cout << endl;
}

void ImprimirItemVacio(const int* anchos)
{
    cout << setw(anchos[0]) << "" << '|';
    cout << setw(anchos[1]) << "" << '|';
    cout << setw(anchos[2]) << "" << '|';
    cout << setw(anchos[3]) << "" << '|';
    cout << setw(anchos[4]) << "" << '|' << endl;
}
