#ifndef GASTOMODEL_H_INCLUDED
#define GASTOMODEL_H_INCLUDED
#include<iostream>
#include<string>
#include "Fecha.h"

class GastoModel{

    private:
        int _id;
        float _montoUnitario;
        string _descripcionGasto;
        int _unidades;
        Fecha _fecha;
    public:
        GastoModel();
        int getId();
        float getMontoUnitario();
        string getDescripcionGasto();
        int getUnidades();
        float getMontoTotal();
        Fecha getFecha();
        void setId(int id);
        void setDescripcionGasto(string descripcionGasto);
        void setMontoUnitario(float monto);
        void setUnidades(int unidades);
        void setFecha(Fecha fecha);

};



#endif // GASTOMODEL_H_INCLUDED
