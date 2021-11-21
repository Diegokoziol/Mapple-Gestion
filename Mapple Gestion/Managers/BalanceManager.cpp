#include "BalanceManager.h"
#include <vector>
#include <string>

#include "../DTOs/ItemBalanceDto.h"
#include "../Repositorios/FacturaRepositorio.h"
#include "../Repositorios/ItemFacturaRepositorio.h"
#include "../Repositorios/GastoRepositorio.h"
#include "../Repositorios/BalanceRepositorio.h"

bool BalanceManager::guardarNuevo(int anio, int mes)
{
    vector<ItemBalanceDto> items;
    int pos=0;
    FacturaDto dtoFactura;
    while(FacturaRepositorio::leer(pos++, dtoFactura))
    {
        if(dtoFactura._fecha.getAnio()==anio && dtoFactura._fecha.getMes()==mes)
        {
            ItemBalanceDto dtoItemBalance;
            dtoItemBalance._id=dtoFactura._id;
            dtoItemBalance._fecha=dtoFactura._fecha;
            dtoItemBalance._descripcion="Productos vendidos:";
            dtoItemBalance._monto=0;
            dtoItemBalance._tipo=1;

            //INSERTAR POR ORDEN DE FECHA, LUEGO ID
            size_t i=0;
            if(!items.empty())
            {
                for(i=0; i<items.size(); i++)
                {
                    if(items[i]._fecha <= dtoItemBalance._fecha)
                    {
                        items.emplace(items.begin()+i, dtoItemBalance);
                        break;
                    }
                }
            }
            if(i==items.size())
                items.push_back(dtoItemBalance);
        }
    }

    pos=0;
    ItemFacturaDto dtoItemFactura;
    while(ItemFacturaRepositorio::leer(pos++, dtoItemFactura))
    {
        for(size_t i=0; i<items.size(); i++)
        {
            if(dtoItemFactura._idFactura==items[i]._id)
            {
                items[i]._descripcion += " " + to_string(dtoItemFactura._codigoProducto);
                items[i]._monto += dtoItemFactura._montoUnitario * dtoItemFactura._cantidad;
                break;
            }
        }
    }

    pos=0;
    GastoDto dtoGasto;
    while(GastoRepositorio::leer(pos++, dtoGasto))
    {
        if(dtoGasto._fecha.getAnio()==anio && dtoGasto._fecha.getMes()==mes)
        {
            ItemBalanceDto dtoItemBalance;
            dtoItemBalance._id = dtoGasto._id;
            dtoItemBalance._fecha = dtoGasto._fecha;
            dtoItemBalance._monto = dtoGasto._montoUnitario * dtoGasto._unidades;
            dtoItemBalance._tipo = 2;
            dtoItemBalance._descripcion = (string)"Gasto: " + dtoGasto._descripcionGasto;


            size_t i=0;
            if(!items.empty())
            {
                for(i=0; i<items.size(); i++)
                {
                    if(dtoItemBalance._fecha <= items[i]._fecha && dtoItemBalance._id < items[i]._id)
                    {
                        items.emplace(items.begin()+i, dtoItemBalance);
                        break;
                    }
                }
            }
            if(i==items.size())
                items.push_back(dtoItemBalance);
        }
    }


    const string finDeLinea="\n";
    const string separadorDeColumna = ";";
    string cadena = "Balance " + to_string(mes) + "-" + to_string(anio) + finDeLinea;
    cadena += "Id movimiento" + separadorDeColumna + "Fecha" + separadorDeColumna;
    cadena += "Debe" + separadorDeColumna + "Haber" + separadorDeColumna;
    cadena += "Descripción" + finDeLinea;
    for(size_t i=0; i<items.size(); i++)
    {
        cadena += to_string(items[i]._id) + separadorDeColumna;
        cadena += items[i]._fecha.getStrFecha() + separadorDeColumna;
        if(items[i]._tipo>1)
            cadena += separadorDeColumna + to_string(items[i]._monto) + separadorDeColumna;
        else
            cadena += to_string(items[i]._monto) + separadorDeColumna + separadorDeColumna;
        cadena += items[i]._descripcion + finDeLinea;
    }
    for(size_t i=0; i<cadena.size(); i++)
        if(cadena[i]=='.') cadena[i]=',';
    return BalanceRepositorio::agregar(cadena.c_str(), cadena.size());
}
