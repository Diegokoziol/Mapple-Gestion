#ifndef FACTURAMANAGER_H_INCLUDED
#define FACTURAMANAGER_H_INCLUDED

#include "../Models/FacturaModel.h"
#include "../Models/PresupuestoModel.h"
#include "../Models/ClienteModel.h"

class FacturaManager{
    public:
        static int guardarNuevo(PresupuestoModel &presupuesto, ClienteModel cliente);
        static bool cargar(int id, FacturaModel &factura);
};

#endif // FACTURAMANAGER_H_INCLUDED
