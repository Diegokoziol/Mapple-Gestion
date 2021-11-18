#include<iostream>
#include "ProductoModel.h"
#include "ItemPresupuestoModel.h"

using namespace std;

ItemPresupuestoModel::ItemPresupuestoModel(){
    _id = 0;
    _cantidad = 0;
    _montoUnitario = 0;
}
ItemPresupuestoModel::ItemPresupuestoModel(ProductoModel producto, int cantidad){
    _id=0;
    _producto = producto;
    _cantidad = cantidad;
    _montoUnitario = producto.getPrecioProducto();
}
int ItemPresupuestoModel::getId(){
    return _id;
}
int ItemPresupuestoModel::getCantidad(){
    return _cantidad;
}
float ItemPresupuestoModel::getMontoUnitario(){
    return _montoUnitario;
}
float ItemPresupuestoModel::getMontoTotal(){
    return _cantidad * _montoUnitario;
}
ProductoModel ItemPresupuestoModel::getProducto(){
    return _producto;
}
void ItemPresupuestoModel::setId(const int id){
    _id = id;
}
void ItemPresupuestoModel::setCantidad(int cantidad){
    _cantidad = cantidad;
}
void ItemPresupuestoModel::setMontoUnitario(float montoUnitario){
    _montoUnitario = montoUnitario;
}
void ItemPresupuestoModel::setProducto(ProductoModel producto){
    _producto = producto;
}

void ItemPresupuestoModel::agregarCantidad(int cantidadAgregada){
    _cantidad += cantidadAgregada;
}
void ItemPresupuestoModel::actualizarMontoUnitario(){
    _montoUnitario = _producto.getPrecioProducto();
}
