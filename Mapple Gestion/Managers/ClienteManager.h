#ifndef CLIENTEMANAGER_H_INCLUDED
#define CLIENTEMANAGER_H_INCLUDED

//#include "../DTOs/ClienteDto.h"
#include "../Models/ClienteModel.h"

class ClienteManager{
    public:
        static bool guardarNuevo(ClienteModel &cliente);
        static bool cargar(int DNI, ClienteModel &cliente);
        static bool existe(int DNI);

};


#endif // CLIENTEMANAGER_H_INCLUDED
