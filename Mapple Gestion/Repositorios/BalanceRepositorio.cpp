#include<iostream>
#include"BalanceRepositorio.h"
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;


bool BalanceRepositorio::agregar(char *caracteres, int tam){
    char c='\n';
    size_t tamTitulo = strspn(caracteres, &c);

    char *nombreArchivo = new char[tamTitulo+5];
    if(nombreArchivo==nullptr) return false;
    strncpy (nombreArchivo,caracteres,tamTitulo);
    strcpy (nombreArchivo+tamTitulo, ".csv");

    FILE *file = fopen(nombreArchivo,"ab");
    if(file==NULL) return false;

    bool wrote =fwrite(caracteres, sizeof(char),tam, file);
    fclose(file);
    delete[] nombreArchivo;
    return wrote;
}





