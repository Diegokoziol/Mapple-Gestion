#include "EntradaCadena.h"

string EntradaCadena(size_t tam)
{
    string ingreso;
    getline(cin, ingreso);
    while(ingreso.size()>tam || ingreso.empty())
    {
        if(ingreso.size()>tam)
        {
            cout << "EL TEXTO INGRESADO ES DEMASIADO LARGO Y PODR�A PERDERSE AL GUARDAR EN DISCO" << endl;
            cout << "POR FAVOR INGRESE OTRO M�S CORTO" << endl;
        }
        getline(cin, ingreso);
    }
    return ingreso;
}
