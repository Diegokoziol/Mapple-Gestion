#include<iostream>
#include<string>
#include "Fecha.h"
#include "GastoModel.h"


using namespace std;

GastoModel::GastoModel(){
    _id = 0;
    _montoUnitario = 0;
    _descripcionGasto = descripcion;
    _unidades = 0;
    _fecha = Fecha();
}

int GastoModel::getId(){

    return _id;
}

float GastoModel::getMontoUnitario(){

    return _montoUnitario;

}
string GastoModel::getDescripcionGasto(){

    return _descripcionGasto;
}

int GastoModel::getUnidades(){

    return _unidades;
}

float GastoModel::getMontoTotal(){

    return _montoUnitario * _unidades;
}

Fecha GastoModel::getFecha(){

    return _fecha;
}

void GastoModel::setId(int id){

    _id = id;
}

void GastoModel::setDescripcionGasto(string descripcionGasto){

    _descripcionGasto = descripcionGasto;
}

void GastoModel::setMontoUnitario(float monto){

    _montoUnitario = monto;
}

void GastoModel::setUnidades(int unidades){

    _unidades = unidades;
}

void GastoModel::setFecha(Fecha fecha){

    _fecha = fecha;
}

