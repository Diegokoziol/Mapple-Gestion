#include "EditarPresupuesto.h"
#include "../../../Managers/PresupuestoManager.h"
#include "../../../Managers/ProductoManager.h"
#include "../../rlutil.h"
#include <iomanip>
using namespace std;
using namespace rlutil;

void EditarPresupuesto(PresupuestoModel &presupuesto, const char* encabezado)
{
    int modo=1;
    while(modo)
    {
        cls();
        cout << encabezado;
        cout << right << setw(100-strlen(encabezado)) << presupuesto.getFecha().getStrFecha();
        cout << left << endl << endl;
        const int anchosColumnas[] = {10,35,10,20,20};
        TitulosColumnas(anchosColumnas);
        presupuesto.agregarItem(ItemPresupuestoModel());
        for(size_t i=0; i<20; i++)
        {
            if(i<presupuesto.getCantidadItems())
                ImprimirItem(presupuesto.getItem(i), anchosColumnas);
            else
                ImprimirItemVacio(anchosColumnas);
        }

        switch(modo)
        {
        case 1:
            modo = Modo1();
            break;
        case 3:
            modo = Modo3(presupuesto);
            break;
        }
    }
}

void TitulosColumnas(const int* anchos)
{
    cout << setw(anchos[0]) << "CÓDIGO" << '|';
    cout << setw(anchos[1]) << "DESCRIPCIÓN" << '|';
    cout << setw(anchos[2]) << "CANTIDAD" << '|';
    cout << setw(anchos[3]) << "PRECIO UNITARIO" << '|';
    cout << setw(anchos[4]) << "TOTAL" << '|' << endl;

    for(int i=0; i<100; i++) cout << "~";
    cout << endl;
}

void ImprimirItemVacio(const int* anchos)
{
    cout << setw(anchos[0]) << "" << '|';
    cout << setw(anchos[1]) << "" << '|';
    cout << setw(anchos[2]) << "" << '|';
    cout << setw(anchos[3]) << "" << '|';
    cout << setw(anchos[4]) << "" << '|' << endl;
}

void ImprimirItem(ItemPresupuestoModel item, const int* anchos)
{
    cout << setw(anchos[0]) << item.getProducto().getCodigoProducto() << '|';
    cout << setw(anchos[1]) << item.getProducto().getDescripcionProducto() << '|';
    cout << setw(anchos[2]) << item.getCantidad() << '|';
    cout << setw(anchos[3]) << item.getMontoUnitario() << '|';
    cout << setw(anchos[4]) << item.getMontoTotal() << '|' << endl;
}

void EntradaNumerica(int &n)
{
    while(!(cin >> n))
    {
        cin.clear();
        cin.ignore();
    }
}

int Modo1()
{
    hidecursor();
    cout << "F3 - AGREGAR    F5 - ELIMINAR    F7 - CERRAR    F9 - ACTUALIZAR PRECIOS    F11 - GENERAR FACTURA" <<endl;
    switch(getkey())
    {
    case KEY_F3:
        return 3;
    case KEY_F5:
        return 5;
    case KEY_F7:
        return 7;
    case KEY_F9:
        return 9;
    case KEY_F11:
        return 11;
    default:
        return 1;
    }
}

int Modo3(PresupuestoModel &presupuesto)
{
    showcursor();
    int cod, cant;
    cout << "CÓDIGO DE PRODUCTO: ";
    EntradaNumerica(cod);

    if(cod<1 || !ProductoManager::existe(cod))
    {
        cout << "EL CÓDIGO INGRESADO NO ES VÁLIDO" << endl;
        anykey();
        return 1;
    }

    ProductoModel producto;
    if(!ProductoManager::cargar(cod, producto))
    {
        cout << "HUBO UN PROBLEMA AL CARGAR EL PRODUCTO SOLICITADO" << endl;
        anykey();
        return 1;
    }

    cout << producto.getDescripcionProducto() << endl;

    cout << "INGRESE CANTIDAD: " << endl;
    EntradaNumerica(cant);
    while(cant<1)
    {
        cout << "POR FAVOR INGRESE UNA CANTIDAD POSITIVA" << endl;
        EntradaNumerica(cant);
    }

    presupuesto.agregarItem(ItemPresupuestoModel(producto, cant));

    return 1;
}
