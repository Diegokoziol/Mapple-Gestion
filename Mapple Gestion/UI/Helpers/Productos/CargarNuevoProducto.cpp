#include "CargarNuevoProducto.h"
#include "../../rlutil.h"
#include "../../../Models/ProductoModel.h"
#include "../../../Managers/ProductoManager.h"
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
    cin >> codigo;
    while(ProductoManager::existe(codigo) || codigo<1 || cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "CÓDIGO INVÁLIDO O REPETIDO, INGRESE OTRO CÓDIGO O (-1) PARA CANCELAR " << endl;
        cin >> codigo;
        if(codigo==-1) return;
    }
    productoNuevo.setCodigoProducto(codigo);

    cout << "INGRESE DESCRIPCIÓN DEL PRODUCTO: ";
    cin.ignore();
    getline(cin, descripcion);
    while(descripcion.length()>29)
    {
        cout << "POR FAVOR, INGRESE UNA DESCRIPCIÓN MÁS BREVE: ";
        getline(cin, descripcion);
    }
    productoNuevo.setDescripcionProducto(descripcion);

    cout << endl;
    cout << "INGRESE PRECIO DEL PRODUCTO: $";
    cin >> precio;
    while(precio<=0 || cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "MONTO INVÁLIDO , INGRESE OTRO O (-1) PARA CANCELAR " << endl;
        if(precio==-1) return;
    }
    productoNuevo.setPrecioProducto(precio);

    while(!ProductoManager::guardarNuevo(productoNuevo))
    {
        cout << "HUBO UN PROBLEMA AL GUARDAR" << endl;
        cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl;
        if(getkey()==KEY_ESCAPE) return;
    }
    cout << endl;
    cout << "------------------------------------------------------------------"<<endl;
    cout << "               PRODUCTO AGREGADO";
    anykey();
}

