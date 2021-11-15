#include <string>
#include <cstring>
#include "ProductoManager.h"
#include "../Models/ProductoModel.h"
#include "../Repositorios/ProductoRepositorio.h"
#include "../DTOs/ProductoDto.h"
using namespace std;

bool ProductoManager::guardarNuevo(ProductoModel &producto)
{
    //Validar que no est� usado el c�digo del producto
    //Est� validaci�n es redundante en producto porque la capa de usuario ya la habr�a hecho a esta altura
    //Se hace ac� para no confiar una validaci�n tal en la capa usuario
    if(existe(producto.getCodigoProducto())) return false;

    ProductoDto dto;
    dto._codigoProducto = producto.getCodigoProducto();
    strcpy(dto._descripcionProducto, producto.getDescripcionProducto().c_str());
    dto._precioProducto = producto.getPrecioProducto();
    dto._stockDisponible = producto.getStockDisponible();

    return ProductoRepositorio::agregar(dto);
}

bool ProductoManager::cargar(int id, ProductoModel &producto)
{
    ProductoModel modelo;
    ProductoDto dto;

    int pos=0;
    while(ProductoRepositorio::leer(pos++, dto))
    {
        if(dto._codigoProducto==id)
        {
            //Producto encontrado, hay que llenar el modelo
            modelo.setCodigoProducto(dto._codigoProducto);

            string descripcion = dto._descripcionProducto;
            modelo.setDescripcionProducto(descripcion);

            modelo.setPrecioProducto(dto._precioProducto);

            modelo.agregarStock(dto._stockDisponible);

            producto=modelo;
            return true;
        }
    }

    //O nunca pudo abrir el archivo, o no se encontr� el c�digo buscado
    return false;
}


bool ProductoManager::existe(int id)
{
    ProductoDto dto;
    int pos=0;
    while(ProductoRepositorio::leer(pos++, dto))
    {
        if(dto._codigoProducto==id)
        {
            return true;
        }
    }
    return false;
}
