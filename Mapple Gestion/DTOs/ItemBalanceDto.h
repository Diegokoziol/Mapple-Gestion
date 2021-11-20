#ifndef ITEMBALANCEDTO_H_INCLUDED
#define ITEMBALANCEDTO_H_INCLUDED
#include <string>
#include "../Models/Fecha.h"

class ItemBalanceDto{
    public:
        int _id;
        Fecha _fecha;
        float _monto;
        int _tipo;
        string _descripcion;
};


#endif // ITEMBALANCEDTO_H_INCLUDED
