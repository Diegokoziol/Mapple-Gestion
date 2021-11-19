#ifndef PRODUCTOMANAGER_H_INCLUDED
#define PRODUCTOMANAGER_H_INCLUDED

#include <vector>
#include "../Models/ProductoModel.h"

class ProductoManager
{
public:
    static bool guardarNuevo(ProductoModel &producto);
    static bool cargar(int id, ProductoModel &producto);
    static bool sobreescribir(ProductoModel &producto);
    static bool existe(int id);
    static vector<ProductoModel> leerTodos();
};

#endif // PRODUCTOMANAGER_H_INCLUDED
