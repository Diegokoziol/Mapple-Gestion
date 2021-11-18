#include<iostream>
#include <vector>
#include "PresupuestoModel.h"
#include "Fecha.h"

PresupuestoModel::PresupuestoModel(){
    _id = 0;
    _plazo = 0;
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
    if(_items.size()>=20) return;

    int id=0;
    for(std::size_t i = 0; i < _items.size(); i++){
        if(_items[i].getId() > id){
            id=_items[i].getId();
        }
    }
    id++;
    itemPresupuesto.setId(id);
    _items.push_back(itemPresupuesto);
}
void PresupuestoModel::quitarItem(int codItem){
    for(std::size_t i = 0; i < _items.size(); i++){
        if(_items[i].getProducto().getCodigoProducto() == codItem){
            _items.erase(_items.begin() + i);
        }
    }
}
int PresupuestoModel::getId(){
    return _id;
}
ItemPresupuestoModel PresupuestoModel::getItem(std::size_t pos){
    if(pos>_items.size())
        return ItemPresupuestoModel();
    else
        return _items[pos];
}
Fecha PresupuestoModel::getFecha(){
    return _fecha;
}
float PresupuestoModel::getMontoTotal(){
    float montoTotal = 0;
    for(std::size_t i = 0; i < _items.size(); i++){
        montoTotal += _items[i].getMontoTotal();
    }
    return montoTotal;
}
bool PresupuestoModel::recalcular(){
    for(std::size_t i = 0; i < _items.size(); i++){
        _items[i].actualizarMontoUnitario();
    }
    return true;
}
bool PresupuestoModel::vencido(){
   return true; ///REVISARR
}

int PresupuestoModel::getPlazo(){
    return _plazo;
}

std::size_t PresupuestoModel::getCantidadItems()
{
    return _items.size();
}
