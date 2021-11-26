#ifndef EDITARPRESUPUESTO_H_INCLUDED
#define EDITARPRESUPUESTO_H_INCLUDED

#include "../../../Models/PresupuestoModel.h"
#include "../../../Models/ItemPresupuestoModel.h"
#include "../../../Models/ClienteModel.h"

void EditarPresupuesto(PresupuestoModel &presupuesto, const char* encabezado);
void ImprimirItem(ItemPresupuestoModel item, const int* anchos);

int Modo1();
int Modo3(PresupuestoModel &presupuesto);
int Modo5(PresupuestoModel &presupuesto);
int Modo7(PresupuestoModel &presupuesto);
int Modo9(PresupuestoModel &presupuesto);
int Modo11(PresupuestoModel &presupuesto);

bool ObtenerCliente(ClienteModel &cliente);

#endif // EDITARPRESUPUESTO_H_INCLUDED
