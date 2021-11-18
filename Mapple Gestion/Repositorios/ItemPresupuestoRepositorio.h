#ifndef ITEMPRESUPUESTOREPOSITORIO_H_INCLUDED
#define ITEMPRESUPUESTOREPOSITORIO_H_INCLUDED

#include "../DTOs/ItemPresupuestoDto.h"

class ItemPresupuestoRepositorio{
    public:
        static bool agregar(ItemPresupuestoDto itemPresupuestoDto);
        static bool leer(int pos, ItemPresupuestoDto &itemPresupuesto);
        static bool sobreescribir(int pos, ItemPresupuestoDto itemPresupuesto);
};


#endif // ITEMPRESUPUESTOREPOSITORIO_H_INCLUDED
