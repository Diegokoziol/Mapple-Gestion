#include<iostream>
#include"GastoRepositorio.h"

using namespace std;

bool GastoRepositorio::agregar(GastoDto gasto){
    FILE *file=fopen("Gastos.dat", "ab");
    if(file==NULL) return false;

    bool wrote = fwrite(&gasto, sizeof(GastoDto), 1, file);
    return wrote;
}

bool GastoRepositorio::leer(int pos, GastoDto &gasto){

    FILE *file=fopen("Gastos.dat", "rb");
    if(file==NULL) return false;

    fseek(file, sizeof(GastoDto)*pos, SEEK_SET);
    bool read = fread(&gasto, sizeof(GastoDto), 1, file);
    fclose(file);

    return read;
}
