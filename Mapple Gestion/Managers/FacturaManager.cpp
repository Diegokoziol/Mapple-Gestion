#include <iostream>
#include "FacturaManager.h"

#include "../Repositorios/FacturaRepositorio.h"
#include "../DTOs/FacturaDto.h"
#include "../Repositorios/ItemFacturaRepositorio.h"
#include "../DTOs/ItemFacturaDto.h"

#include "ProductoManager.h"
#include "ClienteManager.h"

using namespace std;

int FacturaManager::guardarNuevo(PresupuestoModel &presupuesto, ClienteModel cliente){
    vector<ProductoModel> inventarioActualizado;
    for(size_t i=0; i<presupuesto.getCantidadItems(); i++)
    {
        ItemPresupuestoModel item = presupuesto.getItem(i);
        ProductoModel producto = item.getProducto();
        if(producto.getStockDisponible() >= item.getCantidad())
        {
            producto.agregarStock(-1*item.getCantidad());
            inventarioActualizado.push_back(producto);
        }
        else
        {
            return false;
        }
    }
    for(size_t i=0; i<inventarioActualizado.size(); i++)
    {
        if(!ProductoManager::sobreescribir(inventarioActualizado[i]))
            return false;
    }

    FacturaDto dto;

    int mayorId=0;
    int pos=0;
    while(FacturaRepositorio::leer(pos++, dto)){
        if(dto._id>mayorId) mayorId=dto._id;
    }
    dto._id = mayorId + 1;
    dto._fecha = Fecha();
    dto._DNICliente = cliente.getDNI();

    if(!FacturaRepositorio::agregar(dto)) return false;
    for (size_t i=0; i<presupuesto.getCantidadItems(); i++)
    {
        ItemFacturaDto itemDto;
        ItemPresupuestoModel itemModel = presupuesto.getItem(i);
        itemDto._id = itemModel.getId();
        itemDto._codigoProducto = itemModel.getProducto().getCodigoProducto();
        itemDto._cantidad = itemModel.getCantidad();
        itemDto._montoUnitario = itemModel.getMontoUnitario();
        itemDto._idFactura = dto._id;

        if(!ItemFacturaRepositorio::agregar(itemDto)) return false;
    }
    return dto._id;
}

bool FacturaManager::cargar(int id, FacturaModel &factura){
    FacturaDto dto;
    FacturaModel modelo;
    int pos=0;
    while (FacturaRepositorio::leer(pos++, dto)){
        if(dto._id==id){
            modelo.setId(dto._id);
            modelo.setFecha(dto._fecha);

            ClienteModel cliente;
            if(!ClienteManager::cargar(dto._DNICliente, cliente)) return false;
            modelo.setCliente(cliente);
        }
    }
    if(modelo.getId()==0) return false;

    pos = 0;
    ItemFacturaDto itemDto;
    while(ItemFacturaRepositorio::leer(pos++, itemDto)){
        if(itemDto._idFactura==id){
            ItemFacturaModel itemModelo;
            itemModelo.setId(itemDto._id);
            itemModelo.setCodigoProducto(itemDto._codigoProducto);
            itemModelo.setPrecio(itemDto._montoUnitario);
            itemModelo.setCantidad(itemDto._cantidad);

            ProductoModel producto;
            if(ProductoManager::cargar(itemDto._codigoProducto, producto))
                itemModelo.setDescripcionProducto(producto.getDescripcionProducto());
            else
                return false;

            modelo.agregarItem(itemModelo);
        }
    }
    factura = modelo;
    return true;
}
