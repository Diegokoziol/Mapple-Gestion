#include <iostream>
#include "ProductoRepositorio.h"


bool ProductoRepositorio::agregar(ProductoDto producto)
{
    FILE *file = fopen("Productos.dat", "ab");
    if(file==NULL) return false;

    bool wrote = fwrite(&producto, sizeof(ProductoDto), 1, file);
    fclose(file);
    return wrote;
}

bool ProductoRepositorio::leer(int pos, ProductoDto &producto)
{
    FILE *file = fopen("Productos.dat", "rb");
    if(file==NULL) return false;

    fseek(file, sizeof(ProductoDto)*pos, SEEK_SET);
    bool read = fread(&producto, sizeof(ProductoDto), 1, file);

    fclose(file);
    return read;
}

bool ProductoRepositorio::sobreescribir(int pos, ProductoDto producto)
{
    FILE *file = fopen("Productos.dat", "rb+");
    if(file==NULL) return false;

    fseek(file, sizeof(ProductoDto)*pos, SEEK_SET);
    bool wrote = fwrite(&producto, sizeof(ProductoDto), 1, file);
    fclose(file);
    return wrote;
}
