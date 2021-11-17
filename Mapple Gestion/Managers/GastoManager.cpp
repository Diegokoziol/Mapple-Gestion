#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "../Managers/GastoManager.h"
#include "../Models/GastoModel.h"
#include "../DTOs/GastoDto.h"
#include "../Repositorios/GastoRepositorio.h"
using namespace std;

bool GastoManager::guardarNuevo(GastoModel &gasto){
    GastoDto dto;

    int mayorID = 0, pos=0;
    while(GastoRepositorio::leer(pos++, dto))
    {
        if(dto._id>mayorID)
            mayorID=dto._id;
    }
    gasto.setId(mayorID+1);

    dto._id = gasto.getId();
    dto._fecha = gasto.getFecha();
    dto._montoUnitario = gasto.getMontoUnitario();
    dto._unidades = gasto.getUnidades();
    strcpy(dto._descripcionGasto, gasto.getDescripcionGasto().substr(0,39).c_str());

    return GastoRepositorio::agregar(dto);
}

vector <GastoModel> GastoManager::leerTodos(){
    GastoDto dto;
    vector <GastoModel> gastos;
    int pos=0;
    while(GastoRepositorio::leer(pos++,dto)){
        GastoModel gasto;
        gasto.setId(dto._id);
        gasto.setDescripcionGasto(dto._descripcionGasto);
        gasto.setMontoUnitario(dto._montoUnitario);
        gasto.setFecha(dto._fecha);
        gasto.setUnidades(dto._unidades);
        gastos.push_back(gasto);
    }
    return gastos;
}



