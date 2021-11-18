#ifndef PRESUPUESTOREPOSITORIO_H_INCLUDED
#define PRESUPUESTOREPOSITORIO_H_INCLUDED

#include "../DTOs/PresupuestoDto.h"

class PresupuestoRepositorio{
    public:
        static bool agregar(PresupuestoDto presupuestoDto);
        static bool leer(int pos, PresupuestoDto &presupuesto);
        static bool sobreescribir(int pos, PresupuestoDto presupuesto);
};


#endif // PRESUPUESTOREPOSITORIO_H_INCLUDED
