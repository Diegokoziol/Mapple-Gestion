#ifndef PRODUCTOMANAGER_H_INCLUDED
#define PRODUCTOMANAGER_H_INCLUDED

#include "../Models/ProductoModel.h"
//#include "../DTOs/ProductoDto.h"

class ProductoManager
{
public:
    static bool guardarNuevo(ProductoModel &producto);
    static bool cargar(int id, ProductoModel &producto);
    static bool sobreescribir(ProductoModel &producto);
    static bool existe(int id);
};

#endif // PRODUCTOMANAGER_H_INCLUDED
