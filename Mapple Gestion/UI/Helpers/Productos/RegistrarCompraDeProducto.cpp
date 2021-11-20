#include "FuncionesComunesProducto.h"
#include "RegistrarCompraDeProducto.h"
#include "../../../Models/GastoModel.h"
#include "../../../Managers/ProductoManager.h"
#include "../../../Managers/GastoManager.h"
#include "../../rlutil.h"
#include <string>
using namespace std;
using namespace rlutil;

void RegistrarCompraProducto()
{
    cls();
    cout << endl;
    cout << "                REGISTRAR COMPRA DE PRODUCTO" << endl;
    cout << "------------------------------------------------------------------" << endl;

    int codigo = SeleccionarProducto();
    if(codigo==-1) return;
    ProductoModel producto;
    if(ProductoManager::cargar(codigo, producto))
    {
        MostrarDatosActuales(producto);
        int cantidad = PedirCantidad();
        float precioUnitario = PedirPrecioUnitario();
        producto.agregarStock(cantidad);

        while(!ProductoManager::sobreescribir(producto))
        {
            cout << "OCURRIÓ UN PROBLEMA AL GUARDAR LOS CAMBIOS DEL PRODUCTO" << endl;
            cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl;
            if(getkey()==KEY_ESCAPE) return;
        }

        GastoModel gasto;
        gasto.setDescripcionGasto(to_string(producto.getCodigoProducto()) + " -- " + producto.getDescripcionProducto());
        gasto.setUnidades(cantidad);
        gasto.setMontoUnitario(precioUnitario);

        while(!GastoManager::guardarNuevo(gasto))
        {
            cout << "EL STOCK HA SIDO AGREGADO AL INVENTARIO" << endl << endl;
            cout << "OCURRIÓ UN PROBLEMA AL REGISTRAR EL GASTO" << endl;
            cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl;
            if(getkey()==KEY_ESCAPE) return;
        }

        cout << endl << endl;
        cout << "------------------------------------------------------------------" << endl << endl;
        cout << "SE HA REGISTRADO LA COMPRA DE STOCK";
    }
    else
    {
        cout << "HUBO PROBLEMAS AL CARGAR LOS DATOS DEL PRODUCTO" << endl;
    }
    anykey();
}

int PedirCantidad()
{
    int cantidad;
    cout << endl << "INGRESE LA CANTIDAD DE UNIDADES COMPRADAS: " << endl;
    cin >> cantidad;
    while(cin.fail() || cantidad<1)
    {
        cin.clear();
        cin.ignore();
        cout << "LA CANTIDAD INGRESADA NO ES VÁLIDA, INGRESE NUEVAMENTE" << endl;
        cin >> cantidad;
    }
    return cantidad;
}

float PedirPrecioUnitario()
{
    float precio;
    cout << endl;
    cout << "INGRESE EL PRECIO POR UNIDAD DE LA COMPRA: $" ;
    cin >> precio;
    while(cin.fail() || precio<=0)
    {
        cin.clear();
        cin.ignore();
        cout << "EL MONTO INGRESADO NO ES VÁLIDO, POR FAVOR, INGRESE NUEVAMENTE" << endl;
        cin >> precio;
    }
    return precio;
}
