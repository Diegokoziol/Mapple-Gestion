#ifndef PRODUCTOMODEL_H_INCLUDED
#define PRODUCTOMODEL_H_INCLUDED

#include <string>
using namespace std;

class ProductoModel
{
private:
    int _codigoProducto;
    string _descripcionProducto;
    float _precioProducto;
    int _stockDisponible;
public:
    ProductoModel();
    int getCodigoProducto();
    string getDescripcionProducto();
    float getPrecioProducto();
    int getStockDisponible();
    void setCodigoProducto(int codigo);
    void setDescripcionProducto(string descripcion);
    void setPrecioProducto(float precio);
    void agregarStock(int stockAgregado);
    void quitarStock(int stockQuitado);
};

#endif // PRODUCTOMODEL_H_INCLUDED
