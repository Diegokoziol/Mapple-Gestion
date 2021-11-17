#ifndef GASTOREPOSITORIO_H_INCLUDED
#define GASTOREPOSITORIO_H_INCLUDED

#include "../DTOs/GastoDto.h"

class GastoRepositorio{
    public:
    static bool agregar(GastoDto gasto);
    static bool leer(int pos, GastoDto &gasto);
};

#endif // GASTOREPOSITORIO_H_INCLUDED
