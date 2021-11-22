#include <iostream>
#include <vector>
#include "PresupuestoManager.h"

#include "../Models/PresupuestoModel.h"
#include "../Repositorios/PresupuestoRepositorio.h"
#include "../DTOs/PresupuestoDto.h"

#include "../Models/ItemPresupuestoModel.h"
#include "../Repositorios/ItemPresupuestoRepositorio.h"
#include "../DTOs/ItemPresupuestoDto.h"

#include "../Models/ProductoModel.h"
#include "ProductoManager.h"

bool PresupuestoManager::guardarNuevo(PresupuestoModel &presupuesto){
    PresupuestoDto dto;

    int mayorID = 0, pos=0;
    while(PresupuestoRepositorio::leer(pos++, dto))
    {
        if(dto._id>mayorID)
            mayorID=dto._id;
    }
    presupuesto.setId(mayorID+1);

    dto._id = presupuesto.getId();
    dto._fecha = presupuesto.getFecha();
    dto._plazo = presupuesto.getPlazo();

    if(!PresupuestoRepositorio::agregar(dto)) return false;

    for(size_t i=0; i<presupuesto.getCantidadItems(); i++)
    {
        ItemPresupuestoDto itemDto;
        ItemPresupuestoModel itemModel = presupuesto.getItem(i);
        itemDto._id = itemModel.getId();
        itemDto._idPresupuesto = presupuesto.getId();
        itemDto._cantidad = itemModel.getCantidad();
        itemDto._montoUnitario = itemModel.getMontoUnitario();
        itemDto._codigoProducto = itemModel.getProducto().getCodigoProducto();
        itemDto._estado = true;
        if(!ItemPresupuestoRepositorio::agregar(itemDto)) return false;
    }
    return true;
}

bool PresupuestoManager::cargar(int id, PresupuestoModel &presupuesto){
    PresupuestoDto dto;
    PresupuestoModel modelo;
    int pos = 0;
    while (PresupuestoRepositorio::leer(pos++, dto)){
        if(dto._id == id){
            modelo.setId(dto._id);
            modelo.setFecha(dto._fecha);
            modelo.setPlazo(dto._plazo);
        }
    }
    if(modelo.getId()==0) return false;

    pos=0;
    ItemPresupuestoDto itemDto;
    while(ItemPresupuestoRepositorio::leer(pos++, itemDto))
    {
        if(itemDto._idPresupuesto==id && itemDto._estado==true)
        {
            ItemPresupuestoModel itemModelo;
            itemModelo.setId(itemDto._id);
            itemModelo.setCantidad(itemDto._cantidad);
            itemModelo.setMontoUnitario(itemDto._montoUnitario);

            ProductoModel producto;
            if(ProductoManager::cargar(itemDto._codigoProducto, producto))
                itemModelo.setProducto(producto);
            else
                return false;

            modelo.agregarItem(itemModelo);
        }
    }

    presupuesto=modelo;
    return true;
}

bool PresupuestoManager::sobreescribir(PresupuestoModel &presupuesto){
    PresupuestoDto dto;

    int pos=0;
    while (PresupuestoRepositorio::leer(pos, dto)){
        if(dto._id == presupuesto.getId()){
            dto._fecha = presupuesto.getFecha();
            dto._plazo = presupuesto.getPlazo();
            dto._id = presupuesto.getId();
            if(!PresupuestoRepositorio::sobreescribir(pos, dto)) return false;
        }
        pos++;
    }

    pos=0;
    bool *itemsGuardados= new bool[presupuesto.getCantidadItems()] {};
    if(itemsGuardados==nullptr) return false;
    ItemPresupuestoDto itemDto;
    while(ItemPresupuestoRepositorio::leer(pos,itemDto))
    {
        if(itemDto._idPresupuesto==presupuesto.getId())
        {
            for(size_t i=0; i<presupuesto.getCantidadItems(); i++)
            {
                if(itemDto._id==presupuesto.getItem(i).getId())
                {
                    //SOBREESCRIBIR
                    ItemPresupuestoModel itemModel = presupuesto.getItem(i);
                    itemDto._id = itemModel.getId();
                    itemDto._idPresupuesto = presupuesto.getId();
                    itemDto._cantidad = itemModel.getCantidad();
                    itemDto._montoUnitario = itemModel.getMontoUnitario();
                    itemDto._codigoProducto = itemModel.getProducto().getCodigoProducto();
                    itemDto._estado = true;
                    if(!ItemPresupuestoRepositorio::sobreescribir(pos, itemDto)){
                        delete itemsGuardados;
                        return false;
                    }
                    itemsGuardados[i]=true;
                    break;
                }
                if(itemsGuardados[i]==false)
                {
                    //BAJA LÓGICA
                    itemDto._estado=false;
                    if(!ItemPresupuestoRepositorio::sobreescribir(pos, itemDto))
                    {
                        delete itemsGuardados;
                        return false;
                    }
                }
            }
        }
        pos++;
    }

    for(size_t i=0; i<presupuesto.getCantidadItems(); i++)
    {
        if(itemsGuardados[i]==false)
        {
            ItemPresupuestoModel itemModel = presupuesto.getItem(i);
            itemDto._id = itemModel.getId();
            itemDto._idPresupuesto = presupuesto.getId();
            itemDto._cantidad = itemModel.getCantidad();
            itemDto._montoUnitario = itemModel.getMontoUnitario();
            itemDto._codigoProducto = itemModel.getProducto().getCodigoProducto();
            itemDto._estado = true;
            if(!ItemPresupuestoRepositorio::agregar(itemDto))
            {
                delete itemsGuardados;
                return false;
            }
        }
    }

    delete itemsGuardados;
    return true;
}
