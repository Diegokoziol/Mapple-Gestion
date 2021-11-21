#include "BalanceRepositorio.h"
#include <iostream>
#include <cstring>

bool BalanceRepositorio::agregar(const char *caracteres, int tam){
    size_t tamTitulo = strchr(caracteres, '\n') - caracteres;

    char *nombreArchivo = new char[tamTitulo+5];
    if(nombreArchivo==nullptr) return false;
    strncpy (nombreArchivo,caracteres,tamTitulo);
    strcpy (nombreArchivo+tamTitulo, ".csv");

    FILE *file = fopen(nombreArchivo,"wb");
    if(file==NULL) return false;

    bool wrote =fwrite(caracteres, sizeof(char),tam, file);
    fclose(file);
    delete[] nombreArchivo;
    return wrote;
}





