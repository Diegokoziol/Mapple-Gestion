#ifndef ITEMFACTURAMODEL_H_INCLUDED
#define ITEMFACTURAMODEL_H_INCLUDED
#include <string>
using namespace std;
class ItemFacturaModel{
    private:
        int _id;
        int _codigoProducto;
        string _descripcionProducto;
        float _precioProducto;
        int _cantidad;
    public:
        ItemFacturaModel();
        int getId();
        int getCodigoProducto();
        int getCantidad();
        float getPrecio();
        string getDescripcionProducto();
        void setId(int id);
        void setCodigoProducto(int codigo);
        void setPrecio(float precio);
        void setCantidad(int cantidad);
        void setDescripcionProducto(string descripcion);
};

#endif // ITEMFACTURAMODEL_H_INCLUDED
