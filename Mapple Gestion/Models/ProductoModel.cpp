#include "ProductoModel.h"
#include <string>
using namespace std;

ProductoModel::ProductoModel()
{
    _codigoProducto=0;
    _precioProducto=0;
    _stockDisponible=0;
}

int ProductoModel::getCodigoProducto()
{
    return _codigoProducto;
}

string ProductoModel::getDescripcionProducto()
{
    return _descripcionProducto;
}

float ProductoModel::getPrecioProducto()
{
    return _precioProducto;
}

int ProductoModel::getStockDisponible()
{
    return _stockDisponible;
}

void ProductoModel::setCodigoProducto(int codigo)
{
    _codigoProducto=codigo;
}

void ProductoModel::setDescripcionProducto(string descripcion)
{
    _descripcionProducto=descripcion;
}

void ProductoModel::setPrecioProducto(float precio)
{
    _precioProducto=precio;
}

void ProductoModel::agregarStock(int stockAgregado)
{
    _stockDisponible+=stockAgregado;
}

void ProductoModel::quitarStock(int stockQuitado)
{
    _stockDisponible-=stockQuitado;
}
