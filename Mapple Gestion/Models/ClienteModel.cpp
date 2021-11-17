#include<iostream>
#include <string>
#include "ClienteModel.h"

using namespace std;


ClienteModel::ClienteModel(){///--------
    _DNI = 0;

}

ClienteModel::ClienteModel(int DNI, string nombre, string apellido, string direccion, string telefono){
    _DNI = DNI;
    _nombre = nombre;
    _apellido = apellido;
    _direccion = direccion;
    _telefono = telefono;
}
int ClienteModel::getDNI(){
    return _DNI;
}
string ClienteModel::getNombre(){
    return _nombre;
}
string ClienteModel::getApellido(){
    return _apellido;
}
string ClienteModel::getDireccion(){
    return _direccion;
}
string ClienteModel::getTelefono(){
    return _telefono;
}

