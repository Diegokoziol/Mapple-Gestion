#include<iostream>
#include<vector>
#include"ClienteModel.h"
#include "FacturaModel.h"
#include"ItemFacturaModel.h"


using namespace std;

FacturaModel::FacturaModel(){
    _id=0;

}
void FacturaModel::setId(int id){
    _id=id;
}
void FacturaModel::setFecha(Fecha fecha){
    _fecha=fecha;
}
void FacturaModel::setCliente(ClienteModel cliente){
    _cliente=cliente;
}
int FacturaModel::getId(){
    return _id;
}
Fecha FacturaModel::getFecha(){
    return _fecha;
}
ClienteModel FacturaModel::getCliente(){
    return _cliente;
}
ItemFacturaModel FacturaModel::getItem(int pos){
    return _items[pos];
}
float FacturaModel::getMontoTotal(){
    float montoTotal=0;
    for(size_t i=0; i<_items.size(); i++)
    {
        montoTotal+=_items[i].getPrecio()*_items[i].getCantidad();
    }
    return montoTotal;
}
void FacturaModel::agregarItem(ItemFacturaModel itemFactura){
    _items.push_back(itemFactura);
}

size_t FacturaModel::getCantidadItems()
{
    return _items.size();
}
