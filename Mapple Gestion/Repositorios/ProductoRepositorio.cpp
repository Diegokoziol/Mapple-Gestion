#include <iostream>
#include "ProductoRepositorio.h"


bool ProductoRepositorio::leer(int pos, ProductoDto &producto)
{
    FILE *file = fopen("Productos.dat", "rb");
    if(file==NULL) return false;

    fseek(file, sizeof(ProductoDto)*pos, SEEK_SET);
    bool read = fread(&producto, sizeof(ProductoDto), 1, file);

    fclose(file);
    return read;
}
