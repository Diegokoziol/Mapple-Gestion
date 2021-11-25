#ifndef VERFACTURA_H_INCLUDED
#define VERFACTURA_H_INCLUDED

#include "../../../Models/FacturaModel.h"

void VerFactura();
FacturaModel SeleccionarFactura();

void MostrarDatosCliente(ClienteModel cliente);

void ImprimirItem(ItemFacturaModel item, const int* anchos);
void ImprimirItemVacio(const int* anchos);
void TitulosColumnas(const int* anchos);


#endif // VERFACTURA_H_INCLUDED
