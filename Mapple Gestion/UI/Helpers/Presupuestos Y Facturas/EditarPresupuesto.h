#ifndef EDITARPRESUPUESTO_H_INCLUDED
#define EDITARPRESUPUESTO_H_INCLUDED

#include "../../../Models/PresupuestoModel.h"
#include "../../../Models/ItemPresupuestoModel.h"

void EditarPresupuesto(PresupuestoModel &presupuesto, const char* encabezado);
void TitulosColumnas(const int* anchos);
void ImprimirItem(ItemPresupuestoModel item, const int* anchos);
void ImprimirItemVacio(const int* anchos);

int Modo1();
int Modo3(PresupuestoModel &presupuesto);
int Modo5(PresupuestoModel &presupuesto);
int Modo7(PresupuestoModel &presupuesto);
int Modo9(PresupuestoModel &presupuesto);
int Modo11(PresupuestoModel &presupuesto);

#endif // EDITARPRESUPUESTO_H_INCLUDED
