#include<iostream>
#include"ClienteRepositorio.h"

bool ClienteRepositorio::agregar(ClienteDto cliente)
{
    FILE *file = fopen("clientes.dat", "ab");
    if(file == NULL) return false;

    bool wrote = fwrite(&cliente, sizeof(ClienteDto), 1, file);
    fclose(file);
    return wrote;
}

bool ClienteRepositorio::leer(int pos, ClienteDto &cliente)
{
    FILE *file = fopen("clientes.dat", "rb");
    if(file == NULL) return false;

    fseek(file, pos * sizeof(ClienteDto), SEEK_SET);
    bool read = fread(&cliente, sizeof(ClienteDto), 1, file);

    fclose(file);
    return read;
}
