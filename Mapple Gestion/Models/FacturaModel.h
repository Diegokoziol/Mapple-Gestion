#ifndef FACTURAMODEL_H_INCLUDED
#define FACTURAMODEL_H_INCLUDED
#include<vector>
#include "Fecha.h"
#include "ClienteModel.h"
#include "ItemFacturaModel.h"

class FacturaModel{
    private:
        int _id;
        Fecha _fecha;
        ClienteModel _cliente;
        vector<ItemFacturaModel> _items;
    public:
        FacturaModel();
        void setId(int id);
        void setFecha(Fecha fecha);
        void setCliente(ClienteModel cliente);
        int getId();
        Fecha getFecha();
        ClienteModel getCliente();
        ItemFacturaModel getItem(int pos);
        float getMontoTotal();
        void agregarItem(ItemFacturaModel itemFactura);
        size_t getCantidadItems();
};

#endif // FACTURAMODEL_H_INCLUDED
