#include <string>
#include <cstring>
#include <vector>
#include "ProductoManager.h"
#include "../Models/ProductoModel.h"
#include "../Repositorios/ProductoRepositorio.h"
#include "../DTOs/ProductoDto.h"

bool ProductoManager::guardarNuevo(ProductoModel &producto)
{
    if(existe(producto.getCodigoProducto())) return false;
    if(producto.getCodigoProducto()<1) return false;
    if(producto.getDescripcionProducto().length()<1) return false;
    if(producto.getPrecioProducto()<0) return false;
    if(producto.getStockDisponible()<0) return false;

    ProductoDto dto;
    dto._codigoProducto = producto.getCodigoProducto();
    strcpy(dto._descripcionProducto, producto.getDescripcionProducto().substr(0,29).c_str());
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
            modelo.setDescripcionProducto(dto._descripcionProducto);
            modelo.setPrecioProducto(dto._precioProducto);
            modelo.agregarStock(dto._stockDisponible);

            producto=modelo;
            return true;
        }
    }

    //O nunca pudo abrir el archivo, o no se encontr� el c�digo buscado
    return false;
}

bool ProductoManager::sobreescribir(ProductoModel &producto)
{
    if(producto.getCodigoProducto()<1) return false;
    if(producto.getDescripcionProducto().length()<1) return false;
    if(producto.getPrecioProducto()<0) return false;
    if(producto.getStockDisponible()<0) return false;

    ProductoDto dto;

    int pos=0;
    while(ProductoRepositorio::leer(pos, dto))
    {
        if(dto._codigoProducto==producto.getCodigoProducto())
        {
            dto._codigoProducto = producto.getCodigoProducto();
            strcpy(dto._descripcionProducto, producto.getDescripcionProducto().c_str());
            dto._precioProducto = producto.getPrecioProducto();
            dto._stockDisponible = producto.getStockDisponible();

            return ProductoRepositorio::sobreescribir(pos, dto);
        }
        pos++;
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

vector<ProductoModel> ProductoManager::leerTodos()
{
    vector<ProductoModel> productos;
    ProductoDto dto;
    int pos=0;
    while(ProductoRepositorio::leer(pos++, dto))
    {
        ProductoModel modelo;
        modelo.setCodigoProducto(dto._codigoProducto);
        modelo.setDescripcionProducto(dto._descripcionProducto);
        modelo.setPrecioProducto(dto._precioProducto);
        modelo.agregarStock(dto._stockDisponible);
        productos.push_back(modelo);
    }

    return productos;
}
