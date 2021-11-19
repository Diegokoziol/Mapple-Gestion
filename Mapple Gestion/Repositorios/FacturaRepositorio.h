#ifndef FACTURAREPOSITORIO_H_INCLUDED
#define FACTURAREPOSITORIO_H_INCLUDED
#include "../DTOs/FacturaDto.h"

class FacturaRepositorio{
    public:
        static bool agregar(FacturaDto factura);
        static bool leer(int pos, FacturaDto &factura);

};


#endif // FACTURAREPOSITORIO_H_INCLUDED
