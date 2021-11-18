#include<iostream>
#include <vector>
#include "../DTOs/PresupuestoDto.h"
#include "PresupuestoRepositorio.h"

bool agregar(PresupuestoDto presupuestoDto){
    FILE *file = fopen("presupuesto.dat", "ab");
    if(file == NULL)  return false;

    bool wrote = fwrite(&presupuestoDto, sizeof(PresupuestoDto), 1, file);
    fclose(file);
    return wrote;
}
bool leer(int pos, PresupuestoDto &presupuesto){
    FILE *file = fopen("presupuesto.dat", "rb");
    if(file == NULL)  return false;

    fseek(file, pos * sizeof(PresupuestoDto), SEEK_SET);
    bool read = fread(&presupuesto, sizeof(PresupuestoDto), 1, file);
    fclose(file);
    return read;
}
bool sobreescribir(int pos, PresupuestoDto presupuesto){
    FILE *file = fopen("presupuesto.dat", "rb+");
    if(file == NULL)  return false;

    fseek(file, pos * sizeof(PresupuestoDto), SEEK_SET);
    bool wrote = fwrite(&presupuesto, sizeof(PresupuestoDto), 1, file);
    fclose(file);
    return wrote;
}


