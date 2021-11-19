#include "VerStock.h"
#include "../../../Managers/ProductoManager.h"
#include "../../../Models/ProductoModel.h"
#include "../../rlutil.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
using namespace rlutil;

void VerStock()
{
    cls();
    cout << endl << "     **********   STOCK    DISPONIBLE   **********   " << endl << endl;
    cout << left;
    cout << "______________________________________________________________________" << endl;
    cout << setw(10) << "CÓDIGO";
    cout << setw(31) << "DESCRIPCIÓN";
    cout << setw(10) << "PRECIO";
    cout << setw(20) << "STOCK DISPONIBLE" << endl;
    cout << "______________________________________________________________________" << endl;
    cout << endl;

    ImprimirProductos();

    anykey();
}

void ImprimirProductos()
{
    vector<ProductoModel> productos = ProductoManager::leerTodos();
    for(size_t i=0; i<productos.size(); i++)
        ImprimirProducto(productos[i]);
}

void ImprimirProducto(ProductoModel &producto)
{
    cout << left;
    cout << setw(10) << producto.getCodigoProducto();
    cout << setw(31) << producto.getDescripcionProducto();
    cout << "$"<< fixed << setprecision(2) << setw(10) << producto.getPrecioProducto();
    cout << setw(4) << producto.getStockDisponible() << endl;
    cout << "---------------------------------------------------------------------" << endl;
}
