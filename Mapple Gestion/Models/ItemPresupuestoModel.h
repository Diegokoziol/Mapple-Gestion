#ifndef ITEMPRESUPUESTOMODEL_H_INCLUDED
#define ITEMPRESUPUESTOMODEL_H_INCLUDED

#include "ProductoModel.h"

class ItemPresupuestoModel{
    private:
        int _id;
        int _cantidad;
        float _montoUnitario;
        ProductoModel _producto;
    public:
        ItemPresupuestoModel();
        ItemPresupuestoModel(ProductoModel producto, int cantidad);
        int getId();
        int getCantidad();
        float getMontoUnitario();
        float getMontoTotal();
        ProductoModel getProducto();
        void setId(const int id);
        void setCantidad(int cantidad);
        void setMontoUnitario(float montoUnitario);
        void setProducto(ProductoModel producto);
        void agregarCantidad(int cantidadAgregada);
        void actualizarMontoUnitario();

};

#endif // ITEMPRESUPUESTOMODEL_H_INCLUDED
