#ifndef ITEMPRESUPUESTODTO_H_INCLUDED
#define ITEMPRESUPUESTODTO_H_INCLUDED

class ItemPresupuestoDto {
    public:
        int _id;
        int _idPresupuesto;
        int _codigoProducto;
        float _montoUnitario;
        int _cantidad;
        bool _estado;
};


#endif // ITEMPRESUPUESTODTO_H_INCLUDED
