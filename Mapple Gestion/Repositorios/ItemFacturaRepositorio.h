#ifndef ITEMFACTURAREPOSITORIO_H_INCLUDED
#define ITEMFACTURAREPOSITORIO_H_INCLUDED
#include "../DTOs/ItemFacturaDto.h"

class ItemFacturaRepositorio{
    public:
        static bool agregar(ItemFacturaDto itemFactura);
        static bool leer(int pos, ItemFacturaDto &itemFactura);

};

#endif // ITEMFACTURAREPOSITORIO_H_INCLUDED
