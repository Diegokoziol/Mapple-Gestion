#include<iostream>
#include "ProductoModel.h"
#include "ItemPresupuestoModel.h"

using namespace std;

ItemPresupuetoModel::ItemPresupuetoModel(){
    _id = 0;
    _cantidad = 0;
    _montoUnitario = 0;
    _producto = ProductoModel();

}
ItemPresupuetoModel::ItemPresupuetoModel(ProductoModel producto, int cantidad){
    _producto = producto;//----
    _cantidad = cantidad;
}
int ItemPresupuetoModel::getId(){
    return _id;
}
int ItemPresupuetoModel::getCantidad(){
    return _cantidad;
}
float ItemPresupuetoModel::getMontoUnitario(){
    return _montoUnitario;
}
float ItemPresupuetoModel::getMontoTotal(){
    return _cantidad * _montoUnitario;
}
ProductoModel ItemPresupuetoModel::getProducto(){
    return _producto;
}
void ItemPresupuetoModel::setId(const int id){
    _id = id;
}
void ItemPresupuetoModel::setCantidad(int cantidad){
    _cantidad = cantidad;
}
void ItemPresupuetoModel::setMontoUnitario(float montoUnitario){
    _montoUnitario = montoUnitario;
}
void ItemPresupuetoModel::setProducto(ProductoModel producto){
    _producto = producto;
}

void ItemPresupuetoModel::agregarCantidad(int cantidadAgregada){
    _cantidad += cantidadAgregada;
}
void ItemPresupuetoModel::actualizarMontoUnitario(){
    _montoUnitario = _producto.getPrecioProducto();
}
