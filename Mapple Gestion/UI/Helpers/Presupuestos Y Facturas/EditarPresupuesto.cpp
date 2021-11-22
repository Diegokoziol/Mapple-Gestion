#include "EditarPresupuesto.h"
#include "../../rlutil.h"
#include <iomanip>
using namespace std;
using namespace rlutil;

void EditarPresupuesto(PresupuestoModel &presupuesto, const char* encabezado)
{
    cls();
    cout << encabezado;
    cout << right << setw(100-strlen(encabezado)) << presupuesto.getFecha().getStrFecha();
    cout << left << endl << endl;
    const int anchosColumnas[] = {10,35,10,20,20};
    TitulosColumnas(anchosColumnas);
}

void TitulosColumnas(const int* anchos)
{
    cout << setw(anchos[0]) << "CÓDIGO" << '|';
    cout << setw(anchos[1]) << "DESCRIPCIÓN" << '|';
    cout << setw(anchos[2]) << "CANTIDAD" << '|';
    cout << setw(anchos[3]) << "PRECIO UNITARIO" << '|';
    cout << setw(anchos[4]) << "TOTAL" << '|' << endl;

    for(int i=0; i<100; i++) cout << "~";
    cout << endl;
}
