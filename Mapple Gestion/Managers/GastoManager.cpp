#include<iostream>
#include<vector>
#include <cstring>
#include <string>
#include "GastoManager.h"
#include "../Models/GastoModel.h"
#include "../DTOs/GastoDto.h"
#include "../Repositorios/GastoRepositorio.h"



using namespace std;

GastoManager::guardarNuevo(GastoModel &gasto){/// modificar

    if(existe(gasto.getId())) return false;

    GastoDto dto;
    dto._id = gasto.getId();
    strcpy(dto._descripcionGasto,gasto.getDescripcionGasto().c_str());
    dto._montoUnitario = gasto.getMontoUnitario();
    dto._fecha = gasto.getFecha();
    dto._unidades = gasto.getUnidades();

    return GastoRepositorio::agregar(dto);

}
GastoManager::leerTodos(){
vector<GastoDto> dto = GastoRepositorio::leer();
vector<GastoModel> gastos;
for (int i=0; i<dto.size(),i++){
    GastoModel gasto;
    gasto.setId(dto[i]._id);
    gasto.setDescripcionGasto(dto[i]._descripcionGasto);
    gasto.setMontoUnitario(dto[i]._montoUnitario);
    gasto.setUnidades(dto[i]._unidades);
    gastos.push_back(gasto);
}

}
