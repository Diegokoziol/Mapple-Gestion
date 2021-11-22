#include<iostream>
#include <string>
#include "AgregarGasto.h"
#include "../../../Managers/GastoManager.h"
#include "../../../Models/GastoModel.h"
#include "../../rlutil.h"
#include "../../EntradaNumerica.h"

using namespace std;
using namespace rlutil;


void AgregarGasto(){
    cls();
    GastoModel GastoNuevo;

    string descripcioGasto;
    float montoUnitario;
    int unidades;

    cout<<"INGRESE DESCRIPCIÓN DEL GASTO: ";
    cin.ignore();
    getline(cin, descripcioGasto);
    while(descripcioGasto.length()>29)
    {
        cout << "POR FAVOR, INGRESE UNA DESCRIPCIÓN MÁS BREVE: ";
        getline(cin, descripcioGasto);
    }
    GastoNuevo.setDescripcionGasto(descripcioGasto);

    cout<<"INGRESE PRECIO UNITARIO DEL GASTO: $";
    cin >> montoUnitario;
    while(montoUnitario<=0 || cin.fail())
    {
        EntradaNumerica(montoUnitario);
        cout << "MONTO INVÁLIDO , INGRESE OTRO O (-1) PARA CANCELAR " << endl;
        if(montoUnitario==-1) return;
    }
    GastoNuevo.setMontoUnitario(montoUnitario);



    cout<<"INGRESE CANTIDAD DE UNIDADES: ";
    cin>>unidades;

     while(unidades<=0 || cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "CANTIDAD INVÁLIDO , INGRESE OTRA O (-1) PARA CANCELAR " << endl;
        if(unidades==-1) return;
    }
    GastoNuevo.setUnidades(unidades);

    while (!GastoManager::guardarNuevo(GastoNuevo))
    {
        cout << "HUBO UN PROBLEMA AL GUARDAR" << endl;
        cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl << endl;
        if(getkey()==KEY_ESCAPE) return;
    }
    cout << endl;
    cout << "------------------------------------------------------------------"<<endl;
    cout << "               GASTO AGREGADO";
    anykey();

}
