#include <iostream>
#include <iomanip>
#include "../../../Models/FacturaModel.h"
#include "../../../Managers/FacturaManager.h"
#include "../../rlutil.h"
#include "../../EntradaNumerica.h"
#include "VerFactura.h"
#include "GenericoPresupuestoYFactura.h"
using namespace std;
using namespace rlutil;

void VerFactura(){
    FacturaModel factura = SeleccionarFactura();
    if(factura.getId()==0) return;

    cls();
    const int anchosColumnas[] = {10,35,10,20,20};

    string encabezado= " FACTURA N°: " + to_string(factura.getId());
    cout << left << setw(33) << encabezado;
    cout << "FIBROFIX S.A - www.fibrofix.com.ar";
    cout << right << setw(33) << "FECHA: " + factura.getFecha().getStrFecha() << endl;
    cout << left;
    MostrarDatosCliente(factura.getCliente());
    cout << endl;

    TitulosColumnas(anchosColumnas);
    for(size_t i=0; i<20; i++)
    {
        if(i<factura.getCantidadItems())
            ImprimirItem(factura.getItem(i), anchosColumnas);
        else
            ImprimirItemVacio(anchosColumnas);
    }

    cout << endl << right << setw(90) <<"PRECIO TOTAL: $ "<< factura.getMontoTotal();
    anykey();

}

FacturaModel SeleccionarFactura()
{
    FacturaModel factura;
    cls();
    int id;
    cout << "POR FAVOR, INGRESE EL ID DE LA FACTURA  QUE DESEA ABRIR: ";
    EntradaNumerica(id);
    while(id<1)
    {
        cout << "EL ID INGRESADO NO ES VÁLIDO, INTENTE NUEVAMENTE O INGRESE -1 PARA SALIR" << endl;
        EntradaNumerica(id);
        if(id==-1) return factura;
    }

    while(!FacturaManager::cargar(id,factura))
    {
        cout << "NO SE PUDO ABRIR LA FACTURA SOLICITADA" << endl;
        cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl << endl;
        if(getkey()==KEY_ESCAPE) return factura;
    }

    return factura;
}

void ImprimirItem(ItemFacturaModel item, const int* anchos)
{
    cout << setw(anchos[0]) << item.getCodigoProducto() << '|';
    cout << setw(anchos[1]) << item.getDescripcionProducto() << '|';
    cout << setw(anchos[2]) << item.getCantidad() << '|';
    cout << setw(anchos[3]) << item.getPrecio() << '|';
    cout << setw(anchos[4]) << item.getCantidad()*item.getPrecio() << '|' << endl;
}

void MostrarDatosCliente(ClienteModel cliente)
{
    cout << left << endl;
    cout << " DATOS DEL COMPRADOR: "<< endl;

    cout << setw(80) << " Nombre y Apellido: " + cliente.getNombre() + " " + cliente.getApellido();
    cout << setw(20) << " DNI: " + to_string(cliente.getDNI()) << endl;
    cout << setw(80) << " Dirección: " + cliente.getDireccion();
    cout << setw(20) << " Teléfono: "  + cliente.getTelefono() << endl;
}
