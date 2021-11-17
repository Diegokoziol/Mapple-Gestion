#include<iostream>
#include<vector>
#include <cstring>
#include <string>
#include "../Managers/GastoManager.h"
#include "../Models/GastoModel.h"
#include "../DTOs/GastoDto.h"
#include "../Repositorios/GastoRepositorio.h"



using namespace std;

bool GastoManager::guardarNuevo(GastoModel &gasto){/// modificar
    vector<GastoModel> gastos = leerTodos();
    int mayorID = 0;
    for(int i = 0; i < gastos.size(); i++){
        if(gastos[i].getId()> mayorID){
            mayorID = gastos[i].getId();
        }
    }
    gasto.setId(mayorID + 1);
    gastos.push_back(gasto);
    FILE *file = fopen("Gastos.dat", "ab");
    if(file == NULL){
        return false;
    }
    for(int i = 0; i < gastos.size(); i++){
        fwrite(&gastos[i], sizeof(GastoModel), 1, file);
    }
    fclose(file);
    return true;
}
   /*

    GastoDto dto;
    dto._id = gasto.getId();
    strcpy(dto._descripcionGasto,gasto.getDescripcionGasto().c_str());
    dto._montoUnitario = gasto.getMontoUnitario();
    dto._fecha = gasto.getFecha();
    dto._unidades = gasto.getUnidades();

    return GastoRepositorio::agregar(dto);

}*/
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



