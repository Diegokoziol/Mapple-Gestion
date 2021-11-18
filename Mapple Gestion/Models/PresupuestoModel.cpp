#include<iostream>
#include <vector>
#include "PresupuestoModel.h"
#include "Fecha.h"

PresupuestoModel::PresupuestoModel(){
    _id = 0;
    _fecha = Fecha();
    _plazo = 0;
    _items = vector<ItemPresupuestoModel>();
}
void PresupuestoModel::setId(int id){
    _id = id;
}
void PresupuestoModel::setFecha(Fecha fecha){
    _fecha = fecha;
}
void PresupuestoModel::setPlazo(int plazo){
    _plazo = plazo;
}
void PresupuestoModel::agregarItem(ItemPresupuestoModel itemPresupuesto){
    _items.push_back(itemPresupuesto);
}
void PresupuestoModel::quitarItem(int codItem){
    for(int i = 0; i < _items.size(); i++){
        if(_items[i].getProducto().getCodigoProducto() == codItem){
            _items.erase(_items.begin() + i);
        }
    }
}
int PresupuestoModel::getId(){
    return _id;
}
ItemPresupuestoModel PresupuestoModel::getItem(int pos){
    return _items[pos];
}
Fecha PresupuestoModel::getFecha(){
    return _fecha;
}
float PresupuestoModel::getMontoTotal(){
    float montoTotal = 0;
    for(int i = 0; i < _items.size(); i++){
        montoTotal += _items[i].getMontoTotal();
    }
    return montoTotal;
}
bool PresupuestoModel::recalcular(){
    for(int i = 0; i < _items.size(); i++){
        _items[i].actualizarMontoUnitario();
    }
    return true;
}
bool PresupuestoModel::vencido(){
   return true; ///REVISARR
}

int PresupuestoModel::getPlazo(){ //prueba p/ manager
    return _plazo;
}
