#include<iostream>
#include <cstring>
#include <string>
#include"ItemFacturaModel.h"
using namespace std;
ItemFacturaModel::ItemFacturaModel(){
    _id=0;
    _codigoProducto=0;
    _precioProducto=0;
    _cantidad=0;
}

int ItemFacturaModel::getId(){
    return _id;
}
int ItemFacturaModel::getCodigoProducto(){
    return _codigoProducto;
}
int ItemFacturaModel::getCantidad(){
    return _cantidad;
}
float ItemFacturaModel::getPrecio(){
    return _precioProducto;
}
string ItemFacturaModel::getDescripcionProducto(){
    return _descripcionProducto;
}
void ItemFacturaModel::setId(int id){
    _id=id;
}
void ItemFacturaModel::setCodigoProducto(int codigo){
    _codigoProducto=codigo;
}
void ItemFacturaModel::setPrecio(float precio){
    _precioProducto=precio;
}
void ItemFacturaModel::setCantidad(int cantidad){
    _cantidad=cantidad;
}
void ItemFacturaModel::setDescripcionProducto(string descripcion){
    _descripcionProducto=descripcion;
}
