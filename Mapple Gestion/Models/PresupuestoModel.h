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
    //PresupuestoModel(Fecha fecha, int plazo);
    void setId(int id);
    void setFecha(Fecha fecha);
    void setPlazo(int plazo);
    void agregarItem(ItemPresupuestoModel itemPresupuesto);
    void quitarItem(int codItem);
    int getId();
    ItemPresupuestoModel getItem(int pos);
    Fecha getFecha();
    float getMontoTotal();
    bool recalcular();
    bool vencido();
    int getPlazo(); // no se si esta bien agregado
};

#endif // PRESUPUESTOMODEL_H_INCLUDED
