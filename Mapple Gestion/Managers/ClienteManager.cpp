#include<iostream>
#include <string>
#include <cstring>
#include "ClienteManager.h"
#include "../Models/ClienteModel.h"
#include "../Repositorios/ClienteRepositorio.h"
#include "../DTOs/ClienteDto.h"

bool ClienteManager::existe(int DNI){
    ClienteDto cliente;
    int pos = 0;
    while(ClienteRepositorio::leer(pos++, cliente)){
        if(cliente._DNI == DNI) {
            return true;
        }
    }
    return false;
}


bool ClienteManager::cargar(int DNI, ClienteModel &cliente){
    ClienteDto dto;
    int pos = 0;
    while(ClienteRepositorio::leer(pos++, dto)){
        if(dto._DNI == DNI){
            cliente = ClienteModel(dto._DNI, dto._nombre, dto._apellido, dto._direccion, dto._telefono);
            return true;
        }
    }
    return false;
}


bool ClienteManager::guardarNuevo(ClienteModel &cliente){
    if(existe(cliente.getDNI())) return false;

    ClienteDto dto;
    dto._DNI = cliente.getDNI();
    strcpy(dto._nombre, cliente.getNombre().substr(0,29).c_str());
    strcpy(dto._apellido, cliente.getApellido().substr(0,29).c_str());
    strcpy(dto._direccion, cliente.getDireccion().substr(0,49).c_str());
    strcpy(dto._telefono, cliente.getTelefono().substr(0,14).c_str());

    return ClienteRepositorio::agregar(dto);
}
