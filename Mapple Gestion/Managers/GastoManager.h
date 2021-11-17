#ifndef GASTOMANAGER_H_INCLUDED
#define GASTOMANAGER_H_INCLUDED

#include "../Models/GastoModel.h"
//include "../DTOs/GastoDto.h"
#include<vector>

class GastoManager{
public:
    static bool guardarNuevo(GastoModel &gasto);
    static vector<GastoModel> leerTodos();
    static bool existe(int id);
};

#endif // GASTOMANAGER_H_INCLUDED
