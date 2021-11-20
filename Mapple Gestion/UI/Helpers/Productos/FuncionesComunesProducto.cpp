#include "FuncionesComunesProducto.h"
#include "../../../Managers/ProductoManager.h"
#include "../../rlutil.h"
#include <string>
using namespace std;
using namespace rlutil;

int SeleccionarProducto()
{

    int codigo;
    cout << "INGRESE CÓDIGO DEL PRODUCTO: ";
    cin >> codigo;
    while(cin.fail() || codigo<1 || !ProductoManager::existe(codigo) )
    {
        cin.clear();
        cin.ignore();
        cout << "CÓDIGO INVÁLIDO O NO EXISTENTE, INGRESE OTRO CÓDIGO O (-1) PARA CANCELAR " << endl;
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
    cout << "STOCK ACTUAL: " << producto.getStockDisponible() << endl;
}
