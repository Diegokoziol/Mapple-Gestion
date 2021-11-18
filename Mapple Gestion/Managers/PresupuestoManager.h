#ifndef PRESUPUESTOMANAGER_H_INCLUDED
#define PRESUPUESTOMANAGER_H_INCLUDED
#include "../Models/PresupuestoModel.h"

class PresupuestoManager{
    public:
        static bool guardarNuevo(PresupuestoModel &presupuesto);
        static bool cargar(int id, PresupuestoModel &presupuesto);
        static bool sobreescribir(PresupuestoModel &presupuesto);
};


#endif // PRESUPUESTOMANAGER_H_INCLUDED
