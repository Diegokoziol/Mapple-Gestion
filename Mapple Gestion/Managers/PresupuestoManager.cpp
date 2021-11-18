#include<iostream>
#include <vector>
#include"PresupuestoManager.h"
#include "../Models/PresupuestoModel.h"
#include "../Repositorios/PresupuestoRepositorio.h"
#include "../DTOs/PresupuestoDto.h"

bool guardarNuevo(PresupuestoModel &presupuesto){
    PresupuestoDto dto;
    dto._id = presupuesto.getId();
    dto._fecha = presupuesto.getFecha();
    dto._plazo = presupuesto.getPlazo();   ////----- Tendria q ser getPlazo?

    return PresupuestoRepositorio::agregar(dto);
}


bool PresupuestoManager::cargar(int id, PresupuestoModel &presupuesto){
    PresupuestoDto dto;
    PresupuestoModel modelo;
    int pos = 0;
    while (PresupuestoRepositorio::leer(pos++, dto)){
        if(dto._id == id){
            modelo.setId(dto._id);
            modelo.setFecha(dto._fecha);
            modelo.setPlazo (dto._plazo);

            presupuesto=modelo;
            return true;


        }
    }
    return false;
}
bool PresupuestoManager::sobreescribir(PresupuestoModel &presupuesto){
    PresupuestoDto dto;

    int pos=0;
    while (PresupuestoRepositorio::leer(pos, dto)){
        if(dto._id == presupuesto.getId()){
            dto._fecha = presupuesto.getFecha();
            dto._plazo = presupuesto.getPlazo();
            dto._id = presupuesto.getId();
            return PresupuestoRepositorio::sobreescribir(pos, dto);

        }
        pos++;
    }
    return false;
}
