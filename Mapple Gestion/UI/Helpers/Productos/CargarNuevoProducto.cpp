#include "CargarNuevoProducto.h"
#include "../../rlutil.h"
#include "../../../Models/ProductoModel.h"
#include "../../../Managers/ProductoManager.h"
#include "../../EntradaNumerica.h"
#include "../../EntradaCadena.h"

using namespace std;
using namespace rlutil;

void CargarNuevoProducto()
{
    cls();
    ProductoModel productoNuevo;
    int codigo;
    string descripcion;
    float precio;

    cout<<endl;
    cout << "                CARGAR NUEVO PRODUCTO" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "INGRESE CODIGO DEL PRODUCTO: ";
    EntradaNumerica(codigo);
    while(codigo<1 || ProductoManager::existe(codigo) )
    {
        cout << "CÓDIGO INVÁLIDO O REPETIDO, INGRESE OTRO CÓDIGO O (-1) PARA CANCELAR " << endl;
        EntradaNumerica(codigo);
        if(codigo==-1) return;

    }
    productoNuevo.setCodigoProducto(codigo);

    cout << "INGRESE DESCRIPCIÓN DEL PRODUCTO: ";
    descripcion = EntradaCadena(29);

    productoNuevo.setDescripcionProducto(descripcion);

    cout << endl;
    cout << "INGRESE PRECIO DEL PRODUCTO: $";
    EntradaNumerica(precio);
    while(precio<=0 )
    {

        cout << "MONTO INVÁLIDO , INGRESE OTRO O (-1) PARA CANCELAR " << endl;
        EntradaNumerica(precio);
        if(precio==-1) return;
    }
    productoNuevo.setPrecioProducto(precio);

    while(!ProductoManager::guardarNuevo(productoNuevo))
    {
        cout << "HUBO UN PROBLEMA AL GUARDAR" << endl;
        cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl << endl;
        if(getkey()==KEY_ESCAPE) return;
    }
    cout << endl;
    cout << "------------------------------------------------------------------"<<endl;
    cout << "               PRODUCTO AGREGADO";
    anykey();
}

