#include<iostream>
#include "../../../Models/FacturaModel.h"
#include "../../../Managers/FacturaManager.h"
#include "../../rlutil.h"
#include "VerFactura.h"
using namespace std;
using namespace rlutil;

void VerFactura(){

    cls();
    int id;
    cout << "POR FAVOR, INGRESE EL ID DE LA FACTURA  QUE DESEA ABRIR: ";
    cin >> id;
    while(cin.fail() || id<1)
    {
        cin.clear();
        cin.ignore();
        cout << "EL ID INGRESADO NO ES VÁLIDO, INTENTE NUEVAMENTE O INGRESE -1 PARA SALIR" << endl;
        cin >> id;
        if(id==-1) return;
    }
    FacturaModel factura;
    while(!FacturaManager::cargar(id,factura))
    {
        cout << "NO SE PUDO ABRIR LA FACTURA SOLICITADA" << endl;
        cout << "PRESIONE ESCAPE PARA SALIR U OTRA TECLA PARA REINTENTAR" << endl << endl;
        if(getkey()==KEY_ESCAPE) return;
    }
    string encabezado= "FACTURA " + to_string(factura.getId());

}













