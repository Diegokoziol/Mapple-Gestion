#ifndef CLIENTEREPOSITORIO_H_INCLUDED
#define CLIENTEREPOSITORIO_H_INCLUDED

#include "../DTOs/ClienteDto.h"

class ClienteRepositorio{
    public:
        static bool agregar(ClienteDto cliente);
        static bool leer(int pos, ClienteDto &cliente);

};


#endif // CLIENTEREPOSITORIO_H_INCLUDED
