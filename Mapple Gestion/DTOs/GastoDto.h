#ifndef GASTODTO_H_INCLUDED
#define GASTODTO_H_INCLUDED
#include "Fecha.h"

class GastoDto{
    public:
    int _id;
    float _montoUnitario;
    char _descripcionGasto[40];
    int _unidades;
    Fecha _fecha;
};


#endif // GASTODTO_H_INCLUDED
