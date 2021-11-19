#include<iostream>
#include "../Models/PresupuestoModel.h"
#include "../Models/FacturaModel.h"
#include "../DTOs/FacturaDto.h"
#include "FacturaManager.h"
#include "../Repositorios/ItemFacturaRepositorio.h"

#include "../Repositorios/FacturaRepositorio.h"
#include "../DTOs/ItemFacturaDto.h"
#include "../Models/ItemFacturaModel.h"
#include "ProductoManager.h"

using namespace std;

bool FacturaManager::guardarNuevo(PresupuestoModel &presupuesto){
    FacturaDto dto;
    int mayorId=0;
    int pos=0;
    while(FacturaRepositorio::leer(pos++, dto)){
        if(dto._id>mayorId) mayorId=dto._id;
    }
    presupuesto.setId(mayorId+1);
    dto._id = presupuesto.getId();
    dto._fecha = presupuesto.getFecha();
    /// dto._DNICliente =

    if(!FacturaRepositorio::agregar(dto)) return false;
    for (size_t i=0; i<presupuesto.getCantidadItems(); i++)
    {
        ItemFacturaDto itemDto;
        ItemPresupuestoModel itemModel = presupuesto.getItem(i);///-----
        itemDto._id = itemModel.getId();
        itemDto._codigoProducto = itemModel.getProducto().getCodigoProducto(); ///-----
        itemDto._cantidad = itemModel.getCantidad();

        if(!ItemFacturaRepositorio::agregar(itemDto)) return false;

    }
    return true;
}

bool FacturaManager::cargar(int id, FacturaModel &factura){
    FacturaDto dto;
    FacturaModel modelo;
    int pos=0;
    while (FacturaRepositorio::leer(pos++, dto)){
        if(dto._id==id){
            modelo.setId(dto._id);
            modelo.setFecha(dto._fecha);
            //modelo.setCliente(dto._DNICliente);

        }
    }
    if(modelo.getId()==0) return false;

    pos = 0;
    ItemFacturaDto itemDto;
    while(ItemFacturaRepositorio::leer(pos++, itemDto)){
        if(itemDto._id==id){
            ItemFacturaModel itemModelo;
            itemModelo.setId(itemDto._id);
            itemModelo.setCodigoProducto(itemDto._codigoProducto);
            itemModelo.setPrecio(itemDto._montoUnitario);

            itemModelo.setCantidad(itemDto._cantidad);


            ProductoModel producto;
            if(ProductoManager::cargar(itemDto._codigoProducto, producto))
                itemModelo.setDescripcionProducto(producto.getDescripcionProducto());///----
            else
                return false;

            factura.agregarItem(itemModelo);
        }
    }
    factura = modelo;
    return true;
}
