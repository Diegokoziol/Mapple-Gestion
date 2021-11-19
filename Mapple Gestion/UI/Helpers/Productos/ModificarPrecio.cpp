#include "ModificarPrecio.h"
#include "../../../Managers/ProductoManager.h"
#include "../../../Models/ProductoModel.h"
#include "../../rlutil.h"
#include <string>
using namespace std;
using namespace rlutil;

void ModificarPrecio()
{
    cls();
    cout << endl;
    cout << "                ACTUALIZAR PRECIO PRODUCTO" << endl;
    cout << "------------------------------------------------------------------" << endl;

    int codigo = SeleccionarProducto();
    if(codigo!=-1)
    {
        ProductoModel producto;
        if(ProductoManager::cargar(codigo, producto))
        {
            MostrarDatosActuales(producto);
            float nuevoPrecio = PedirNuevoPrecio();
            producto.setPrecioProducto(nuevoPrecio);

            if(ProductoManager::sobreescribir(producto))
            {
                cout << endl;
                cout << "------------------------------------------------------------------" << endl;
                cout << "               PRECIO ACTUALIZADO";
                cout << endl;
            }
            else
            {
                cout << "OCURRI� UN PROBLEMA AL GUARDAR LOS CAMBIOS" << endl;
            }
        }
        else
        {
            cout << "HUBO PROBLEMAS AL CARGAR LOS DATOS DEL PRODUCTO" << endl;
        }

        anykey();
    }
}

int SeleccionarProducto()
{

    int codigo;
    cout << "INGRESE CODIGO DEL PRODUCTO A MODIFICAR: ";
    cin >> codigo;
    while(cin.fail() || codigo<1 || !ProductoManager::existe(codigo) )
    {
        cin.clear();
        cin.ignore();
        cout << "C�DIGO INV�LIDO O NO EXISTENTE, INGRESE OTRO C�DIGO O (-1) PARA CANCELAR " << endl;
        cin >> codigo;
        if(codigo==-1) return -1;
    }

    return codigo;
}

void MostrarDatosActuales(ProductoModel &producto)
{
    cout << endl;
    cout << producto.getDescripcionProducto() << endl;
    cout << "PRECIO ACTUAL: $" << producto.getPrecioProducto() << endl;
}

float PedirNuevoPrecio()
{
    float precio;
    cout << endl;
    cout << "INGRESE NUEVO PRECIO DEL PRODUCTO: $" ;
    cin >> precio;
    while(cin.fail() || precio<0)
    {
        cin.clear();
        cin.ignore();
        cout << "EL MONTO INGRESADO NO ES V�LIDO" << endl;
        cin >> precio;
    }
    return precio;
}
