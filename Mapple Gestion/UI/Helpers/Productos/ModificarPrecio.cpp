#include "FuncionesComunesProducto.h"
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

            while(!ProductoManager::sobreescribir(producto))
            {
                cout << "OCURRIÓ UN PROBLEMA AL GUARDAR LOS CAMBIOS" << endl;
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
    cin >> precio;
    while(cin.fail() || precio<0)
    {
        cin.clear();
        cin.ignore();
        cout << "EL MONTO INGRESADO NO ES VÁLIDO" << endl;
        cin >> precio;
    }
    return precio;
}
