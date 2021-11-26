#include "EntradaCadena.h"

string EntradaCadena(size_t tam)
{
    string ingreso;
    getline(cin, ingreso);
    while(ingreso.size()>tam || ingreso.empty())
    {
        if(ingreso.size()>tam)
        {
            cout << "EL TEXTO INGRESADO ES DEMASIADO LARGO Y PODRÍA PERDERSE AL GUARDAR EN DISCO" << endl;
            cout << "POR FAVOR INGRESE OTRO MÁS CORTO" << endl;
        }
        getline(cin, ingreso);
    }
    return ingreso;
}
