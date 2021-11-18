#ifndef PRESUPUESTOMODEL_H_INCLUDED
#define PRESUPUESTOMODEL_H_INCLUDED
#include "Fecha.h"
#include "ItemPresupuestoModel.h"
#include<vector>

class PresupuestoModel{
private:
    int _id;
    Fecha _fecha;
    int _plazo;
    vector<ItemPresupuestoModel> _items;
public:
    PresupuestoModel();
    void setId(int id);
    void setFecha(Fecha fecha);
    void setPlazo(int plazo);
    void agregarItem(ItemPresupuestoModel itemPresupuesto);
    void quitarItem(int codItem);
    int getId();
    ItemPresupuestoModel getItem(std::size_t pos);
    Fecha getFecha();
    float getMontoTotal();
    bool recalcular();
    bool vencido();
    int getPlazo();
    std::size_t getCantidadItems();
};

#endif // PRESUPUESTOMODEL_H_INCLUDED
