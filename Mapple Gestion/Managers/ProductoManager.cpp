#include <string>
#include <cstring>
#include "ProductoManager.h"
#include "../Models/ProductoModel.h"
#include "../Repositorios/ProductoRepositorio.h"
#include "../DTOs/ProductoDto.h"
using namespace std;

bool ProductoManager::guardarNuevo(ProductoModel &producto)
{
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

    //O nunca pudo abrir el archivo, o no se encontró el código buscado
    return false;
}
