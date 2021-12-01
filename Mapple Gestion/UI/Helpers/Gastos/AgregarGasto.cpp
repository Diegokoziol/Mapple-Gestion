#include<iostream>
#include <string>
#include "AgregarGasto.h"
#include "../../../Managers/GastoManager.h"
#include "../../../Models/GastoModel.h"
#include "../../rlutil.h"
#include "../../EntradaNumerica.h"
#include "../../EntradaCadena.h"

using namespace std;
using namespace rlutil;


void AgregarGasto(){
    cls();
    GastoModel GastoNuevo;

    string descripcioGasto;
    float montoUnitario;
    int unidades;

    cout<<"INGRESE DESCRIPCIÓN DEL GASTO: ";
    descripcioGasto = EntradaCadena(29);
    GastoNuevo.setDescripcionGasto(descripcioGasto);

    cout<<"INGRESE PRECIO UNITARIO DEL GASTO: $";
     EntradaNumerica(montoUnitario);
    while(montoUnitario<=0)
    {

        cout << "MONTO INVÁLIDO, INGRESE OTRO O (-1) PARA CANCELAR " << endl;
        EntradaNumerica(montoUnitario);
        if(montoUnitario==-1) return;

    }
    GastoNuevo.setMontoUnitario(montoUnitario);



    cout<<"INGRESE CANTIDAD DE UNIDADES: ";
    EntradaNumerica(unidades);

     while(unidades<=0)
    {
        cout << "CANTIDAD INVÁLIDO , INGRESE OTRA O (-1) PARA CANCELAR " << endl;
        EntradaNumerica(unidades);
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
