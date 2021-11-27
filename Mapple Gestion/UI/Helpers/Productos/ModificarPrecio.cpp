#include "FuncionesComunesProducto.h"
#include "ModificarPrecio.h"
#include "../../../Managers/ProductoManager.h"
#include "../../../Models/ProductoModel.h"
#include "../../EntradaNumerica.h"
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

            while(!ProductoManager::sobreescribir(producto))
            {
                cout << "OCURRI� UN PROBLEMA AL GUARDAR LOS CAMBIOS" << endl;
                cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl << endl;
                if(getkey()==KEY_ESCAPE) return;
            }
            cout << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "               PRECIO ACTUALIZADO";
            cout << endl;
        }
        else
        {
            cout << "HUBO PROBLEMAS AL CARGAR LOS DATOS DEL PRODUCTO" << endl;
        }

        anykey();
    }
}

float PedirNuevoPrecio()
{
    float precio;
    cout << endl;
    cout << "INGRESE NUEVO PRECIO DEL PRODUCTO: $" ;
    EntradaNumerica(precio);
    while(precio<0)
    {

        cout << "EL MONTO INGRESADO NO ES V�LIDO" << endl;
        EntradaNumerica(precio);
    }
    return precio;
}
