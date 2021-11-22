#include<iostream>
#include "MostrarGastos.h"
#include "../../rlutil.h"
#include "../../../Managers/GastoManager.h"
#include "../../../Models/GastoModel.h"
#include <string>
#include <iomanip>
#include <vector>

using namespace rlutil;
using namespace std;

void MostrarGastos(){
    cls();
    cout << left;
    cout<<endl;
    cout <<"                            GASTOS   REALIZADOS                               "<<endl;
    cout<<"_______________________________________________________________________________"<<endl;
    cout << setw(5) << "ID";
    cout << setw(10) << "FECHA";
    cout << setw(31) << "DESCRIPCIÓN";
    cout << setw(10) << "PRECIO";
    cout << setw(10) << "UNIDADES" ;
    cout << setw(20) << "PRECIO TOTAL" <<endl;
    cout<<"_______________________________________________________________________________"<<endl;
    cout<<endl;

    ImprimirGastos();
    anykey();

}

void ImprimirGastos()
{
    vector<GastoModel> gastos = GastoManager::leerTodos();
    for (size_t i=0;i<gastos.size(); i++)
        ImprimirGasto(gastos[i]);


}
void ImprimirGasto(GastoModel &gasto)
{

     cout << left;
     cout << setw(5)  << gasto.getId();
     cout << setw(10) << gasto.getFecha().getStrFecha();
     cout << setw(31) << gasto.getDescripcionGasto();
     cout << "$"<< fixed << setprecision(2) << setw(10) << gasto.getMontoUnitario();
     cout << setw(10) << gasto.getUnidades();
     cout << "$"<< fixed << setprecision(2) << setw(20) << gasto.getMontoTotal()<<endl;
     cout << "-------------------------------------------------------------------------------" << endl;
}
