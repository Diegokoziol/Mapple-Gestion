#ifndef CLIENTEMODEL_H_INCLUDED
#define CLIENTEMODEL_H_INCLUDED

#include <string>
using namespace std;

class ClienteModel
{
    private:
        int _DNI;
        string _nombre;
        string _apellido;
        string _direccion;
        string _telefono;
    public:
        ClienteModel();
        ClienteModel(int DNI, string nombre, string apellido, string direccion, string telefono);
        int getDNI();
        string getNombre();
        string getApellido();
        string getDireccion();
        string getTelefono();

};

#endif // CLIENTEMODEL_H_INCLUDED
