#ifndef FACTURAMANAGER_H_INCLUDED
#define FACTURAMANAGER_H_INCLUDED
#include "../Models/PresupuestoModel.h"
#include "../Models/FacturaModel.h"




class FacturaManager{
    public:
        static bool guardarNuevo(PresupuestoModel &presupuesto);
        static bool cargar(int id, FacturaModel &factura);
};

#endif // FACTURAMANAGER_H_INCLUDED
