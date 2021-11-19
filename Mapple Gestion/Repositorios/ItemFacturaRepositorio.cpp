#include<iostream>
#include "ItemFacturaRepositorio.h"

bool ItemFacturaRepositorio::agregar(ItemFacturaDto itemFactura){
    FILE *file = fopen("ItemFacturas.dat", "ab");
    if(file==NULL) return false;

    bool wrote = fwrite(&itemFactura, sizeof(ItemFacturaDto), 1, file);
    fclose(file);
    return wrote;
}

bool ItemFacturaRepositorio::leer(int pos, ItemFacturaDto &itemFactura){
    FILE *file = fopen("ItemFacturas.dat", "rb");
    if(file==NULL) return false;

    fseek(file, pos * sizeof(ItemFacturaDto), SEEK_SET);
    bool read = fread(&itemFactura, sizeof(ItemFacturaDto), 1, file);

    fclose(file);
    return read;
}
