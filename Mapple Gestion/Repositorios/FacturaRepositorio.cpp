#include<iostream>
#include"FacturaRepositorio.h"
#include "../DTOs/FacturaDto.h"

using namespace std;

bool FacturaRepositorio::agregar(FacturaDto factura){
    FILE *file = fopen("Facturas.dat", "ab");
    if(file==NULL) return false;

    bool wrote = fwrite(&factura, sizeof(FacturaDto), 1, file);
    fclose(file);
    return wrote;
}
bool FacturaRepositorio::leer(int pos, FacturaDto &factura){
    FILE *file = fopen("Facturas.dat", "rb");
    if(file==NULL) return false;

    fseek(file, pos * sizeof(FacturaDto), SEEK_SET);
    bool read = fread(&factura, sizeof(FacturaDto), 1, file);

    fclose(file);
    return read;
}
