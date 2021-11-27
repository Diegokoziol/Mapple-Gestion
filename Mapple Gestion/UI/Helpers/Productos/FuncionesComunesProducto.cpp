#include "FuncionesComunesProducto.h"
#include "../../../Managers/ProductoManager.h"
#include "../../rlutil.h"
#include "../../EntradaNumerica.h"
#include <string>
using namespace std;
using namespace rlutil;

int SeleccionarProducto()
{

    int codigo;
    cout << "INGRESE C�DIGO DEL PRODUCTO: ";
    EntradaNumerica(codigo);
    while(codigo<1 || !ProductoManager::existe(codigo) )
    {

        cout << "C�DIGO INV�LIDO O NO EXISTENTE, INGRESE OTRO C�DIGO O (-1) PARA CANCELAR " << endl;
        EntradaNumerica(codigo);
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
