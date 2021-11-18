#include<iostream>
#include "ItemPresupuestoRepositorio.h"

bool ItemPresupuestoRepositorio::agregar(ItemPresupuestoDto itemPresupuestoDto){
    FILE *file = fopen("ItemsPresupuestos.dat", "ab");
    if(file == NULL)  return false;

    bool wrote = fwrite(&itemPresupuestoDto, sizeof(ItemPresupuestoDto), 1, file);
    fclose(file);
    return wrote;
}

bool ItemPresupuestoRepositorio::leer(int pos, ItemPresupuestoDto &itemPresupuesto){
    FILE *file = fopen("ItemsPresupuestos.dat", "rb");
    if(file == NULL)  return false;

    fseek(file, pos * sizeof(ItemPresupuestoDto), SEEK_SET);
    bool read = fread(&itemPresupuesto, sizeof(ItemPresupuestoDto), 1, file);
    fclose(file);
    return read;
}
bool ItemPresupuestoRepositorio::sobreescribir(int pos, ItemPresupuestoDto itemPresupuesto){
    FILE *file = fopen("ItemsPresupuestos.dat", "rb+");
    if(file == NULL)  return false;

    fseek(file, pos * sizeof(ItemPresupuestoDto), SEEK_SET);
    bool wrote = fwrite(&itemPresupuesto, sizeof(ItemPresupuestoDto), 1, file);
    fclose(file);
    return wrote;
}

