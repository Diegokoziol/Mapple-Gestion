#ifndef PRODUCTOREPOSITORIO_H_INCLUDED
#define PRODUCTOREPOSITORIO_H_INCLUDED

#include "../DTOs/ProductoDto.h"

class ProductoRepositorio
{
public:
    static bool agregar(ProductoDto producto);
    static bool leer(int pos, ProductoDto &producto);
    static bool sobreescribir(int pos, ProductoDto producto);
};

#endif // PRODUCTOREPOSITORIO_H_INCLUDED
